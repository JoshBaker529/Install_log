// Settings class
#include <filesystem>
using std::filesystem::path;
#include <string>
using std::string;

// #include <filesystem>
// using namespace std;

class Settings {
public:
  // Methods
  Settings();
  path getPath();

private:
  string logFile;
};
