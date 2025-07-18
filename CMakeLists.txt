cmake_minimum_required(VERSION 3.31)
project(fractals)

# Directories
set(IMGUI_SRC_DIR libs/imgui)
set(LIB_SFML_PATH libs/sfml)
set(LIB_DIR libs)
set(INCLUDE_DIR includes)
set(SRC_DIR src)

# Load OpenGL
set(OpenGL_GL_PREFERENCE "GLVND")
find_package(OpenGL REQUIRED)

# Load SFML
find_package(
    SFML 2.5.1 COMPONENTS REQUIRED
    system
    window
    graphics
    PATHS ${LIB_SFML_PATH}
)

# Load source and header files
set(SOURCES ${SRC_DIR}/main.cpp)
set(HEADERS)

# Load ImGUI src files
set(
    IMGUI_LIB_SRC
    ${IMGUI_SRC_DIR}/imgui.cpp
    ${IMGUI_SRC_DIR}/imgui_draw.cpp
    ${IMGUI_SRC_DIR}/imgui_tables.cpp
    ${IMGUI_SRC_DIR}/imgui_widgets.cpp
    ${IMGUI_SRC_DIR}/imgui-SFML.cpp
)

# Load GLAD and STB src files
set(
    LIBS_SRC
    ${LIB_DIR}/glad/src/glad.c
)

# Include directories
include_directories(
    ${LIB_DIR}
    ${INCLUDE_DIR}
    ${LIB_DIR}/glad/include
)

# Executable
add_executable(
    ${CMAKE_PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${LIBS_SRC}
    ${IMGUI_LIB_SRC}
)

# Include directory to target
target_include_directories(
    ${CMAKE_PROJECT_NAME} PRIVATE
    ${IMGUI_SRC_DIR}
)

set(OpenGL_GL_PREFERENCE "GLVND")
find_package(OpenGL REQUIRED)

# Link libraries to target
target_link_libraries(
    ${CMAKE_PROJECT_NAME} PRIVATE
    sfml-system
    sfml-window
    sfml-graphics
    dl
    ${OPENGL_LIBRARY}
)