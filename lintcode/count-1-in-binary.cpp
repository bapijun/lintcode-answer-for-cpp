class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        num = (num&0x55555555) + ((num>>1)&0x55555555);  
		    num = (num&0x33333333) + ((num>>2)&0x33333333);    
		    num = (num&0x0f0f0f0f) + ((num>>4)&0x0f0f0f0f);   
		    num = (num&0x00ff00ff) + ((num>>8)&0x00ff00ff);   
		    num = (num&0x0000ffff) + ((num>>16)&0x0000ffff);  
		    return num;
    }
};
