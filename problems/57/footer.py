
if __name__ == "__main__":
	test_cases = int(raw_input())
	for i in range(test_cases):
		a = raw_input()
		solution = Solution()
		solution.reverseWords(a)
		print(a)
