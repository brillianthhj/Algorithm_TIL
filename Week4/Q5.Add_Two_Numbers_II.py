# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        stackL1 = []
        stackL2 = []

        carry = 0
        
        while l1:
            stackL1.append(l1.val)
            l1 = l1.next

        while l2:
            stackL2.append(l2.val)
            l2 = l2.next

        head = None

        for _ in range(max(len(stackL1), len(stackL2))):
            s1 = s2 = 0
            if len(stackL1) != 0:
                s1 = stackL1.pop()
            
            if len(stackL2) != 0:
                s2 = stackL2.pop()
            
            ans = (s1 + s2 + carry) % 10
            new_node = ListNode(ans)
            new_node.next = head
            head = new_node

            carry = (int)((s1 + s2 + carry) / 10)

        if carry > 0:
            new_node = ListNode(carry)
            new_node.next = head
            head = new_node

        return head


# a = ListNode(7)
# b = ListNode(2)
# c = ListNode(4)
# d = ListNode(3)

# a.next = b
# b.next = c
# c.next = d


# e = ListNode(5)
# f = ListNode(6)
# g = ListNode(4)

# e.next = f
# f.next = g

a = ListNode(5)
e = ListNode(5)

s = Solution()
value = s.addTwoNumbers(a, e)

while value != None:
    print(value.val)
    value = value.next

            
