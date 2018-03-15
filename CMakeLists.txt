cmake_minimum_required(VERSION 3.10)
project(stringutils VERSION 0.1.0 LANGUAGES CXX)

# Add library target
add_library(stringutils src/stringutils.cpp)
add_library(stringutils::stringutils ALIAS stringutils)

# Configure library target
target_include_directories(
    stringutils
    PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
target_compile_features(stringutils PUBLIC cxx_std_17)
target_compile_options(stringutils PRIVATE -Wall -Werror -Wextra -Wpedantic)

# Add tests
enable_testing()
add_subdirectory(test)

# Add docs
add_subdirectory(docs)

# Install
include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/stringutils)

install(
    TARGETS stringutils
    EXPORT stringutils-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(
    EXPORT stringutils-targets
    FILE stringutilsTargets.cmake
    NAMESPACE stringutils::
    DESTINATION ${INSTALL_CONFIGDIR})

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/stringutilsConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion)

configure_package_config_file(
    ${CMAKE_CURRENT_LIST_DIR}/cmake/stringutilsConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/stringutilsConfig.cmake
    INSTALL_DESTINATION ${INSTALL_CONFIGDIR})

install(
    FILES
    ${CMAKE_CURRENT_BINARY_DIR}/stringutilsConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/stringutilsConfigVersion.cmake
    DESTINATION ${INSTALL_CONFIGDIR})

export(
    EXPORT stringutils-targets
    FILE ${CMAKE_CURRENT_BINARY_DIR}/stringutilsTargets.cmake
    NAMESPACE stringutils::)

export(PACKAGE stringutils)
