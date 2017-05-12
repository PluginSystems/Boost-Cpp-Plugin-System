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


set(SOURCE_FILES main.cpp IPlugin.h PluginLoader.cpp PluginLoader.h HelloPlugin.cpp)
add_executable(CppBoostPluginSystem ${SOURCE_FILES})


set(LIBRARY_FILES HelloPlugin.cpp IPlugin.h)

add_library(BoostPlugin SHARED ${LIBRARY_FILES})

if(Boost_FOUND)

    target_link_libraries(CppBoostPluginSystem ${Boost_LIBRARIES})
    target_link_libraries(BoostPlugin ${Boost_LIBRARIES})

endif()

