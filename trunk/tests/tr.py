def translate(context, text):
    print context, text

def tr(text):
    import sys, os
    # get the calling filename
    try:
        f = sys._getframe(1)   
	#print f, dir(f)
	for p in dir(f):
	    print p+': '+str(getattr(f, p))
        filename = f.f_code.co_filename
    finally:
        del f

    # extract directory and extension
    context = os.path.basename(os.path.splitext(filename)[0])
    return translate(context, text)

# Installs the tr function as "_" in the builtin namespace.
import __builtin__
__builtin__.tr = tr

tr('Eric Jardim')


