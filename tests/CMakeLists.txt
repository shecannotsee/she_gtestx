add_executable(she_gtestx_tests she_gtestx_test.cpp)
target_link_libraries(she_gtestx_tests PRIVATE she_gtestx::she_gtestx GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(she_gtestx_tests)

