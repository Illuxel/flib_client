cmake_minimum_required(VERSION 3.24)

if (NOT DEFINED CMAKE_INSTALL_LIBDIR)
  set(CMAKE_INSTALL_LIBDIR "lib")
endif()
if (NOT DEFINED CMAKE_INSTALL_BINDIR)
  set(CMAKE_INSTALL_BINDIR "bin")
endif()
if (NOT DEFINED CMAKE_INSTALL_INCLUDEDIR)
  set(CMAKE_INSTALL_INCLUDEDIR "include")
endif()

qt6_add_library(ForwardClientLib STATIC)

message(STATUS "Building Forward.Client.Lib")

set_target_properties(ForwardClientLib PROPERTIES AUTOMOC ON)
target_link_libraries(ForwardClientLib PUBLIC Qt6::Core Qt6::Widgets Qt6::Qml Qt6::Quick Qt6::QuickControls2)
target_include_directories(ForwardClientLib
PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/forward/client>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/forward/client>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/forward/api>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/forward/api>
)

set(FLAPI_SOURCE
    forward/api/MessageModel.cpp
    forward/api/MessageModel.hpp
)

set(FLCLIENT_SOURCE 
    forward/client/Settings.cpp
    forward/client/Settings.hpp
    forward/client/Style.cpp
    forward/client/Style.hpp
    forward/client/Localization.cpp
    forward/client/Localization.hpp
)

qt6_add_qml_module(ForwardClientLib
    URI forward.client
    RESOURCE_PREFIX /imports
    SOURCES
        ${FLAPI_SOURCE}
        ${FLCLIENT_SOURCE}
)
