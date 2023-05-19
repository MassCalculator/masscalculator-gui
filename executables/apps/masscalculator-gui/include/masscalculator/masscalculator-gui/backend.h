/**
 * @file backend.h
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief @todo(jimmyhalimi): Add brief.
 * @version 0.1
 * @date 2023-05-19
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
#include <QObject>    // for QObject
#include <QQmlEngine> // for QQmlEngine

namespace masscalculator::gui {

/**
 * @brief This class is responsible to creating all the variables needed for
 * MassCalculator functioning
 */
class Backend : public QObject {
  Q_OBJECT
  // Add properties, signals, and slots as needed

 public:
  explicit Backend(QObject* parent = nullptr);
  ~Backend() override;

  /// No copying nor moving
  Backend(const Backend& other) = delete;
  Backend& operator=(const Backend& other) = delete;
  Backend(Backend&& other) = delete;
  Backend& operator=(Backend&& other) = delete;

  // Initialize the Backend
  void Initialize(QQmlEngine* qml_engine = nullptr);

 private:
  bool video_visible_{false};
};
} // namespace masscalculator::gui
#endif // MASSCALCULATOR_GUI_EXECUTABLES_APPS_MASSCALCULATOR_GUI_BACKEND_H_
