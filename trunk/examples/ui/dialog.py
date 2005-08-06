############################################################################
#    Copyright (C) 2005 by Eric Jardim                                     #
#    ericjardim@gmail.com                                                  #
#                                                                          #
#    This program is free software; you can redistribute it and/or modify  #
#    it under the terms of the GNU General Public License as published by  #
#    the Free Software Foundation; either version 2 of the License, or     #
#    (at your option) any later version.                                   #
#                                                                          #
#    This program is distributed in the hope that it will be useful,       #
#    but WITHOUT ANY WARRANTY; without even the implied warranty of        #
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         #
#    GNU General Public License for more details.                          #
#                                                                          #
#    You should have received a copy of the GNU General Public License     #
#    along with this program; if not, write to the                         #
#    Free Software Foundation, Inc.,                                       #
#    59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             #
############################################################################

# Dynamic dialog loading

from Qt import QApplication, QWidget, QPushButton, loadUi


class Proxy(object):
    #__ui__ = 'dialog.ui'
    
    def __init__(self, obj):
        pass


class Dialog(QWidget):
    #def __new__(self, other):
    #    #print other
    #    self = loadUi('dialog.ui', None)
        
    def __init__(self, parent=None):
        QWidget.__init__(self, parent)
        self.ui = loadUi('dialog.ui', self)
        for signal in self.ui.__signals__():
            print signal
        
if __name__ == '__main__':
    app = QApplication('Dynamic dialog loading example')
    dialog = Dialog(None)
    #form = loadUi('dialog.ui', None)
    dialog.show()
    #dialog.ui.show()
    app.run()
