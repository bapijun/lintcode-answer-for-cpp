class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
	void combination(vector<int> &candidates, int target, int index, vector<int> cur,int sum, vector<vector<int>>& Result)
	{
		if(candidates.size() <= index)
			return;
		
		if(sum + candidates[index] == target)
		{
			cur.push_back(candidates[index]);
			Result.push_back(cur);
		}
		else if(sum + candidates[index] < target)
		{
			cur.push_back(candidates[index]);
			sum += candidates[index];
			combination(candidates, target, index, cur, sum, Result);
			combination(candidates, target, index+1, cur, sum, Result);
			cur.pop_back();
			combination(candidates, target, index+1, cur, sum, Result);
		}
		

	}


    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> Result;
		vector<int> cur;
		combination(candidates, target, 0, cur, 0, Result);
		return Result;
    }
};
