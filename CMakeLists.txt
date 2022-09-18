# Copyright (c) Microsoft Corporation.
# Licensed under the MIT License.
cmake_minimum_required(VERSION 3.10.2)
project(libelf
    LANGUAGES C
    VERSION 0.187
)

add_subdirectory(src)

if (LIBELF_INSTALL)
    # Install the targets
    install(TARGETS DirectX-Headers DirectX-Guids
            EXPORT DirectX-Headers-Targets
            ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
    # Create the targets CMake file which contains the above definitions
    install(EXPORT DirectX-Headers-Targets FILE directx-headers-targets.cmake
            NAMESPACE Microsoft::
            DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/directx-headers/cmake)

    # Install the actual includes
    install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/"
            DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

    # Create the CMake config files
    include(CMakePackageConfigHelpers)
    write_basic_package_version_file("directx-headers-config-version.cmake"
                                    VERSION ${PROJECT_VERSION}
                                    COMPATIBILITY SameMajorVersion)
    configure_package_config_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/directx-headers-config.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/directx-headers-config.cmake"
        INSTALL_DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/directx-headers/cmake)

    # Install the CMake config files
    install(FILES "${CMAKE_CURRENT_BINARY_DIR}/directx-headers-config.cmake"
                "${CMAKE_CURRENT_BINARY_DIR}/directx-headers-config-version.cmake"
            DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/directx-headers/cmake)
endif()
