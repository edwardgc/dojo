cmake_minimum_required(VERSION 3.0.0)
project(vs-project VERSION 0.1.0)

set(GTEST_ROOT "D:\\Users\\cguo005\\googletest")
set(GTEST_INCLUDE_DIR "${GTEST_ROOT}/googletest/include" "${GTEST_ROOT}/googlemock/include")
set(GTEST_LIBRARY "${GTEST_ROOT}/build/lib/Debug/gmockd.lib")
set(GTEST_MAIN_LIBRARY "${GTEST_ROOT}/build/lib/Debug/gmock_maind.lib")

include_directories("${gtest_SOURCE_DIR}/include")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

set(LIB_SRC
  src/example.cpp
)

include_directories(include src ${GTEST_INCLUDE_DIR})
add_library(${PROJECT_NAME}_lib ${LIB_SRC})
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_lib)

# 添加测试程序
set(TEST_SOURCE test/test)
add_executable(${PROJECT_NAME}-test ${LIB_SRC} ${TEST_SOURCE})
target_link_libraries(${PROJECT_NAME}-test ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY})
