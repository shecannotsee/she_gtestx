# she_gtestx

`she_gtestx` is a small C++17 header-first extension layer for GoogleTest.

Chinese documentation: [README.zh-CN.md](/home/shecannotsee/Desktop/projects/she_gtestx/README.zh-CN.md)

The initial scaffold keeps GoogleTest untouched and flattens extra logical test
levels into the names GoogleTest already understands.

The public entry points are:

- `SHE_GTESTX_TEST(...)`
- `SHE_GTESTX_TEST_F(fixture, ...)`

The current implementation supports up to 16 logical levels. The internal
`SHE_GTESTX_TEST_1..16` and `SHE_GTESTX_TEST_F_1..16` macros are kept as the
dispatch targets, but they are no longer the primary user-facing API.

## Layout

- `include/she_gtestx/she_gtestx.h`: public single-header interface
- `examples/`: minimal usage example
- `tests/`: scaffold validation tests
- `cmake/`: package config template for installation/export

## Using she_gtestx

`she_gtestx` is header-only, but it still depends on GoogleTest headers and
link targets.

To use it in another project, you need:

- access to `include/she_gtestx/she_gtestx.h`
- access to GoogleTest headers
- to link your test target against `gtest` or `gtest_main`

### Option 1: copy the header

You can copy:

- `include/she_gtestx/she_gtestx.h`

into your project, for example under `third_party/`.

```cmake
find_package(GTest CONFIG REQUIRED)

add_executable(sample_tests tests/sample_test.cpp)
target_include_directories(sample_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/third_party)
target_link_libraries(sample_tests PRIVATE GTest::gtest GTest::gtest_main)
target_compile_features(sample_tests PRIVATE cxx_std_17)
```

### Option 2: add_subdirectory

If `she_gtestx` is vendored into your repository:

```cmake
find_package(GTest CONFIG REQUIRED)

add_subdirectory(third_party/she_gtestx)

add_executable(sample_tests tests/sample_test.cpp)
target_link_libraries(sample_tests PRIVATE she_gtestx::she_gtestx GTest::gtest_main)
```

### Option 3: install and find_package

Install `she_gtestx` first:

```bash
cmake -S . -B build -DCMAKE_INSTALL_PREFIX=/your/install/prefix
cmake --build build
cmake --install build
```

Then consume it from another project:

```cmake
find_package(GTest CONFIG REQUIRED)
find_package(she_gtestx CONFIG REQUIRED)

add_executable(sample_tests tests/sample_test.cpp)
target_link_libraries(sample_tests PRIVATE she_gtestx::she_gtestx GTest::gtest_main)
```

If it is installed in a non-default prefix, add that prefix to
`CMAKE_PREFIX_PATH`.

## Build

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

To build only the library scaffold without examples or tests:

```bash
cmake -S . -B build \
  -DSHE_GTESTX_BUILD_TESTS=OFF \
  -DSHE_GTESTX_BUILD_EXAMPLES=OFF
cmake --build build
```

To install:

```bash
cmake -S . -B build -DCMAKE_INSTALL_PREFIX=/your/install/prefix
cmake --build build
cmake --install build
```

## Example

```cpp
#include <she_gtestx/she_gtestx.h>

SHE_GTESTX_TEST(component, parser, http, parses_header) {
  EXPECT_EQ(2 + 2, 4);
}
```

The example above expands to a regular GoogleTest test whose suite name becomes
`component__parser__http`.

With a fixture:

```cpp
class HttpParserTest : public ::testing::Test {};

SHE_GTESTX_TEST_F(HttpParserTest, component, parser, http, parses_header) {
  EXPECT_EQ(2 + 2, 4);
}
```

This keeps the GoogleTest suite name as `HttpParserTest` and flattens the
logical levels into the test name:

```none
HttpParserTest.component__parser__http__parses_header
```

## Current Limits

- Logical levels must be valid C++ identifiers, not string paths.
- The current maximum depth is 16 levels.
- The hierarchy is encoded into GoogleTest names; GoogleTest itself still sees
  only two levels.
