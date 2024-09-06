cmake_minimum_required(VERSION 3.29)
project(BoidSimulation)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)


add_executable(${PROJECT_NAME}
        main.cpp
        logger.h
        boid_simulator.cpp
        boid_simulator.h
        im_sketch.h
        vector2.h
        app.rc
        application.cpp
        application.h
        im_framerate_graph.h
        GUI.h
        utility.h)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
)

target_link_libraries(${PROJECT_NAME} PRIVATE imgui::imgui)

target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/assets
        ${CMAKE_CURRENT_BINARY_DIR}/assets)
