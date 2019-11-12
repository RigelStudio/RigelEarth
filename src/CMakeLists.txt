# 添加CMakeList头信息，cmake最低版本
cmake_minimum_required(VERSION 2.8.12)

# Set porject name
set(TargetName RigelEarth)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed.
#set(CMAKE_AUTOMOC ON)

# Find the Qt librarys
find_package(Qt5 COMPONENTS 
Core 
Gui
Widgets
OpenGL
)

# Find all Files
set(qrcs ${TargetName}.qrc)

#set(icon ${TargetName}.ico ${TargetName}.rc)

set(forms BIMProject.ui TopMenu.ui LeftPanel.ui)

set(headers
BIMProject.h
LeftPanel.h
TopMenu.h
)

set(sources
main.cpp
InputLib.cpp
BIMProject.cpp
LeftPanel.cpp
TopMenu.cpp
)

# Qt warp files
qt5_wrap_ui(Forms_Ui ${forms} )
qt5_wrap_cpp(Headers_Moc ${headers} )
qt5_add_resources(Res_Qrc ${qrcs})

# add definitions,unicode and export
add_definitions(-DUNICODE -D_UNICODE)

# Set porject filiter
source_group("Header Files" FILES ${headers})
source_group("Form Files" FILES ${forms})
source_group("Resource Files" FILES ${qrcs} ${icon})
source_group("Generated Files" FILES ${Forms_Ui} ${headers} ${qrcs})

# Tell CMake to create the TargetName executable
add_executable(${TargetName} ${sources} ${Forms_Ui} ${Headers_Moc} ${Res_Qrc} ${headers} ${icon}
				)

set_target_properties(${TargetName} PROPERTIES DEBUG_OUTPUT_NAME "${TargetName}${CMAKE_DEBUG_POSTFIX}")
set_target_properties(${TargetName} PROPERTIES RELEASE_OUTPUT_NAME "${TargetName}${CMAKE_RELEASE_POSTFIX}")

# Use the Qt5 modules
target_link_libraries(${TargetName} Qt5::Core Qt5::Gui Qt5::Widgets
	Qt5::OpenGL MeQt MeDB MeCore)
