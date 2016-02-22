class Solution {
public:
	bool PathSearch(TreeNode* root, int sum, int NowSum) {
		if(nullptr == root) {
			return false;
		}

		else if(NowSum + root->val == sum && nullptr == root->left && nullptr == root->right) {
				return true;
		}
		else {
			return PathSearch(root->left, sum, NowSum+root->val) || PathSearch(root->right, sum, NowSum+root->val);
		}
	}
    bool hasPathSum(TreeNode* root, int sum) {
        return PathSearch(root, sum, 0);
    }
};
