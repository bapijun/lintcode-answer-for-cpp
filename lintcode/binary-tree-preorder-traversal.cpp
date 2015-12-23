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
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
     
    vector<int> preorderTraversal(TreeNode *root) 
    {
		vector<int> Result;
		stack<TreeNode*> Stk;
	    Stk.push(root);
		while(!Stk.empty())
		{
			TreeNode* NowNode = Stk.top();
			Stk.pop();
			if(NULL != NowNode)
			{
				Result.push_back(NowNode->val);
				Stk.push(NowNode->right);
				Stk.push(NowNode->left);
			}
		}
		return Result;
    }

    
};
