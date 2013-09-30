print "Hello"
the_world_is_flat = 1
if the_world_is_flat:
    print "Be careful not to fall off!"
def fib(n):     #writes out the fibonacci serries up to n
    a, b = 0, 1
    while b < n:
        print b,
        a, b = b,  a+b

fib(100)

n =m = t = 1
print '\n', n
print m
print t, '\n'


word = 'Some word that has stuff'
print word[5:10], '\n'

a = [ 'item', 'object', 27, 4]
print a
b = len(a)
print b

c = int(raw_input("Please enter an integer: "))
if c == 1:
       print 'c is equal to 1'
elif c == 2:
       print 'c is equal to 2'
else:
        print 'c is equal to', c

for i in range(len(a)):
    print i, a[i]
