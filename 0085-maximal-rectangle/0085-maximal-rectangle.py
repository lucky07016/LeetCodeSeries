class Solution:
    def maximalRectangle(self, matrix):
        if not matrix:
            return 0

        rows = len(matrix)
        cols = len(matrix[0])

        heights = [0] * cols
        maxArea = 0

        for row in matrix:
            for c in range(cols):
                if row[c] == "1":
                    heights[c] += 1
                else:
                    heights[c] = 0
            stack = []
            extended = heights + [0]

            for i in range(len(extended)):
                while stack and extended[i] < extended[stack[-1]]:
                    h = extended[stack.pop()]
                    if stack:
                        width = i - stack[-1] - 1
                    else:
                        width = i

                    maxArea = max(maxArea, h * width)
                stack.append(i)

        return maxArea