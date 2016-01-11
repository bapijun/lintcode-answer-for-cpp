class Solution {
public:
   
    vector<vector<int> > dp;   
    int solve(vector<vector<int> >&v,int i,int j,int n){
        if(dp[i][j]!=INT_MIN)
            return dp[i][j];
        return dp[i][j]=v[i][j]+(i==n?0:min(solve(v,i+1,j,n),solve(v,i+1,j+1,n)));    
    } 
    int minimumTotal(vector<vector<int> > &triangle) {
        const int n=triangle.size();
        const int m=triangle[n-1].size();
        
        for(int i=0;i<n;++i){
            vector<int> base;
            for(int j=0;j<m;++j)
                base.push_back(INT_MIN);
            dp.push_back(base);    
        }
        solve(triangle,0,0,n-1);
    }
};
