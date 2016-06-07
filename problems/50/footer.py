if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        listItems = [str(item) for item in raw_input().split(" ")]
        a = int(listItems[0])
        b = int(listItems[1])
        s = Solution()
        result = s.divide(a, b)
        print result
