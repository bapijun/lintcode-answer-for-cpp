class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
     
  	bool isBSTUtil(TreeNode * node , int min , int max )
	{
		//空树也是BST
		if ( node == NULL)
			return true;

		//如果节点值违反了最大/最小约束条件，则不是BST
		if ( node->val < min || node->val > max)
			return false;

		//递归检查子树
		return  isBSTUtil( node->left, min, node->val - 1) &&
			isBSTUtil( node->right, node->val + 1, max);
	}
	bool isValidBST(TreeNode *root) 
	{
		return(isBSTUtil( root, INT_MIN, INT_MAX));
	}
};
