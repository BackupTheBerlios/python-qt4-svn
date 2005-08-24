from Qt.Core import QTime, QTimer, tr
from Qt.Gui import QLCDNumber 

class DigitalClock(QLCDNumber):
    def __init__(self, parent=None):
        QLCDNumber.__init__(self, parent)
        self.segmentStyle = QLCDNumber.Filled
        timer = QTimer(self)
        timer.connect('timeout()', self.showTime);
        timer.start(1000)
        self.showTime()
        self.windowTitle = tr('Digital Clock')
        self.resize(150, 60)

    def showTime(self):
        time = QTime.currentTime()
        text = time.toString('hh:mm')
        if time.second() % 2 == 0:
            h, m = text.split(':')
            text = '%s %s' % (h, m)
        self.display(text)
