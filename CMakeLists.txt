#添加CMakeList头信息，cmake最低版本
cmake_minimum_required(VERSION 2.8)

#设置当前CMakeList.txt所在文件为当前目录
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 设置解决方案名称
project(MeEarth)

#设置开发需要的第三方库
SET(OSG_DIR "" CACHE PATH "osg and osgEarth directory")
SET(MEGISENGINE_DIR "" CACHE PATH "MeEarth directory")

# 如果不配置第三方库，则不进行之后的生成
if(NOT OSG_DIR)
	message(FATAL_ERROR "请选择osg和osgEarth的目录!")
endif()

if(NOT MEGISENGINE_DIR)
	message(FATAL_ERROR "请选择MeGISEngine的目录!")
endif()

# 设置第三方头文件与链接库的路径
include_directories(
	${OSG_DIR}/include
	${CMAKE_BINARY_DIR}
	${MEGISENGINE_DIR}/src
)

link_directories(
	${OSG_DIR}/lib
	${OUTPUT_LIBDIR}
)

#设置cmake其他模块功能的路径
SET(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMakeModules/")
#设置要使用的cmake模块
#include()


#查找MeGISEngine开发包
FIND_PACKAGE(MeGISEngine)
if(MEGISENGINE_FOUND)
    include_directories(${MEGISENGINE_INCLUDE_DIR})
endif(MEEARTH_FOUND)


OPTION(BUILD_STATIC_LIBRAY  "建造静态库" ON)
OPTION(BUILD_WINDOWS_SYSTEM "建造窗口程序" OFF)


# 设置输出路径，不区分不32、64
set(OUTPUT_BINDIR ${CMAKE_SOURCE_DIR}/bin)

# 设置lib库的输出路径，不区分32、64
set(OUTPUT_LIBDIR ${CMAKE_SOURCE_DIR}/lib)

# 对每一个平台，设置其输出路径
foreach(CONF ${CMAKE_CONFIGURATION_TYPES})
	string(TOUPPER "${CONF}" CONF_UC)
	set("CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${CONF_UC}" ${OUTPUT_LIBDIR})
	set("CMAKE_RUNTIME_OUTPUT_DIRECTORY_${CONF_UC}" ${OUTPUT_BINDIR})
	set("CMAKE_LIBRARY_OUTPUT_DIRECTORY_${CONF_UC}" "${OUTPUT_BINDIR}${SEPARATE_FOLDER}")
endforeach()

# Debug库输出带d,Release不带
set(CMAKE_DEBUG_POSTFIX "d" CACHE STRING "add a postfix, usually d on windows")
set(CMAKE_RELEASE_POSTFIX "" CACHE STRING "add a postfix, usually empty on windows")
if(CMAKE_BUILD_TYPE MATCHES "Release")
	SET(CMAKE_BUILD_POSTFIX "${CMAKE_RELEASE_POSTFIX}")
elseif(CMAKE_BUILD_TYPE MATCHES "Debug")
	SET(CMAKE_BUILD_POSTFIX "${CMAKE_DEBUG_POSTFIX}")
else()
	SET(CMAKE_BUILD_POSTFIX "")
endif()

#添加子目录
add_subdirectory(src)
