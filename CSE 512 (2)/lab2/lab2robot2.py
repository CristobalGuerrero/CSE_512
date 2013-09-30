# lab2robot.py

import math
import random

# global variable
r = 2
c = 4
Robot=[r,c]

def make_grid(k):
    grid={}
    for i in range(k):
        for j in range(k):
            grid[(i,j)]=0
    return grid

def print_grid(grid):
    dim=int(math.sqrt(len(grid)))
    print('\n')
    for i in range(dim):
        for j in range(dim):
            if j < dim - 1:
                #print(grid[(i,j)]),
                print_cell(grid[(i,j)],1)
            else:
                #print(grid[(i,j)])
                print_cell(grid[(i,j)],0)
    print('\n')

def print_cell(cell,sameline):
    if cell == 0:
        if sameline == 1:
            print('_'),
        else:
            print('_')
    else:
        if sameline == 1:
            print(cell),
        else:
            print(cell)
            
# place robot (R) in cell (r,c);
def place_robot(grid):
    global Robot
    global c
    global r
    Robot=[r,c]
    grid[(r,c)]='R'

def horiz_wall(grid,x,y1,y2):
    for i in range(y1,y2):
        grid[(x,i)]='X'

#place the object in the area
def place_object():
    m = 3
    p = 7
    for n in range(m,p):
        for i in range(m,p):
            grid[(i,n)] = 'x'

def move_robot():
    instance = False
    global Robot
    global c
    global r
    a = r
    b = c
    while instance == False:
        move = random.randint(0,3)
        if move == 0:
            r-=1
            instance  = check_instance()
            if instance == False:
                r+=1
        elif move == 1:
            r+=1
            instance = check_instance()
            if instance == False:
                r-=1
        elif move == 2:
            c+=1
            instance = check_instance()
            if instance == False:
                c-=1
        elif move == 3:
            c-=1
            instance = check_instance()
            if instance == False:
                c+=1
    Robot = [r,c]
    grid[(a,b)] = '_'
    grid[(r,c)] = 'R'

def check_instance():
    global c
    global r
    if c != -1 and c!=10 and r != -1 and r!= 10 and grid[(r,c)] != 'x':
        return True
    else:
        return False
    
    
grid = make_grid(10)
print("10x10 grid defined")
print('\n')
place_robot(grid)
place_object()
print_grid(grid)
for i in range(200): 
    move_robot()
    print_grid(grid)
print("robot placed")
print('\n')


    
