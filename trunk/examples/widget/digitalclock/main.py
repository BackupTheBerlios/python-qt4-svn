from Qt.Gui import QApplication
from digitalclock import DigitalClock

app = QApplication()
clock = DigitalClock()
clock.show()
app.run()
