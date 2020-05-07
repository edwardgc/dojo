# 查找 GTest 库
set(GTEST_ROOT "D:\\Users\\cguo005\\googletest")

set(GTEST_INCLUDE_DIR "${GTEST_ROOT}/googletest/include" "${GTEST_ROOT}/googlemock/include")
set(GTEST_LIBRARY "${GTEST_ROOT}/build/lib/Debug/gtestd.lib")
set(GTEST_MAIN_LIBRARY "${GTEST_ROOT}/build/lib/Debug/gmock_maind.lib")
find_package(GTest)
include(GoogleTest)

include_directories(${GTEST_INCLUDE_DIR})

# aux_source_directory(. DIR_TEST_SRCS)
# add_library(tests ${DIR_TEST_SRCS})
FILE(GLOB_RECURSE TEST_SRC ${CMAKE_SOURCE_DIR}/test/*.cpp ${CMAKE_SOURCE_DIR}/test/*.hpp)

add_executable(mytest ${TEST_SRC})

target_link_libraries(mytest
    ${GTEST_MAIN_LIBRARY}
    )

# # 添加到测试
# gtest_discover_tests(mytest)
