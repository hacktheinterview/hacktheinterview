class Solution:
    result = []

    def preorder(self, root):
        if not root:
            return
        self.result.append(root.val)
        self.preorder(root.left)
        self.preorder(root.right)


    def preorderTraversal(self, root):
        # Implement the solution here
        self.result = []
        self.preorder(root)
        return self.result
