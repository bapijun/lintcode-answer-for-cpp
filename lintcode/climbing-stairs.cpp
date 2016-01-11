class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        if(n==0) {
            return 0;
        }
        else if(n == 1) {
            return 1;
        }
        else if(n == 2) {
            return 2;
        }
        else {
            return climbStairs(n-1) + climbStairs(n-2);
        }
    }
};
