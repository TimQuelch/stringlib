cmake_minimum_required(VERSION 3.10)
project(stringlib VERSION 0.1.0 LANGUAGES CXX)

# Add library target
add_library(stringlib src/stringlib.cpp)
add_library(stringlib::stringlib ALIAS stringlib)

# Configure library target
target_include_directories(stringlib
    PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
target_compile_features(stringlib PUBLIC cxx_std_17)
target_compile_options(stringlib PRIVATE -Wall -Werror -Wextra -Wpedantic)

# Add tests
enable_testing()
add_subdirectory(test)

# Add docs
add_subdirectory(docs)

# Install
include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/stringlib)

install(
    TARGETS stringlib
    EXPORT stringlib-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(
    EXPORT stringlib-targets
    FILE stringlibTargets.cmake
    NAMESPACE stringlib::
    DESTINATION ${INSTALL_CONFIGDIR})

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/stringlibConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion)

configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/stringlibConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/stringlibConfig.cmake
    INSTALL_DESTINATION ${INSTALL_CONFIGDIR})

install(
    FILES
    ${CMAKE_CURRENT_BINARY_DIR}/stringlibConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/stringlibConfigVersion.cmake
    DESTINATION ${INSTALL_CONFIGDIR})

export(
    EXPORT stringlib-targets
    FILE ${CMAKE_CURRENT_BINARY_DIR}/stringlibTargets.cmake
    NAMESPACE stringlib::)

export(PACKAGE stringlib)
