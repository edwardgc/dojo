# 设置cmake版本
cmake_minimum_required(VERSION 3.0)
# 设置项目名称
project(vs)

# 使用c++11标准编译
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++ ${CMAKE_CXX_FLAGS}")
endif()

# 在配置阶段下载和解压googletest
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# windwos下避免覆盖编译器配置
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# gtest配置在build目录下
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# 兼容CMake2.8.11以前的版本
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()


aux_source_directory(src LIB_SRC)
list(REMOVE_ITEM LIB_SRC "src/Main.cpp")

include_directories(include src)
add_library(${PROJECT_NAME}_lib ${LIB_SRC})
add_executable(${PROJECT_NAME} src/Main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_lib)

# 添加测试程序
set(TEST_SOURCE test/Test.cpp)
add_executable(${PROJECT_NAME}-test ${LIB_SRC} ${TEST_SOURCE})
target_link_libraries(${PROJECT_NAME}-test gtest_main)