class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        //特殊情况
		if(0 == obstacleGrid.size()) {
			return 0;
		}
		if(0 == obstacleGrid[0].size()) {
			return 0;
		}

		if(1 == obstacleGrid[0][0]) {
			return 0;
		}
		vector<vector<int>> PathMatix;
		for(int i = 0; i != obstacleGrid.size(); i++) {
			vector<int> tem;
			for(int j = 0; j != obstacleGrid[i].size(); j++) {
				tem.push_back(0);
			}
			PathMatix.push_back(tem);
		}

		PathMatix[0][0] = 1;//obstacleGrid[0][0] != 0;
		//初始化两边
		for(int i = 1; i != obstacleGrid.size(); i++) {
			if(obstacleGrid[i][0] == 1) {
				PathMatix[i][0] = 0;
			}
			else {
				PathMatix[i][0] = PathMatix[i-1][0];
			}
		}

		for(int i = 1; i != obstacleGrid[0].size(); i++) {
			if(obstacleGrid[0][i] == 1) {
				PathMatix[0][i] = 0;
			}
			else {
				PathMatix[0][i] = PathMatix[0][i-1];
			}
		}
        //填充矩阵
		for(int i = 1; i != obstacleGrid.size(); i++) {
			for(int j = 1; j != obstacleGrid[i].size(); j++) {
			
					if(obstacleGrid[i][j] == 1) {
						PathMatix[i][j] = 0;
					}
					else {
						PathMatix[i][j] = PathMatix[i-1][j] + PathMatix[i][j-1];
					}
				
			}
		}

		return PathMatix[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
	}
    
};
