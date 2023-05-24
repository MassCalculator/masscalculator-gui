configure_file(config/software_version.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/include/masscalculator/${PROJECT_NAME}/software_version.h)

# Add path of QML module defined by this project to QML import paths.
set(QML_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/qml" CACHE INTERNAL "QML import directories")

add_executable(${PROJECT_NAME}
  include/masscalculator/masscalculator-gui/backend.h
  src/backend.cc
  src/main.cc
  qml/masscalculator/masscalculator-gui/masscalculator_masscalculator-gui.qrc
)

target_include_directories(${PROJECT_NAME} PRIVATE 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    masscalculator::masscalculator-core
    Qt5::Core
    Qt5::Gui
    Qt5::Network
    Qt5::Qml
    Qt5::Quick
    Qt5::Widgets
)
