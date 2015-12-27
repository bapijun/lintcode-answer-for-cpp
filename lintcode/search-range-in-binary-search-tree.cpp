class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
	void searchRangeRec(TreeNode* root, int k1, int k2, vector<int>& result) {
        if(nullptr == root)
			return;
		if(root->val > k2)
		{
			searchRangeRec(root->left, k1, k2 , result);
		}
		else if(root->val < k1)
			{
				searchRangeRec(root->right, k1, k2 , result);
			}
		else
		{
				
				searchRangeRec(root->left, k1, k2 , result);
				result.push_back(root->val);
				searchRangeRec(root->right, k1, k2 , result);
		}

    }

    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        vector<int> result;
		searchRangeRec(root, k1, k2 ,result);
		return result;
    }
};
