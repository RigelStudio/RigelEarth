
set( NIUBI_SETUP_TARGET_NAME BIMProject )
set( LIBRARY_IBLCUDE_DIR ${CMAKE_SOURCE_DIR}/include/${NIUBI_SETUP_TARGET_NAME} )

link_directories( ${OSG_DIR}/lib ${OSGEARHT_DIR}/lib ${MEEARTH_DIR}/lib )

set(CMAKE_AUTOMOC ON)


qt5_wrap_ui(ui_FILES 
    BIMProject.ui
    LeftPanel.ui
    TopMenu.ui
    )  
    
qt5_add_resources(QRCS 
    BIMProject.qrc
    )

SET(NIUBI_SETUP_HEADERS
)

SET(NIUBI_SETUP_SOURCES

    ${ui_FILES}
    ${QRCS}

    BIMProject.h
    BIMProject.cpp
    
    InitProject.h
    InitProject.cpp
    
    LeftPanel.h
    LeftPanel.cpp
    
    TopMenu.h
    TopMenu.cpp
    
    InputLib.cpp
    
    main.cpp
    )

    
NIUBI_SETUP_EXECUTABLE(ON)
# The Qt5Widgets_LIBRARIES variable also includes QtGui and QtCore
target_link_libraries(${NIUBI_SETUP_TARGET_NAME} ${Qt5Widgets_LIBRARIES})
NIUBI_SETUP_INSTALL()
NIUBI_SETUP_INSTALL_INCLUDE()
NIUBI_SETUP_DOCUMENT()
