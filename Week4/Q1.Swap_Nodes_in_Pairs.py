# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def swapPairs(self, head):
        temp = ListNode(0)
        temp.next = head
        pre = temp
        cur = head

        while cur and cur.next:
            pre.next = cur.next
            pre = pre.next
            cur.next = pre.next
            pre.next = cur
            pre = cur
            cur = cur.next

        return temp.next

s = Solution()

a = ListNode(1)
b = ListNode(2)
c = ListNode(3)
d = ListNode(4)
e = None

a.next = b
b.next = c
c.next = d
d.next = e

result = s.swapPairs(a)

while result != None:
    print(result.val)
    result = result.next