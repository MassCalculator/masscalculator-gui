import QtQuick 2.15

/**
* This file is the entry point for the MassCalculator GUI app.
*/
QtObject {
  id: root

  property var mainWindow: MainWindow {
    id: mainWindow

    title: "MassCalculator GUI Application"
    width: 1920
    height: 1080
  }
}
