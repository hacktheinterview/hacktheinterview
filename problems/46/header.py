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
