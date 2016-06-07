if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        n = int(raw_input())
        s = Solution()
        result = s.isPalindrome(n)
        print result
