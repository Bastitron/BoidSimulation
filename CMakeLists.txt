cmake_minimum_required(VERSION 3.29)
project(BoidSimulation)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

add_executable(${PROJECT_NAME} main.cpp
        utility/Logger.h)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)
target_link_libraries(${PROJECT_NAME} PRIVATE imgui::imgui)

target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)
