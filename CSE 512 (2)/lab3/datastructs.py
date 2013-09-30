# datastructs.py
# by KV, inspired by AIMA Python file utils.py


class Queue:
    def __init__(self):
        abstract

    def extand(self, items):
        for x in items: self.append(item)

def Stack():
    return []

class FIFOQueue(Queue):
    def __init__(self):
        self.Q = []
        self.start = 0
    def append(self, item):
        self.Q.append(item)
    def __len__(self):
        return len(self.Q) - self.start
    def extend(self, items):
        self.Q.extend(items)
    def pop(self):
        elm = self.Q[self.start]
        self.start += 1
        if self.start > 5 and self.start > len(self.Q)/2:
            self.Q = self.Q[self.start:]
            self.start = 0
        return elm
    
