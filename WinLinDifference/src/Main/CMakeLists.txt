project(Main LANGUAGES CXX)

add_executable(Main main.cpp)
target_link_libraries(Main PRIVATE Base Core)
