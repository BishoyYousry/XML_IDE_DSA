cmake_minimum_required(VERSION 3.5)

project(QT_Application VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)


set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        linenumberarea.cpp
        codeeditor.cpp
        clickablelabel.cpp
        inputdialog.cpp
        XMLformatting.cpp
        xml_minifying.cpp
        Error_detection.cpp
        compression.cpp
        decompression.cpp
        json_Conversion.cpp
        Tree_Node.cpp
        Graph.cpp
        set.cpp
        User.cpp
        Utility.cpp
        mainwindow.ui
        resource.qrc
)
set(PROJECT_HEADERS
    mainwindow.h
    CodeEditor.h
    linenumberarea.h
    clickablelabel.h
    inputdialog.h
    XMLformatting.h
    xml_minifying.h
    Error_detection.h
    compression.h
    decompression.h
    Tree_Node.h
    json_Conversion.h
    Graph.h
    set.h
    User.h
    Utility.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(QT_Application
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES} ${PROJECT_HEADERS}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET QT_Application APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(QT_Application SHARED
            ${PROJECT_SOURCES} ${PROJECT_HEADERS}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(QT_Application
            ${PROJECT_SOURCES} ${PROJECT_HEADERS}
        )
    endif()
endif()

target_link_libraries(QT_Application PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(QT_Application PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS QT_Application
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QT_Application)
endif()
