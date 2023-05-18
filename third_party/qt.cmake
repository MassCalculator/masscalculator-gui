cmake_minimum_required(VERSION 3.15)

set(QT_REQUIRED_VERSION 5.15.8)

# @todo(jimmyhalimi): Update the list for required components.
set(QT_REQUIRED_COMPONENTS
  Core
  Multimedia
  Qml
  Quick
  Widgets
)

# Check that Qt is installed in the system.
# This call cannot fail.
find_package(Qt5 ${QT_REQUIRED_VERSION} REQUIRED 
  COMPONENTS ${QT_REQUIRED_COMPONENTS} CONFIG
)
