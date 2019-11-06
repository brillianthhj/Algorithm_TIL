# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class BSTIterator:

    def __init__(self, root: TreeNode):
        self.stack = []
        self.stack_leftmost_value(root)
        
    def stack_leftmost_value(self, root):
        while root:
            self.stack.append(root)
            root = root.left

    def next(self) -> int:
        """
        @return the next smallest number
        """
        node = self.stack.pop()
        
        if node.right:
            self.stack_leftmost_value(node.right)
            
        return node.val
        

    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        return len(self.stack) > 0


root = TreeNode(7)
n3 = TreeNode(3)
n15 = TreeNode(15)
n9 = TreeNode(9)
n20 = TreeNode(20)

root.left = n3
root.right = n15
n15.left = n9
n15.right = n20

obj = BSTIterator(root)
print(obj.next())
print(obj.next())
print(obj.next())
print(obj.next())
print(obj.next())
print(obj.hasNext())