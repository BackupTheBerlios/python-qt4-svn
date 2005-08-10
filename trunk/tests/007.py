# QFormBuilder example

from Qt import *

app = QApplication('QFormBuilderExample')
form = loadUi('form.ui', None)
form.show()

listview = form.findChild('nameList')
button = form.findChild('okPushButton')
edit = form.findChild('nameEdit')

print form, dir(form)
print button, dir(button)
print edit, dir(edit)

#for widget in form.children():
#    print 'name:', widget.objectName
#    print 'obj:', widget
    #print 'parent:', widget.parent()
    

app.run()
