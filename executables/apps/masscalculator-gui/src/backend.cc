/**
 * @file backend.cc
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
#include "masscalculator/masscalculator-gui/backend.h" // for Backend

#include <masscalculator/masscalculator-core/interface/object_interface.h> // for Object<T, U>
#include <masscalculator/masscalculator-core/materials/alloy_coppers.h> // for AlloyCoppers
#include <masscalculator/masscalculator-core/materials/constants/alloy_coppers.h> // for alloycopper::k*
#include <masscalculator/masscalculator-core/materials/material.h>
#include <masscalculator/masscalculator-core/shapes/cylinder.h> // for Cylinder

#include <QQmlContext> // for QQmlContext
#include <QQmlEngine>  // for QQmlEngine
#include <QStringList> // for QStringList
#include <memory>      // for std::make_unique

namespace masscalculator::gui {
Backend::Backend(QObject* parent) : QObject(parent) {}

void Backend::Initialize(QQmlEngine* qml_engine) {
  shape_ =
      std::make_unique<masscalculator::core::shapes::Cylinder>(0.1_m, 0.2_m);

  material_ = std::make_unique<masscalculator::core::materials::AlloyCoppers>(
      masscalculator::core::materials::constants::alloycopper::k194Iron);

  object_ = std::make_unique<masscalculator::core::interface::Object<
      masscalculator::core::shapes::Shape<
          masscalculator::core::shapes::Cylinder>,
      masscalculator::core::materials::Material<
          masscalculator::core::materials::AlloyCoppers>>>(shape_, material_);

  // Set QQMLContext properties
  qml_engine->rootContext()->setContextProperty("backend", this);
}

Backend::~Backend() = default;

Q_INVOKABLE QStringList Backend::getMaterials() {
  QStringList list;

  for (int type_id = static_cast<int>(
           masscalculator::core::materials::AlloyCoppers::Type::kBegin);
       type_id <=
       static_cast<int>(
           masscalculator::core::materials::AlloyCoppers::Type::kEnd);
       ++type_id) {
    list.push_back(QString::fromStdString(
        masscalculator::core::materials::AlloyCoppers::kTypeString
            .at(static_cast<
                masscalculator::core::materials::AlloyCoppers::Type>(type_id))
            .data()));
  }

  return list;
}

Q_INVOKABLE QStringList Backend::getMaterialTypes() {
  QStringList list;

  for (int type_id = static_cast<int>(
           masscalculator::core::materials::AlloyCoppers::Type::kBegin);
       type_id <=
       static_cast<int>(
           masscalculator::core::materials::AlloyCoppers::Type::kEnd);
       ++type_id) {
    list.push_back(QString::fromStdString(
        masscalculator::core::materials::AlloyCoppers::kTypeString
            .at(static_cast<
                masscalculator::core::materials::AlloyCoppers::Type>(type_id))
            .data()));
  }

  return list;
}

Q_INVOKABLE QStringList Backend::getShapes() {
  QStringList list;

  for (int type_id = static_cast<int>(
           masscalculator::core::shapes::Cylinder::Type::kBegin);
       type_id <=
       static_cast<int>(masscalculator::core::shapes::Cylinder::Type::kEnd);
       ++type_id) {
    list.push_back(QString::fromStdString(
        masscalculator::core::materials::AlloyCoppers::kTypeString
            .at(static_cast<
                masscalculator::core::materials::AlloyCoppers::Type>(type_id))
            .data()));
  }

  return list;
}
} // namespace masscalculator::gui
