cmake_minimum_required(VERSION 3.16...3.21)

set(EXPORT_COMPILE_COMMANDS ON)
project(Application_Main)
find_package(Geant4 REQUIRED ui_all vis_all)

# Set the Path to the Header Files of Geant4 and the Current Project
include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

# Compile and Link the Current Project
add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cc ${sources} ${headers})
target_link_libraries(${PROJECT_NAME} ${Geant4_LIBRARIES})
