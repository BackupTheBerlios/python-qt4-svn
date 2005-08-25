# parent test

from Qt.Gui import QApplication, QPushButton, QWidget
app = QApplication('app')
form = QWidget()
okButton = QPushButton('Push me', form)
cancelButton = QPushButton('Push me', form)

okButton.show()
cancelButton.show()
form.show()

app.run()
