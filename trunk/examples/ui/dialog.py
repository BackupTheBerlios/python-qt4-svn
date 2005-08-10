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

from Qt import QApplication, QWidget, QPushButton, loadUi, QGridLayout, QVBoxLayout
import Qt


class Dialog(QWidget):
    def __init__(self, parent=None):
        #self.ui = loadUi('dialog.ui', parent)
        QWidget.__init__(self, parent)
        #self.visible = False
        self.ui = loadUi('dialog.ui', self)
        
        #self.ui = QPushButton('Eric', self)
        #layout = QVBoxLayout(None)
        #layout.addWidget(self.ui)
        
        #self.setFocusProxy(self.ui)
        #layout.addWidget(self.ui, 0, 0)
        #print self.focusProxy()
        
        #self.setLayout(layout)
        #print self.layout()
        #layout.setEnabled(False)
        #layout.setEnabled(True)
        
        #for signal in self.ui.__signals__():
        #    print signal


if __name__ == '__main__':
    app = QApplication('Dynamic dialog loading example')
    dialog = Dialog(None)
    dialog.show()
    app.run()
