// This is essentially the same thing as the install_log.sh, but written in C++
// for ease of access

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
using std::cout;
#include <fstream>
using std::ifstream, std::ofstream;
#include "Settings.h"
#include <ctime>

struct Entry {};

int main(int argc, char *argv[]) {

  // cout << "Date: " << date.tm_mon + 1 << "/" << date.tm_mday << "/"
  //    << date.tm_year + 1990 << "\n";

  // No args
  if (argc == 1) {
    cout << "Usage: " << argv[0]
         << " [-h|-l|-r|-o] <package name> <description>\n"
            "For more information, use: "
         << argv[0] << " -h";
    return 0;
  }

  // There is at least one arg

  if (strcmp(argv[1], "-h") == 0) {
    cout << "Default usage: " << argv[0] << " <package name> <description>\n";
    cout << "Options:\n"
            "\t-h\tShows help menu\n\n"
            "\t-l\tLists all entries\n\n"
            "\t-r\tRemoves an entry\n"
            "\t\tArguments: <package name>\n\n"
            "\t-o\tForce adds to list "
            "(for the extremely slim chance a package has the same name as an "
            "option)\n"
            "\t\tArguments: <package name> <description>\n";
    return 0;
  }

  // Auto loads settings
  Settings settings;

  if (strcmp(argv[1], "-l") == 0) {
    ifstream inFile;
    inFile.open(settings.getPath());

    if (!inFile) {
      cout << "Error loading file";
      return -1;
    }

    string line;
    while (!inFile.eof()) {
      std::getline(inFile, line, '\n');
      cout << line << "\n";
    }
    inFile.close();
    return 0;
  }

  if (strcmp(argv[1], "-r") == 0) {
    if (argc != 3) {
      cout << "Usage: " << argv[0] << "-r <package name>";
    }
    ifstream inFile;
    inFile.open(settings.getPath());
    if (!inFile) {
      cout << "Error loading file";
      return -1;
    }
    std::stringstream sstream;
    string date, name, desc, line;

    while (!inFile.eof()) {
      std::getline(inFile, line);
      sstream << line << "\n";
    }
    inFile.close();

    ofstream outFile;
    outFile.open(settings.getPath());
    if (!outFile) {
      cout << "Error loading file";
      return -1;
    }
    bool found = false;
    while (sstream >> date >> name) {
      std::getline(sstream, desc);
      name[name.length() - 1] = '\0';
      if (std::strcmp(name.c_str(), argv[2]) == 0) {
        found = true;
        continue;
      }
      outFile << date << " " << name << ":" << desc << "\n";
    }

    if (found) {
      cout << argv[2] << " removed from log.";
    } else {
      cout << argv[2]
           << " not found. Please make sure the package name is correct.";
    }

    outFile.close();
    return 0;
  }

  // Code for getting the date in MM/DD/YYYY format
  time_t timestamp = time(NULL);
  struct tm datetime = *localtime(&timestamp);
  char date[11];
  std::strftime(date, 11, "%m/%d/%Y", &datetime);

  if (strcmp(argv[1], "-o") == 0) {

    ofstream outFile;
    outFile.open(settings.getPath(), std::ios::app);
    if (!outFile) {
      cout << "Error loading file";
      return -1;
    }
    outFile << date << " " << argv[2] << ": ";
    for (int i = 3; i < argc; i++) {
      outFile << argv[i] << " ";
    }
    outFile << "\n";
    outFile.close();

    return 0;
  }

  // At this point, we don't have any arguments

  ofstream outFile;
  outFile.open(settings.getPath(), std::ios::app);
  if (!outFile) {
    cout << "Error loading file";
    return -1;
  }
  outFile << date << " " << argv[1] << ": ";
  for (int i = 2; i < argc; i++) {
    outFile << argv[i] << " ";
  }
  outFile << "\n";
  outFile.close();

  return 0;
}
