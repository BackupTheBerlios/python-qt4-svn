from Qt.Gui import QApplication
from digitalclock import DigitalClock

app = QApplication('digitalclock')
clock = DigitalClock()
clock.show()
app.run()
