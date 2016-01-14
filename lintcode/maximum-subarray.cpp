class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        if(0 == nums.size()) {
			return 0;
		}
		else if(1 == nums.size()) {
			return nums[0];
		}
		else {
			int Max = INT_MIN;//设定的最大值,初始化为ini的最小值
			int NowMax = INT_MIN;//当前的数组终止的子数组的最大值
			for(vector<int>::const_iterator ite = nums.cbegin(); ite != nums.cend(); ite++) {
				if(NowMax <= 0) {
					NowMax = *ite;
					if(Max < NowMax) {
						Max = NowMax;
					}
				}
				else {
					NowMax += *ite;
					if(Max < NowMax) {
						Max = NowMax;
					}
				}//end of else
			}//end of for
			return Max;
		}//end of else
    }
};
