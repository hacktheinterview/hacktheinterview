class Solution:
    result = []

    def postorder(self, root):
        if not root:
            return

        self.postorder(root.left)
        self.postorder(root.right)
        self.result.append(root.val)

    def postorderTraversal(self, root):
        # Implement the solution here
        self.result = []
        self.postorder(root)
        return self.result
