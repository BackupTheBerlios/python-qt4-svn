##########################
###    Instructions    ###
##########################

# Fill the options with the correct values for your own setup
# Don't use "" or '' around values (unless you know what you're doing)
# Environment variables should be referenced like this:
#    - $(VAR) the variable will bypass to the Makefile, or 
#    - $$(VAR) the variable will be resolve in qmake
# Follow the examples and everything is gonna be alright.
# Any doubt consult:
#    http://doc.trolltech.com/4.0/qmake-advanced-usage.html#variables


##########################
###   Generic Options  ###
##########################

# Can be "release" or "debug"
RUNTIME=debug


##########################
###       Python       ###
##########################

### Python setup
# The prefix where python is installed 
# ex: "/usr", "/usr/local", "/tmp/python" and "/home/eric/python2.4"
PYTHONDIR=/usr

# Python version
PYTHONVER=2.3


##########################
### Boost.Python setup ###
##########################

# The boost.python prefix dir (where you installed it, or where
# your distribution places it)
BOOSTDIR=/usr

# The toolset you compiled boost 
# ex: "-gcc" (Gnu gcc), "-mgw" (MinGW) ...
BOOSTTOOLSET=-gcc

# If you want boost multithread support 
# ex: "-mt" or "" (nothing)
BOOSTTHREADING=-mt

# Runtime, debug or release?
# ex:  "-d" or "" (nothing)
BOOSTRUNTIME=

# Boost version 
# ex: "-1_32", "-1_33" and so on
BOOSTVER=-1_33

