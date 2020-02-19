#-------------------------------------------------------------------------------
#	CMAKE SETTINGS
#-------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.12.0)
set(QT_MINIMUM_VERSION 5.13.1)
#-------------------------------------------------------------------------------
#	SOURCE CODE
#-------------------------------------------------------------------------------
file(GLOB_RECURSE QWT3D_FILES "qwt3d/*.h" "qwt3d/*.cpp")
file(GLOB_RECURSE HEADER_FILES "src/*.h")
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")
#-------------------------------------------------------------------------------
#	PROJECT SETTINGS
#-------------------------------------------------------------------------------
set(TARGET_NAME qwt3d-examples)
set(PROJECT_NAME ${TARGET_NAME})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(${PROJECT_NAME} LANGUAGES CXX)
#-------------------------------------------------------------------------------
#	Qt SETTINGS
#-------------------------------------------------------------------------------
# Required Qt settings
set(QtPath "${CMAKE_SOURCE_DIR}/ext")

set(CMAKE_PREFIX_PATH ${QtPath})
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# Find the necessary Qt5 modules
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5OpenGL REQUIRED) # Required for Qwt3D
#-------------------------------------------------------------------------------
#	SOURCE GROUPS
#-------------------------------------------------------------------------------
source_group(generated REGULAR_EXPRESSION ".*_automoc.cpp")
source_group(sources REGULAR_EXPRESSION ".*[.]cpp")
source_group(headers REGULAR_EXPRESSION ".*[.]h")
#-------------------------------------------------------------------------------
#	ADDITIONAL LIBRARIES
#-------------------------------------------------------------------------------
list(APPEND LIBRARIES
Qt5::Core
Qt5::Gui
Qt5::Widgets
# Following are required for Qwt3D!
Qt5::OpenGL
opengl32
glu32
gdi32
)
#-------------------------------------------------------------------------------
#	GENERATE EXECUTABLE
#-------------------------------------------------------------------------------
# Generate the executable
add_executable(${TARGET_NAME} ${QWT3D_FILES} ${HEADER_FILES} ${SOURCE_FILES})
# link libraries
target_link_libraries(${TARGET_NAME} ${LIBRARIES})
