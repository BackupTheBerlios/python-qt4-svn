from Qt.Core import QObject, QTimer, QCoreApplication

count = 0

def timeout():
    global count
    count += 1
    print 'timeout %d'%count
    if count > 5: 
        QCoreApplication.quit()

app = QCoreApplication('timer')
timer = QTimer(None)
timer.interval = 1000
timer.connect('timeout()', timeout)
timer.start()
app.run()

