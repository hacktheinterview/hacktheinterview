

if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        a = int(raw_input())
        s = Solution()
        print(s.trailingZeroes(a))