from Qt.Gui import QApplication, QFont, QPushButton, QWidget

app = QApplication('t3')
window = QWidget()
window.resize(200, 120);
quit = QPushButton ('Quit', window)
quit.setFont(QFont('Times', 18, QFont.Bold))
quit.setGeometry(10, 40, 180, 40)
quit.connect('clicked()', app.quit)
window.show()
app.run()
