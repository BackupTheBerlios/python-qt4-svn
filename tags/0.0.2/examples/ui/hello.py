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

# Hello World

from Qt.Gui import QApplication, QPushButton

class MyButton(QPushButton):
    def __init__(self,  text=None, parent=None):
       QPushButton.__init__(self, text, parent)
       self.objectName = 'button'
       self.connect("clicked()", self.on_button_clicked)

    def event(self, event):
        print event
        
    def eventFilter(self, obj, event):
        print obj, event
       
    def on_button_clicked(self):
        print 'Hello, World!'
       
app = QApplication('Hello World example')
button = MyButton('Click me')
button.show()
app.run()

