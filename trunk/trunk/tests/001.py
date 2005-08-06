import Qt
print 'Qt:', Qt

from Qt import QApplication

app = QApplication('')
print 'app:', app, app.sessionId()

#app.run()
