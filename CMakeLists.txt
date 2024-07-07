cmake_minimum_required(VERSION 3.5)

project(async_writer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost COMPONENTS program_options REQUIRED )

add_executable(async_writer main.cpp
    context.hpp context.cpp
    parser.hpp parser.cpp
    controller.hpp controller.cpp
    notify_queue.hpp
    accumulator.hpp accumulator.cpp
    command.hpp command.cpp
    utility.hpp
    postprocessor.hpp postprocessor.cpp
    postprocessor_handler.hpp
    output_handler.hpp output_handler.cpp
    logging_handler.hpp logging_handler.cpp
    postprocessor_handler.cpp)

include(GNUInstallDirs)
install(TARGETS async_writer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
