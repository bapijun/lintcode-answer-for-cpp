class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxProduct(vector<int> nums) {
		if(nums.size()<=0) return 0;  
		if(nums.size()==1) return nums[0];  
		int curMax = nums[0];  
		int curMin = nums[0];  
		int ans = nums[0];  
		for(int i=1;i<nums.size();i++){  
			int temp = curMin *nums[i];  
			curMin = min(nums[i], min(temp, curMax*nums[i]));  
			curMax = max(nums[i], max(temp, curMax*nums[i]));  
			ans = max(ans, curMax);  
		}  
		return ans;  
    }
};
