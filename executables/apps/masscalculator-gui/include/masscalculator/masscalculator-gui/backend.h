/**
 * @file backend.h
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief @todo(jimmyhalimi): Add brief.
 * @version 0.1
 * @date 2023-05-20
 *
 * @copyright Copyright (c) 2023, MassCalculator, Org., All rights reserved.
 * @license This project is released under the  MIT license (MIT).
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef MASSCALCULATOR_GUI_EXECUTABLES_APPS_MASSCALCULATOR_GUI_BACKEND_H_
#define MASSCALCULATOR_GUI_EXECUTABLES_APPS_MASSCALCULATOR_GUI_BACKEND_H_
#include <masscalculator/masscalculator-core/interface/object_interface.h> // for Object<T, U>
#include <masscalculator/masscalculator-core/materials/alloy_coppers.h> // for AlloyCoppers
#include <masscalculator/masscalculator-core/materials/material.h> // for Material<T>
#include <masscalculator/masscalculator-core/shapes/cylinder.h> // for Cylinder
#include <masscalculator/masscalculator-core/shapes/shape.h>    // for Shape<T>

#include <QObject>     // for QObject
#include <QQmlEngine>  // for QQmlEngine
#include <QStringList> // for QStringList
#include <memory>      // for std::unique_ptr

namespace masscalculator::gui {
/**
 * @brief This class is responsible to creating all the variables needed for
 * MassCalculator functioning
 */
class Backend : public QObject {
  Q_OBJECT

 public:
  /**
   * @brief Construct a new Backend object
   *
   * @param parent
   */
  explicit Backend(QObject* parent = nullptr);

  /**
   * @brief Destroy the Backend object
   */
  ~Backend() override;

  /**
   * @brief Get the Materials object
   *
   * @return Q_INVOKABLE
   */
  Q_INVOKABLE QStringList getMaterials();

  /**
   * @brief Get the Material Types object
   *
   * @return Q_INVOKABLE
   */
  Q_INVOKABLE QStringList getMaterialTypes();

  /**
   * @brief Get the Shapes object
   *
   * @return Q_INVOKABLE
   */
  Q_INVOKABLE QStringList getShapes();

  /**
   * @brief Delete copy constructor
   */
  Backend(const Backend&) = delete;

  /**
   * @brief Delete move constructor
   */
  Backend(Backend&&) = delete;

  /**
   * @brief Delete assignment operator
   */
  Backend& operator=(const Backend&) = delete;

  /**
   * @brief Delete move assignment operator
   */
  Backend& operator=(Backend&&) = delete;

  /**
   * @brief @todo(jimmyhalimi): Add doxy documentation.
   *
   * @param qml_engine
   */
  void Initialize(QQmlEngine* qml_engine = nullptr);

 private:
  std::unique_ptr<masscalculator::core::shapes::Shape<
      masscalculator::core::shapes::Cylinder>>
      shape_;

  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::AlloyCoppers>>
      material_;

  std::unique_ptr<masscalculator::core::interface::Object<
      masscalculator::core::shapes::Shape<
          masscalculator::core::shapes::Cylinder>,
      masscalculator::core::materials::Material<
          masscalculator::core::materials::AlloyCoppers>>>
      object_;
};
} // namespace masscalculator::gui
#endif // MASSCALCULATOR_GUI_EXECUTABLES_APPS_MASSCALCULATOR_GUI_BACKEND_H_
