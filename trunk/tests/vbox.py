from Qt.Gui import QApplication, QWidget, QVBoxLayout, QPushButton

app = QApplication('')

window = QWidget(None)
button1 = QPushButton("One")
button2 = QPushButton("Two")
button3 = QPushButton("Three")
button4 = QPushButton("Four")
button5 = QPushButton("Five")

layout =  QVBoxLayout()
layout.addWidget(button1)
layout.addWidget(button2)
layout.addWidget(button3)
layout.addWidget(button4)
layout.addWidget(button5)

window.setLayout(layout)
window.show()
app.run()