from Qt.Core import QCoreApplication

def unixSignal(number):
    print 'Unix signal:', number
    QCoreApplication.quit()

app = QCoreApplication('')
app.connect('unixSignal(int)', unixSignal)
app.run()

