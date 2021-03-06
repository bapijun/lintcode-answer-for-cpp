class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        // write your code here
        int n = word1.length();
        int m = word2.length();
        vector<vector<int> > dp(n+1,vector<int>(m+1,0));
        for(int i = 1;i<=n;i++)
            dp[i][0]=i;
        for(int i=1;i<=m;i++)
            dp[0][i]=i;
        for(int i=1;i<=n;i++)
        {
            char c1 = word1[i-1];
            for(int j=1;j<=m;j++)
            {
                char c2 = word2[j-1];
                if(c1==c2)
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                
            }
        }
        return dp[n][m];
    }
};
