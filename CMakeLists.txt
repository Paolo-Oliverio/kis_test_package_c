# This is the standard template for a KIS SDK package.

# 1. Boilerplate to setup the build environment.
# This script handles finding or fetching `kis_build_system` in standalone mode.
cmake_minimum_required(VERSION 3.20)
include(cmake/package_setup.cmake)

# 2. Load package metadata (name, version, dependencies).
include(kis.package.cmake)
project(${PACKAGE_NAME} VERSION ${PACKAGE_VERSION})

# 3. Handle first-party dependencies (other kis_ packages).
kis_handle_first_party_dependencies()

# ==============================================================================
#           PACKAGE DEFINITION BASED ON LIBRARY TYPE
# ==============================================================================

# --- Configuration for a standard compiled library ---

# 3. Define the library target with its source files.
# You can use the simpler positional form: kis_add_library(<name> <sources...>)
# or the explicit named form: kis_add_library(TARGET <name> SOURCES <files...>)
kis_add_library(${PACKAGE_NAME}
    main/src/${PACKAGE_NAME}.cpp
)

# 4. Apply standard SDK build settings (warnings, C++ standard, etc.).
kis_apply_sdk_build_settings_to_target(${PACKAGE_NAME})

# 5. Add platform-specific source files and include directories from `main/platform/<tag>`.
kis_add_platform_specializations(${PACKAGE_NAME})

# 6. Define public include directories.
target_include_directories(${PACKAGE_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/main/include>
    $<INSTALL_INTERFACE:include>
)

# 7. Link to other dependencies.
kis_link_dependencies(TARGET ${PACKAGE_NAME} PUBLIC kis::kis_test_package_b)

# 8. Install the package artifacts (library, headers, CMake config).
kis_install_package()

# 9. Install any public assets. This applies to both library types.
kis_install_assets()

# 10. (Optional) Define tests, samples, etc.
add_subdirectory(secondary)