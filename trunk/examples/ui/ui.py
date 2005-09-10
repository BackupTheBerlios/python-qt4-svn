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

# Dynamic UI loading

from Qt.Gui import QApplication, QWidget, QPushButton, loadUi

class Form(QWidget):
    def __init__(self, parent=None):
        QWidget.__init__(self, parent)
        ui = loadUi('form.ui', self)
        print ui.objectName
        print
        children = ui.children()
        for child in children:
            print child, child.objectName

            #child.setParent(self)
            if isinstance(child, QWidget):
                print '    ', child.parentWidget()
                child.setParent(self)
            else:
                print '    ', type(child)
                
        #self.ui = loadUi('form.ui', self)
        #for signal in self.__signals__():
        #    print signal
        

app = QApplication()
form = Form(None)
#form = loadUi('form.ui', None)
form.show()
app.run()


#for widget in form.ui.children():
#    print widget
#print form.ui
