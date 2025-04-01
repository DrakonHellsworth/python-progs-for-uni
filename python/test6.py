class shape:
    def __init__(self):
        self.color=(0,0,0)
class rectangle(shape):
    def __init__(self,w,h):
        shape.__init__(self)
        self.width=w
        self.height=h
            
    def area(self):
        return self.width*self.height
            
r1=rectangle(10,5)
print (r1.width)
print (r1.height)
print (r1.color)
print (r1.area())