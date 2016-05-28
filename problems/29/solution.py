class BinaryTreeDeserializer:
    def __init__(self, tokens):
        self.tokens = tokens

    def _deserialize(self, index):
        if index >= len(self.tokens):
            return None, index

        val = self.tokens[index]
        nextIndex = index + 1
        if val == "#":
            return None, index + 1

        root = TreeNode(int(self.tokens[index]))
        root.left, nextIndex = self._deserialize(nextIndex)
        root.right, nextIndex = self._deserialize(nextIndex)
        return root, nextIndex + 1

    def deserialize(self):
        root, index = self._deserialize(0)
        return root

class BinaryTree:
    def __init__(self):
        self.root = None

    def _inorder(self, root):
        if not root:
            return
        self._inorder(root.left)
        print root.val,
        self._inorder(root.right)

    def inorder(self):
        self._inorder(self.root)

    def constructFromTokens(self, tokens):
        d = BinaryTreeDeserializer(tokens)
        self.root = d.deserialize()

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


class Solution:
    def isBST(self, root, mini, maxi):
        if not root:
            return 1

        if root.val < mini or root.val > maxi:
            return 0

        return self.isBST(root.left, mini, root.val - 1) and self.isBST(root.right, root.val + 1, maxi)

    def isValidBinarySearchTree(self, root):
        # Implement the solution here
        INTEGER_MIN = -(1<<31) + 1
        INTEGER_MAX = (1<<31) - 1
        return self.isBST(root, INTEGER_MIN, INTEGER_MAX)

if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        lineItems = [l for l in raw_input().split(" ")]
        tokens = lineItems[1:]

        T = BinaryTree()
        T.constructFromTokens(tokens)
        s = Solution()
        result = s.isValidBinarySearchTree(T.root)
        print result
