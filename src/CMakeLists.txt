set(INCROOT ${PROJECT_SOURCE_DIR}/include/InputAction)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src)

add_library(${PROJECT_NAME} SHARED
)

target_sources(${PROJECT_NAME}
    PRIVATE
        ${INCROOT}/detail/hash_combine.hpp
    PUBLIC
        ${INCROOT}/events/EventComponent.hpp
        ${SRCROOT}/EventComponent.cpp
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

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

find_package(aggup REQUIRED /usr/local/share/aggup)
find_package(SFML 2.5.1 COMPONENTS window REQUIRED)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        aggup
    PUBLIC
        sfml-window
)
