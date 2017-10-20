cmake_minimum_required(VERSION 3.4)
project(BIMProject)

#设置开发需要的库
SET(OSG_DIR "" CACHE PATH "osg directory")
SET(OSGEARTH_DIR "" CACHE PATH "osgEarth directory")
SET(MEEARTH_DIR "" CACHE PATH "MeEarth directory")

SET(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMakeModules/")
include(niubiMacroUtils)

FIND_PACKAGE(opengl)
FIND_PACKAGE(openThreads)
FIND_PACKAGE(osg)
FIND_PACKAGE(osgDB)
FIND_PACKAGE(osgUtil)
FIND_PACKAGE(osgGA)
FIND_PACKAGE(osgViewer)
FIND_PACKAGE(osgText)
FIND_PACKAGE(osgAnimation)
FIND_PACKAGE(osgShadow)
FIND_PACKAGE(osgTerrain)

# FIND_PACKAGE(fbx)

FIND_PACKAGE(osgEarth)

FIND_PACKAGE(MeEarth)
if(MEEARTH_FOUND)
    include_directories(${MEEARTH_INCLUDE_DIR})
endif(MEEARTH_FOUND)


OPTION(BUILD_STATIC_LIBRAY  "建造静态库" ON)
OPTION(BUILD_WINDOWS_SYSTEM "建造窗口程序" OFF)


SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)


# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Widgets finds its own dependencies (QtGui and QtCore).
# find_package(Qt5Widgets REQUIRED)
find_package(Qt5 COMPONENTS
    Widgets
    OpenGL
    Multimedia
    # Declarative
    LinguistTools #for ts
    )

# The Qt5Widgets_INCLUDES also includes the include directories for
# dependencies QtCore and QtGui
include_directories(
    ${Qt5Widgets_INCLUDE_DIRS}
    ${Qt5Multimedia_INCLUDE_DIRS}
    )

# We need add -DQT_WIDGETS_LIB when using QtWidgets in Qt 5.
add_definitions(
    ${Qt5Widgets_DEFINITIONS}
    ${Qt5Multimedia_DEFINITIONS}
    )

# message( WARNING "aa" ${Qt5Multimedia_INCLUDE_DIRS} )

# Executables fail to build with Qt 5 in the default configuration
# without -fPIE. We add that here.
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

# set postfix
SET(CMAKE_DEBUG_POSTFIX "d" CACHE STRING "add a postfix, usually d on windows")
SET(CMAKE_RELEASE_POSTFIX "" CACHE STRING "add a postfix, usually empty on windows")
SET(CMAKE_RELWITHDEBINFO_POSTFIX "rd" CACHE STRING "add a postfix, usually empty on windows")
SET(CMAKE_MINSIZEREL_POSTFIX "s" CACHE STRING "add a postfix, usually empty on windows")

include_directories( ${CMAKE_SOURCE_DIR}/include )
include_directories( ${OSG_INCLUDE_DIR} )
# include_directories( ${FBX_INCLUDE_DIR} )

LINK_DIRECTORIES( ${OSG_DIR}/lib )
LINK_DIRECTORIES( ${MEEARTH_DIR}/lib )

set(CMAKE_AUTOMOC OFF)


add_subdirectory(BIMProject)
