from Qt.Gui import QApplication, QWidget, QPushButton, QHBoxLayout

app = QApplication()

def create():
    window = QWidget()
    button1 = QPushButton("One")
    button2 = QPushButton("Two")
    button3 = QPushButton("Three")
    button4 = QPushButton("Four")
    button5 = QPushButton("Five")
    
    layout = QHBoxLayout()
    layout.addWidget(button1)
    layout.addWidget(button2)
    layout.addWidget(button3)
    layout.addWidget(button4)
    layout.addWidget(button5)
    
    window.setLayout(layout)
    window.show()
    return window

window = create()    
app.run()