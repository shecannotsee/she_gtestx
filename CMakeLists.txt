cmake_minimum_required(VERSION 3.20)

project(
  she_gtestx
  VERSION 0.1.0
  DESCRIPTION "A thin multi-level extension layer on top of GoogleTest"
  LANGUAGES CXX)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

option(SHE_GTESTX_BUILD_TESTS "Build she_gtestx tests" ${PROJECT_IS_TOP_LEVEL})
option(SHE_GTESTX_BUILD_EXAMPLES "Build she_gtestx examples" ${PROJECT_IS_TOP_LEVEL})

find_package(GTest CONFIG QUIET)

if(NOT GTest_FOUND AND (SHE_GTESTX_BUILD_TESTS OR SHE_GTESTX_BUILD_EXAMPLES OR PROJECT_IS_TOP_LEVEL))
  include(FetchContent)

  set(gtest_force_shared_crt
      ON
      CACHE BOOL "" FORCE)

  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2)
  FetchContent_MakeAvailable(googletest)
endif()

add_library(she_gtestx INTERFACE)
add_library(she_gtestx::she_gtestx ALIAS she_gtestx)

target_compile_features(she_gtestx INTERFACE cxx_std_17)
target_include_directories(
  she_gtestx
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

if(TARGET GTest::gtest)
  target_link_libraries(she_gtestx INTERFACE GTest::gtest)
endif()

install(
  TARGETS she_gtestx
  EXPORT she_gtestxTargets)

install(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(
  EXPORT she_gtestxTargets
  FILE she_gtestxTargets.cmake
  NAMESPACE she_gtestx::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/she_gtestx)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/she_gtestxConfigVersion.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion)

configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/she_gtestxConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/she_gtestxConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/she_gtestx)

install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/she_gtestxConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/she_gtestxConfigVersion.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/she_gtestx)

if(SHE_GTESTX_BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()

if(SHE_GTESTX_BUILD_TESTS)
  include(CTest)
  enable_testing()
  add_subdirectory(tests)
endif()

