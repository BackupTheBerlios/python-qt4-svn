
def a(*params):
    print params
    b(*params)

def b(p1, p2, p3):
    print p1, p2, p3
    
a('1', '2', '3')

