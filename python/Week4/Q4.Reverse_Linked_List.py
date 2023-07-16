# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev = None
        curr = head
        
        while curr != None:
            nextTemp = curr.next
            curr.next = prev
            prev = curr
            curr = nextTemp
            
        return prev

    
a = ListNode(1)
b = ListNode(2)
c = ListNode(3)
d = ListNode(4)
e = None

a.next = b
b.next = c
c.next = d
d.next = e

s = Solution()
value = s.reverseList(a)


while value != None:
    print(value.val)
    value = value.next