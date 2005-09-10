import Qt
print 'Qt:', Qt

from Qt.Gui import QApplication

app = QApplication()
print 'app:', app, app.sessionId()

#app.run()
