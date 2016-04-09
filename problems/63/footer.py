
if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        lineItems = [int(l) for l in raw_input().split(" ")]
        a = lineItems[1:]
        s = Solution()
        s.arrange(a)
        for x in a:
            print("{0} ".format(x), end="")
        print("")