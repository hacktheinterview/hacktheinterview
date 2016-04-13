

if __name__ == "__main__":
	test_cases = int(raw_input())
	for i in range(test_cases):
		n = int(raw_input())
		a = []
		for i in range(n):
			a.append([int(l) for l in raw_input().split(" ")])
		solution = Solution()
		result = solution.diagonal(a)
		for r in result:
			for x in r:
				print(str(x) + " ", end="")
			print("")
