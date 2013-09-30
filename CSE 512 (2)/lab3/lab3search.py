#this method imports all with the * sign
from datastructs import *

#Initializes the graph with all the states included in it
#states and the graph can be changed by having it global
Graph = { 'a' : ['b','c'], 'b': ['d'], 'c': ['j'], 'd': ['e','f'],
                  'j': ['d'], 'f': ['g'], 'e': [], 'g': [] }

#checks to see if the state is the goal which would be a
#successful run
def goal_test(state):
    return state == 'g'

#this returns the immediate successors dependent on
#the current state that you are in
def successor_fct(state):
    return Graph[state]

#This searches the state and will later be able to create
#a tree that will help out the program
def graph_search(initstate, openlst):
    #fill in here
    openlst.append(initstate)
    closed = []
    #runs the loop until the open list is empty
    while openlst != [ ] :
        NEXT = openlst.pop()
        closed.append(next)
        
        if goal_test(NEXT):
            return NEXT
        
        SUCCS = successor_fct(NEXT)
        
        for s in SUCCS:
            if not s  in closed and not s in openlst:
                openlst.append(s)
        return None
            
#defines the initial state and the stack as well
def dfs_graph_search(initstate):
    return graph_search(initstate, Stack())

def bfs_graph_search(initstate):
    return graph_search(initstate, FIFOQueue())

