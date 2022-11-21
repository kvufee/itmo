class Queue:

    class Node:
        def __init__(self, data) -> None:
            self.data = data
            self.next = next

    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0
    
    def __len__(self):
        return self.size

    def empty(self):
        return self.size == 0

    def push(self, data):
        added = self.Node(data, None)

        if self.empty():
            self.head = added
        else:
            self.tail.next = added

        self.tail = added
        self.size += 1

    def pop(self):
        if self.empty():
            return "Error"

        removed = self.head.data
        self.head = self.head.next
        self.size += 1
        
        if self.empty():
            self.tail = None

        return removed


if __name__ == "__main__":
    q = Queue()
    n = int(input())
    ans = []

    for i in range(n):
        s = input()
    
        if "-" in s:
            ans.append(q.pop())
        else:
            num = int(s.split()[1])
            q.push(num)

for i in range(len(ans)):
    print(ans[i], end = "\n")