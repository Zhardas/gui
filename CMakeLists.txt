cmake_minimum_required(VERSION 3.2)
project(headacheGUI)

add_subdirectory(${PROJECT_SOURCE_DIR}/comparison_gui)

add_subdirectory(${PROJECT_SOURCE_DIR}/engine)
include_directories("${PROJECT_SOURCE_DIR}/engine")

include_directories(SYSTEM "${PROJECT_SOURCE_DIR}/engine/lib/dx/include/")
link_directories(${PROJECT_SOURCE_DIR}/engine/lib/dx/lib/x86/)

include_directories(SYSTEM "${PROJECT_SOURCE_DIR}/engine/lib/vorbis/include/")
link_directories(${PROJECT_SOURCE_DIR}/engine/lib/vorbis/lib/)

include_directories(SYSTEM "${PROJECT_SOURCE_DIR}/engine/lib/enet/include")
link_directories(${PROJECT_SOURCE_DIR}/engine/lib/enet/lib/)

include_directories(SYSTEM "${PROJECT_SOURCE_DIR}/lib/fftw3/include")
link_directories(${PROJECT_SOURCE_DIR}/lib/fftw3/lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg -std=gnu++14 -Wall -Wno-unused-function")

add_executable(headacheGUI
        main.cpp
        main_scene.cpp
        main_scene.h
        )

target_link_libraries(headacheGUI headache2 m)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources DESTINATION ${DESTINATION}/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/engine/lib/vorbis/lib/libvorbis.dll DESTINATION ${DESTINATION}/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/engine/lib/vorbis/lib/libvorbisfile.dll DESTINATION ${DESTINATION}/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/engine/lib/vorbis/lib/libogg.dll DESTINATION ${DESTINATION}/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/engine/debug/ DESTINATION ${DESTINATION}/)