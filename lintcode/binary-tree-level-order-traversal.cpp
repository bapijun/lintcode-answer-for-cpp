/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
	
    /** 
     * @param root : The root of binary tree. 
     * @return : buttom-up level order a list of lists of integer 
     */  
	void DFS(vector<vector<int>>& result,TreeNode* root ,int deep)
	{
		if(nullptr == root)
			return;

		deep++;//深度增加
		if(deep > result.size())
		{
			vector<int> NowDeep;
			NowDeep.push_back(root->val);
			result.push_back(NowDeep);
			DFS(result, root->left, deep);
			DFS(result, root->right, deep);
		}
		else
		{		
			result[deep-1].push_back(root->val);
			DFS(result, root->left, deep);
			DFS(result, root->right, deep);
		}
		
	}

    vector<vector<int>> levelOrder(TreeNode *root)
	{
		vector<vector<int>> result;
		DFS(result, root, 0);
		return result;
	}
};
