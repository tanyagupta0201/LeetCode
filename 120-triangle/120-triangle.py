# https://youtu.be/OM1MTokvxs4

class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        dp = [0] * (len(triangle) + 1)
        
        for row in triangle[ : : -1]:
            for i, n in enumerate(row):
                dp[i] = n + min(dp[i], dp[i + 1])
                
        return dp[0]
                
        
'''
C++ code

for(int i=triangle.size()-2;i>=0;--i)
    {
        for(int j=0;j<triangle[i].size();j++)
        {
            triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);   
        }
    }
    return triangle[0][0];

'''