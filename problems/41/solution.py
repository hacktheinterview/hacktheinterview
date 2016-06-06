import sys
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
        return root, nextIndex

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
    def levelOrder(self, root):
        return []

def print2DVector(result):
    sys.stdout.write("[")
    if result:
        for row in result:
            sys.stdout.write("[")
            for elem in row:
                sys.stdout.write(elem)
                sys.stdout.write(",")
            sys.stdout.write("]")
    sys.stdout.write("]")
    sys.stdout.flush()
    print

if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        lineItems = [l for l in raw_input().split(" ")]
        tokens = lineItems[1:]
        T = BinaryTree()
        T.constructFromTokens(tokens)
        s = Solution()
        result = s.levelOrder(T.root)
        print2DVector(result)
