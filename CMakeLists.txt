cmake_minimum_required(VERSION 3.8)
project(CppBoostPluginSystem)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost 1.64.0 COMPONENTS system filesystem REQUIRED)

if(Boost_FOUND)

    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})

endif()

include_directories(${Boost_INCLUDE_DIRS})


set(SOURCE_FILES
        main.cpp
        IPlugin.h
        PluginLoader.cpp
        PluginLoader.h
        tests/TestCase.h
        tests/BenchmarkRun.cpp
        tests/BenchmarkRun.h
        tests/util/Stopwatch.h
        tests/util/Stopwatch.cpp
        tests/benchmarks/LoadAndUnloadBenchmark.h
        tests/benchmarks/EnableAndDisableBenchmark.h
        tests/benchmarks/ContextSwitchBenchmark.h
        tests/benchmarks/ContextSwitchReturnTypeBenchmark.h
        StringFace.h
        )
add_executable(CppBoostPluginSystem ${SOURCE_FILES})


set(FIRST HelloPlugin.cpp IPlugin.h StringFace.h)
set(SECOND SecondPlugin.cpp IPlugin.h StringFace.h)

add_library(FirstPlugin SHARED ${FIRST})
add_library(SecondPlugin SHARED ${SECOND})

if(Boost_FOUND)

    target_link_libraries(CppBoostPluginSystem ${Boost_LIBRARIES})
    target_link_libraries(FirstPlugin ${Boost_LIBRARIES})
    target_link_libraries(SecondPlugin ${Boost_LIBRARIES})

endif()