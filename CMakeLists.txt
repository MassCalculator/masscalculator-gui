cmake_minimum_required(VERSION 3.15)

################################################################################
#
# Project definition
#
################################################################################

# Define the project
project(masscalculator-gui
        VERSION 0.1.0
        HOMEPAGE_URL "https://github.com/MassCalculator/masscalculator-gui"
        DESCRIPTION "masscalculator-gui app executable"
        LANGUAGES CXX
)

# Set C and C++ standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the project version.
set(MASSCALCULATOR_GUI_NAME ${PROJECT_NAME})
set(MASSCALCULATOR_GUI_VERSION ${PROJECT_VERSION})
set(MASSCALCULATOR_GUI_MAJOR ${PROJECT_VERSION_MAJOR})
set(MASSCALCULATOR_GUI_MINOR ${PROJECT_VERSION_MINOR})
set(MASSCALCULATOR_GUI_PATCH ${PROJECT_VERSION_PATCH})

# @todo(jimmyhalimi): Add a description
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

################################################################################
#
# Additional CMake functionalities
#
################################################################################

# Additional CMake modules are added here to allow finding libraries not
# natively supported by CMake and to be able to include CMake files
# uder third_party/ redirectly.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
  "${CMAKE_SOURCE_DIR}/cmake"
  "${CMAKE_SOURCE_DIR}/third_party"
)

# Initialize the package manager.
include(conan)

# Search for all third party dependencies
include(third_party)

################################################################################
#
# CMake targets definition
#
################################################################################

if(${BUILD_DOCS})
  # This adds the doxygen documentation.
  add_subdirectory(docs)
endif()

# This adds the executables for this project.
add_subdirectory(executables)

# This adds the compile flags.
target_compile_options(${PROJECT_NAME} PRIVATE -O2 -Wall -Wextra -Werror)

# This adds the linker flags.
target_link_options(${PROJECT_NAME} PRIVATE -flto)

################################################################################
#
# Installation and Deployment
#
################################################################################

include(install)

# This adds the packaging steps.
# @todo(jimmyhalimi): Commented out for now, until time comes to fix this.
# include(pack-cpack)

if(${BUILD_RELEASE})
  # @todo(jimmyhalimi): Commented out for now, until time comes to fix this.
  # include(deploy)
endif()

# Set QML import paths for Qt Creator to find QML modules
set(QML_IMPORT_PATH "${QML_DIRS}" CACHE STRING "Qt Creator QML import paths" FORCE)
