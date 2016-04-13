

if __name__ == "__main__":
	test_cases = int(raw_input())
	for i in range(test_cases):
		A = int(raw_input())
		solution = Solution()
		result = solution.generateMatrix(A)
		for r in result:
			for x in r:
				print(str(x) + " ", end="")
			print("")
