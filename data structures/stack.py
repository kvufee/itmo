class Node:
    def __init__(self, data = None, next = None):
        self.data = data
        self.next = next

class Stack:
    
    def __init__(self):
        self.head = None
    
    def push(self, data):
        node = Node(data)
        node.next = self.head
        self.head = node
    
    def pop(self):
        if self.head is None:
            return 
        item = self.head.data
        self.head = self.head.next
        return item

    def top(self):
        if self.head is None:
            return
        item = self.head.data
        return item
    
 
stack = Stack()
n = int(input())
ans = []

for i in range(n):
    s = input()

    if "+" in s:
        item = s.split()[1]
        stack.push(item)
    else:
        ans.append(stack.pop())

for i in range(n):
    print(ans[i], end="\n")