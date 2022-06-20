project(Base LANGUAGES CXX)

add_library(Base STATIC base.cpp)
target_include_directories(Base PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

