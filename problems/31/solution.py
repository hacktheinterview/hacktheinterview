class Solution:
    def isMirror(self, root1, root2):
        if not root1 and not root2:
            return 1

        if root1 and root2 and root1.val == root2.val:
            x = self.isMirror(root1.left, root2.right)
            x += self.isMirror(root1.right, root2.left)
            return 1 if x == 2 else 0

        return 0

    def isSymmetric(self, root):
        return self.isMirror(root, root)
