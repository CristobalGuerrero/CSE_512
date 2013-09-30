# lab2robot.py

import math
import random

#creates the grid by utilizing a dictionary to make a 10x10 grid
#and returns it to be used
def make_grid(k):
    grid = {}
    i = 1
    for i in range(k):
        for j in range(k):
            grid[ (i,j) ] = '_'
    return grid

#creates an image for the grid though somewhat sloppy some getting
#used to is needed for a better image
def print_grid(grid):
    dimension = int(math.sqrt(len(grid)))
    print('\n')
    for i in range(dimension):
        for j in range(dimension):
                if j < dimension -1:
                    print(grid[(i,j)]),
                else:
                    print(grid[(i,j)])
    print('\n')

#place the robot in the area
def place_robot(r,c):
    grid = make_grid(10)
    grid[(r,c)] = 'R'
    print_grid(grid)
    return grid

#place the object in the area
def place_object():
    grid = place_robot(r,c)
    m = 3
    p = 7
    for n in range(m,p):
        for i in range(m,p):
            grid[(i,n)] = 'x'
    return grid

#move the robot
#in this function we will move the robot by one space each time
def move_robot(command):
    if command == 'u':
        r -= 1
    elif command == 'r':
        c += 1
    else:
        print('wrong input')
grid = make_grid(10)
print_grid(grid)
#for i in range(5):
#    move_robot(raw_input("Enter in a direction: "))
 #   print_grid(grid)

