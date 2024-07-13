cmake_minimum_required(VERSION 3.5)

project(async_writer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost COMPONENTS program_options REQUIRED )
find_package(Threads)
find_package(GTest REQUIRED)

add_library(lib_async STATIC
    main.cpp
    context.hpp
    context.cpp
    processing/parser.hpp
    processing/parser.cpp
    processing/controller.hpp
    processing/controller.cpp
    processing/accumulator.hpp
    processing/accumulator.cpp
    utility/command.hpp
    utility/command.cpp
    utility/utility.hpp
    utility/notify_queue.hpp
    post_processing/postprocessor.hpp
    post_processing/postprocessor.cpp
    post_processing/postprocessor_handler.hpp
    post_processing/output_handler.hpp
    post_processing/output_handler.cpp
    post_processing/logging_handler.hpp
    post_processing/logging_handler.cpp
    post_processing/postprocessor_handler.cpp
    async.hpp
    async.cpp)

include_directories(${GTEST_INCLUDE_DIR})
include_directories(${Boost_INCLUDE_DIR})
include_directories(utility)
include_directories(processing)
include_directories(post_processing)


target_link_libraries(lib_async
        ${Boost_LIBRARIES}
        ${CMAKE_THREAD_LIBS_INIT})


add_executable(main main.cpp)
target_link_libraries(main lib_async)


add_executable(unit_tests
    test/controller_test.cpp
    test/parser_test.cpp
    test/main.cpp)

target_link_libraries(unit_tests
        gtest
        pthread
        lib_async)

enable_testing()

add_test(unit_tests unit_tests)
