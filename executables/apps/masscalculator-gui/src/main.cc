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

  masscalculator::gui::Backend masscalculator_backend;

  QQmlApplicationEngine app_engine;
  app_engine.addImportPath(kQrcPrefix);

  masscalculator_backend.Initialize(&app_engine);

  app_engine.load(QString(kQrcPrefix) + kQrcAppPrefix + "main.qml");

  return app.exec();
}
