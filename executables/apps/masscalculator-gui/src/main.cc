/**
 * @file main.cc
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
#include <masscalculator/masscalculator-base/software_version.h> // for GetVersion

#include <QGuiApplication>       // for QGuiApplication
#include <QQmlApplicationEngine> // for QQmlApplicationEngine

#include "masscalculator/masscalculator-gui/backend.h"          // for Backend
#include "masscalculator/masscalculator-gui/software_version.h" // for GetVersion

namespace {
constexpr auto kQrcPrefix{"qrc:/"};
constexpr auto kQrcAppPrefix{"masscalculator/masscalculator-gui/"};
} // namespace

int main(int argc, char** argv) {
  QGuiApplication app(argc, argv);

  std::cout << masscalculator::base::GetVersion() << std::endl;
  std::cout << masscalculator::gui::GetVersion() << std::endl;

  masscalculator::gui::Backend masscalculator_backend;

  QQmlApplicationEngine app_engine;
  app_engine.addImportPath(kQrcPrefix);

  masscalculator_backend.Initialize(&app_engine);

  app_engine.load(QString(kQrcPrefix) + kQrcAppPrefix + "main.qml");

  return app.exec();
}
