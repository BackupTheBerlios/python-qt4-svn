from Qt import QApplication
from MainForm import MainForm

if __name__ == '__main__':
    app = QApplication('')
    form = MainForm(None)
    form.show()
    app.run()
