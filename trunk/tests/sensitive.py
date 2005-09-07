class signal(object):
    def __init__(self, callback):
        self.callback = callback

    def __call__(self, *args, **kw):
        self.callback(self.callback.im_self, *args, **kw)

class A(object): 
    def __init__(self):
        for a in dir(self):
            if isinstance(getattr(self, a), signal):
	        print self, a, 'is a signal'
	
    #def __setattr__(self, p1, p2):
	#if type(p2)==type(''):
	#    print 'string'


class B(A): 
    #@signal
    def changed(self): pass
    changed = signal(changed) 

print A.__class__
A.lala = 'method1'
print dir(A)

a = A()
a.lala = 'method2'
b = B()
b.lala = 'method2'

b.changed()

