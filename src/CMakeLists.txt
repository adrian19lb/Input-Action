include(GNUInstallDirs)

set(INCROOT ${PROJECT_SOURCE_DIR}/include/InputAction)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src)

add_library(${PROJECT_NAME} SHARED
    ${SRCROOT}/KeyboardDispatcher.cpp
    ${SRCROOT}/MouseDispatcher.cpp
    ${SRCROOT}/Dispatcher.cpp
    ${SRCROOT}/EventComponent.cpp
    ${SRCROOT}/Action.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${INCROOT}>
        $<INSTALL_INTERFACE:include/InputAction>
    PRIVATE
        ${SRCROOT}
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES LINKER_LANGUAGE CXX
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

find_package(aggup REQUIRED /usr/local/share/aggup)
find_package(SFML 2.5.1 COMPONENTS window REQUIRED)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        aggup
    PUBLIC
        sfml-window
)

install(TARGETS ${PROJECT_NAME} EXPORT "${PROJECT_NAME}Config"
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(DIRECTORY ${INCROOT} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT "${PROJECT_NAME}Config" DESTINATION share/${PROJECT_NAME}/cmake)

export(TARGETS ${PROJECT_NAME} FILE "${PROJECT_NAME}Config.cmake")

