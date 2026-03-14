# she_gtestx

`she_gtestx` 是一个基于 C++17 的轻量级 GoogleTest 扩展层。

它的目标很简单：

- 不修改 GoogleTest 本身
- 在 GoogleTest 现有两层模型之上，补一层“逻辑多层级测试命名”
- 继续复用 GoogleTest 原生的断言、执行、过滤和报告能力

当前实现采用“名字压平”的方式工作，也就是把额外层级编码进
GoogleTest 已有的 `TestSuite.TestName` 结构里。

## 当前能力

当前对外公开的接口只有两个：

- `SHE_GTESTX_TEST(...)`
- `SHE_GTESTX_TEST_F(fixture, ...)`

其中：

- `SHE_GTESTX_TEST(...)` 用于普通测试
- `SHE_GTESTX_TEST_F(fixture, ...)` 用于基于 fixture 的测试

## 如何接入你的项目

`she_gtestx` 是 header-only 库，但它不是“零依赖头文件”。

你在使用它时，仍然需要：

- 让编译器能找到 `she_gtestx` 的头文件
- 让编译器能找到 GoogleTest 的头文件
- 在测试目标里链接 `gtest` 或 `gtest_main`

### 方式一：直接拷贝头文件

如果你只想快速使用，可以把下面这个目录拷到你的工程里：

- `include/she_gtestx/she_gtestx.h`

例如拷到你的项目目录：

```none
your_project/
├── third_party/
│   └── she_gtestx/
│       └── she_gtestx.h
└── tests/
    └── sample_test.cpp
```

然后在你的 `CMakeLists.txt` 里把头文件路径和 GoogleTest 连起来：

```cmake
find_package(GTest CONFIG REQUIRED)

add_executable(sample_tests tests/sample_test.cpp)
target_include_directories(sample_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/third_party)
target_link_libraries(sample_tests PRIVATE GTest::gtest GTest::gtest_main)
target_compile_features(sample_tests PRIVATE cxx_std_17)
```

测试代码：

```cpp
#include <gtest/gtest.h>
#include <she_gtestx/she_gtestx.h>

SHE_GTESTX_TEST(component, parser, http, parses_header) {
  EXPECT_EQ(2 + 2, 4);
}
```

### 方式二：作为子目录加入工程

如果你把 `she_gtestx` 作为子模块或子目录放进工程，可以直接：

```cmake
find_package(GTest CONFIG REQUIRED)

add_subdirectory(third_party/she_gtestx)

add_executable(sample_tests tests/sample_test.cpp)
target_link_libraries(sample_tests PRIVATE she_gtestx::she_gtestx GTest::gtest_main)
```

这种方式的好处是：

- 不需要手动写 `include` 路径
- 可以直接复用 `she_gtestx::she_gtestx` 目标

### 方式三：安装后通过 `find_package` 使用

先构建并安装 `she_gtestx`：

```bash
cmake -S . -B build -DCMAKE_INSTALL_PREFIX=/your/install/prefix
cmake --build build
cmake --install build
```

然后在你的项目里：

```cmake
find_package(GTest CONFIG REQUIRED)
find_package(she_gtestx CONFIG REQUIRED)

add_executable(sample_tests tests/sample_test.cpp)
target_link_libraries(sample_tests PRIVATE she_gtestx::she_gtestx GTest::gtest_main)
```

如果 `she_gtestx` 没有安装在系统默认路径下，需要把安装前缀加到 `CMAKE_PREFIX_PATH`：

```bash
cmake -S . -B build -DCMAKE_PREFIX_PATH=/your/install/prefix
```

### 普通测试

```cpp
#include <she_gtestx/she_gtestx.h>

SHE_GTESTX_TEST(component, parser, http, parses_header) {
  EXPECT_EQ(2 + 2, 4);
}
```

上面这个测试会被压平成一个普通的 GoogleTest 测试，大致等价于：

```cpp
TEST(component__parser__http, parses_header) {
  EXPECT_EQ(2 + 2, 4);
}
```

也就是说：

- 前面的层级会组成 `TestSuite`
- 最后一个参数会作为测试名 `TestName`

### 带 fixture 的测试

```cpp
#include <she_gtestx/she_gtestx.h>

class HttpParserTest : public ::testing::Test {};

SHE_GTESTX_TEST_F(HttpParserTest, component, parser, http, parses_header) {
  EXPECT_EQ(2 + 2, 4);
}
```

这类测试会保持 GoogleTest 原生的 fixture 语义。最终名字大致是：

```none
HttpParserTest.component__parser__http__parses_header
```

这里需要注意：

- `TestSuite` 仍然是 fixture 类型名 `HttpParserTest`
- 逻辑层级会被压进 `TestName`

这是为了兼容 GoogleTest 的 `TEST_F` 机制。

## 层级上限

现在 `SHE_GTESTX_TEST(...)` 和 `SHE_GTESTX_TEST_F(...)` 不是“任意层级”。

当前版本最多支持 **16 层逻辑层级**。

例如下面这种 16 层是支持的：

```cpp
SHE_GTESTX_TEST(level01,
                level02,
                level03,
                level04,
                level05,
                level06,
                level07,
                level08,
                level09,
                level10,
                level11,
                level12,
                level13,
                level14,
                level15,
                level16,
                works) {
  EXPECT_TRUE(true);
}
```

但再往上加第 17 层，当前实现就不支持了。

原因不是 GoogleTest 本身不允许，而是当前这版头文件的宏分发实现只展开到了 16 层。

## 当前限制

- 层级名必须是合法的 C++ 标识符
- 不能直接写字符串路径，例如 `"net/http/parser"`
- GoogleTest 内部仍然只有两层，并没有真的变成树形对象模型
- 当前最大层级为 16

## 构建

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

如果你只想编译库本身，不想编译示例和测试，可以关闭它们：

```bash
cmake -S . -B build \
  -DSHE_GTESTX_BUILD_TESTS=OFF \
  -DSHE_GTESTX_BUILD_EXAMPLES=OFF
cmake --build build
```

如果你想安装：

```bash
cmake -S . -B build -DCMAKE_INSTALL_PREFIX=/your/install/prefix
cmake --build build
cmake --install build
```

## 项目结构

- `include/she_gtestx/she_gtestx.h`：公开头文件
- `examples/`：最小示例
- `tests/`：验证当前行为的测试
- `cmake/`：安装与导出配置
