from Qt.Gui import QApplication, QFont, QPushButton
from sys import argv

app = QApplication()
quit = QPushButton("Quit", None)
quit.resize(100, 30)
quit.setFont(QFont('Times', 18, QFont.Bold));
quit.connect('clicked()', app.quit);
quit.show()
app.run()
