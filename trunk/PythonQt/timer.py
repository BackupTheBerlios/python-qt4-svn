from Qt.Core import QTimer
from Qt.Gui import QApplication

app = QApplication('timer')
timer1 = QTimer(None)
timer2 = QTimer(None)
timer1.interval = 1000
timer2.interval = 1000
timer1.connect('timeout()', timer2.start)
timer2.connect('timeout()', app.quit)
timer1.start()
app.run()
print timer1, timer2