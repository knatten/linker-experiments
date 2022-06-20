project(Core LANGUAGES CXX)

add_library(Core SHARED core.cpp)
target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Core PRIVATE Base)

