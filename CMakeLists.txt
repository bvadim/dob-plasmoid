project(plasma-dob)
 
find_package(KDE4 REQUIRED)
include(KDE4Defaults)
find_package(LibXml2)

add_definitions (${QT_DEFINITIONS} ${KDE4_DEFINITIONS})
include_directories( ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR} ${KDE4_INCLUDES} )
 
set(dob_SRCS dob.cpp config.cpp WebManager.cpp DobHtmlParser.cpp)
 
kde4_add_ui_files(dob_SRCS settings.ui)
kde4_add_plugin(plasma_applet_dob ${dob_SRCS})

target_link_libraries ( plasma_applet_dob
                        ${KDE4_PLASMA_LIBS}
                        ${KDE4_KDEUI_LIBS}
                        ${QT_QTNETWORK_LIBRARY}
                        ${LIBXML2_LIBRARIES})
 
install(TARGETS plasma_applet_dob
        DESTINATION ${PLUGIN_INSTALL_DIR})
 
install(FILES plasma-applet-dob.desktop
        DESTINATION ${SERVICES_INSTALL_DIR})
