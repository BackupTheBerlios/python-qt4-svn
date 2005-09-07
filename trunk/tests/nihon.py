# -*- coding: utf-8 -*-

import Qt
app=Qt.Gui.QApplication("demo")
text = u"日本語のpython-qt4"
button=Qt.Gui.QPushButton(text)
assert text == button.text
button.show()
app.run()
