import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

/**
* MassCalculator GUI Main Window
*/
Window {
  id: root

  width: 1920
  height: 1080
  visible: true
  title: "MassCalculator GUI Application"
  color: "#1B1E23"

  ComboBox {
    id: material
    x: 50
    y: 50
    width: 200
    currentIndex: (model.length - 1)
    model: backend.getMaterials()

    onCurrentIndexChanged: {
      var selectedOption = model[currentIndex]
      console.log("Selected material:", selectedOption)
    }
  }

  ComboBox {
    id: material_type
    x: 300
    y: 50
    width: 200
    currentIndex: (model.length - 1)
    model: backend.getMaterialTypes()

    onCurrentIndexChanged: {
      var selectedOption = model[currentIndex]
      console.log("Selected material type:", selectedOption)
    }
  }

  ComboBox {
    id: shape
    x: 550
    y: 50
    width: 200
    currentIndex: (model.length - 1)
    model: backend.getShapes()

    onCurrentIndexChanged: {
      var selectedOption = model[currentIndex]
      console.log("Selected shape:", selectedOption)
    }
  }
}
