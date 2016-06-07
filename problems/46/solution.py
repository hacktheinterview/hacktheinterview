import sys
import cStringIO

class BinaryTreeSerializer:
    def __init__(self, root):
        self.root = root

    def _serialize(self, root, output):
        if not root:
            output.write("# ")
            return
        output.write(root.val)
        output.write(" ")
        self._serialize(root.left, output)
        self._serialize(root.right, output)

    def serialize(self):
        output = cStringIO.StringIO()
        self._serialize(self.root, output)
        result = output.getvalue()
        print result[:-1]

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

    def printTreeToOutputFormat(self):
        x = BinaryTreeSerializer(self.root)
        x.serialize()

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


class Solution:
    # @param preorder, a list of integers
    # @param inorder, a list of integers
    # @return a tree node
    def bst(self, preorder, inorder):
        if len(preorder) == 0 or len(inorder) == 0:
            return None
        root = TreeNode(preorder[0])
        idx = inorder.index(preorder[0])
        preorder.pop(0)
        root.left = self.bst(preorder, inorder[0:idx])
        root.right = self.bst(preorder, inorder[idx+1:])
        return root


    def constructBinaryTree(self, preorder, inorder):
        return self.bst(preorder, inorder)

if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        lineItems = [l for l in raw_input().split(" ")]
        n = int(lineItems[0])
        preorder = lineItems[1:(n + 1)]
        inorder = lineItems[(n + 1):]

        s = Solution()
        root = s.constructBinaryTree(preorder, inorder)
        T = BinaryTree()
        T.root = root
        T.printTreeToOutputFormat()
