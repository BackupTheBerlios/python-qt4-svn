# automated script

INCDIR=/usr/include/qt4
#INCDIR=$(org)qt4/include

pyste.py --module=$1 -I$INCDIR  $1.py

#pyste.py --module=Qt --multiple -I /usr/include/qt4 $$
