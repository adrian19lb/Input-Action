set(INCROOT ${PROJECT_SOURCE_DIR}/include/InputAction)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src)

add_library(${PROJECT_NAME} SHARED
)

target_sources(${PROJECT_NAME}
    PRIVATE
        ${INCROOT}/detail/hash_combine.hpp
        ${INCROOT}/events/button/Dispatcher.hpp
        ${SRCROOT}/Dispatcher.cpp
        ${INCROOT}/events/button/KeyboardDispatcher.hpp
        ${SRCROOT}/KeyboardDispatcher.cpp
        ${INCROOT}/detail/is_smart_pointer.hpp
        ${INCROOT}/detail/Dereferencer.hpp
        ${INCROOT}/detail/Comperator.hpp
        ${INCROOT}/detail/Hasher.hpp
        ${INCROOT}/events/button/State.hpp
        ${INCROOT}/events/button/Fixture.hpp
        ${INCROOT}/events/button/PressOnceState.hpp
        ${INCROOT}/events/button/HoldState.hpp
        ${INCROOT}/events/button/ReleaseState.hpp
        ${INCROOT}/events/button/PressSecondState.hpp
        ${INCROOT}/detail/RangeSearcher.hpp
        ${INCROOT}/events/button/FixtureReceiver.hpp
        ${INCROOT}/events/button/FixtureRangeReceiver.hpp
        ${INCROOT}/detail/Buffer.hpp
    PUBLIC
        ${INCROOT}/events/EventComponent.hpp
        ${SRCROOT}/EventComponent.cpp
        ${INCROOT}/events/ButtonComponent.hpp
        ${INCROOT}/events/button/ButtonComponent.inc
        ${INCROOT}/events/ButtonAction.hpp
        ${INCROOT}/events/KeyboardKeyComponent.hpp
        ${INCROOT}/events/button/KeyboardKeyComponent.inc
        ${INCROOT}/Action.hpp
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
