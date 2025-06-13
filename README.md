# INSTALL LOG
Simple logger to keep track of installs via a package manager. 

# In the process of converting to C++ (Simply because I'm more comfortable using it)
```
./install_log.sh [-l] [<package> <description>]
```

using -l lists the file.

Will automatically put it in the format:
```
YYYY-MM-DD <package> <description>
```

By default, saves to ~/.installs.txt 

