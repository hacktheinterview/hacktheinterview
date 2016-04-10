

if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        a, b = [int(l) for l in raw_input().split(" ")]
        s = Solution()
        print(s.gcd(a, b))