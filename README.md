# INSTALL LOG
Simple logger to keep track of installs via a package manager. 

NOTE: install_log.sh is a simple bash script that allows for the addition and listing of packages, but is unable to remove items from the list. 

# Installation
## Requirements:
Some sort of C++ compiler. My make file uses g++, any others will have to be manually changed in the make file (or compile by hand).

## Steps
Simply download the repository in some form, navigate to the folder, and run the command `make`.
This will build the executable named `log` in the directory.

# Usage
The default command is ` ./log <package name> <description> `. This will add an entry to the log file with the format `YYYY/MM/DD <package name>: <description>`. 

## Modifiers
`-h`: Shows the help menu.
`-l`: Prints entire log file to console.
`-r <package name>`: Removes a package from the log.
`-o`: Skips any checks for flags, and follows the same format as the default command (For the extremely slim chance a package has the same name as one of the modifiers).

The log file is stored in `~/install_log.txt`, if manual modification of the file is required.

