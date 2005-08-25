import sys
print sys.argv

import Qt
print 'Qt:', Qt
print 'dir(Qt):', dir(Qt)

from Qt import QApplication
app = QApplication('')
print 'app:', app, app.sessionId()
print 'dir(app):', dir(app)
#app.run()


