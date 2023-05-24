# Include the default CMAKE_INSTALL_LIBDIR and CMAKE_INSTALL_INCLUDEDIR values.
include(GNUInstallDirs)

############################################################
# INSTALL MASSCALCULATOR-GUI BINARY
############################################################

# Install the library targets and their corresponding headers
install(
  TARGETS
    ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}-config
  RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_BINDIR}
)

install(
  DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/masscalculator-gui/include/masscalculator
  DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}
  FILES_MATCHING PATTERN "*.h*"
  PATTERN "CMakeLists.txt" EXCLUDE
)

install(
  FILES ${CMAKE_SOURCE_DIR}/docs/assets/man/masscalculator-cli.1.gz
  DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_MANDIR}/man1
  COMPONENT ${PROJECT_NAME}
)
