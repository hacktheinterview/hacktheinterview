if __name__ == "__main__":
    test_cases = int(raw_input())
    for t in range(test_cases):
        lineItems = [int(l) for l in raw_input().split(" ")]
        rows = lineItems[0]
        cols = lineItems[1]
        K = lineItems[-1]
        lineItems = lineItems[2: -1]
        matrix = []
        for i in range(rows):
            l = []
            for j in range(cols):
                l.append(lineItems[i*cols+j])
            matrix.append(l)

        s = Solution()
        result = s.searchMatrix(matrix, K)
        print result
