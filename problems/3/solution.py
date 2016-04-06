class Solution:

    def isPalindromeUtil(self, left, right):
        # return <sub list result, current node we are checking>
        if not right:
            return 1, left
        #print "left, right ", left.val, right.val

        ret, left = self.isPalindromeUtil(left, right.next)
        if not ret:
            return 0, left

        ret = 1 if right.val == left.val else 0
        left = left.next
        return ret, left

    def isPalindromicList(self, head):
        ret, left = self.isPalindromeUtil(head, head)
        return ret
