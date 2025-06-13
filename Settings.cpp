
#include "Settings.h"
#include <filesystem>

Settings::Settings() {
  // This should eventually read from a config file

  // string root = std::filesystem::current_path().root_path();
  string file = "/Users/joshbaker/install_log.txt";

  logFile = std::filesystem::absolute(path(file));
}

path Settings::getPath() { return logFile; }
