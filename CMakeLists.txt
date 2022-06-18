cmake_minimum_required(VERSION 3.5)
project(all_any_none_program VERSION 0.1 LANGUAGES CXX )

set ( CMAKE_CXX_FLAGS "-Wall -W -pedantic" )



set( INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include )
set( SRC_DIR ${CMAKE_SOURCE_DIR}/src )



include_directories( include )



set( APP_NAME "dnaprofiler" )
add_executable( ${APP_NAME}
                src/main.cpp )



target_sources( ${APP_NAME} PUBLIC ${SRC_DIR}/unknownProfile.cpp )
target_sources( ${APP_NAME} PUBLIC ${SRC_DIR}/personProfile.cpp )



set_property(TARGET ${APP_NAME} PROPERTY CXX_STANDARD 11)