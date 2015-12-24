class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
	bool afterSearch(TreeNode *root, int& deep)
	{
		if(nullptr == root)
		{
			deep = 0;
			return true;
		}
		
		int leftdeep = 0, rightdeep = 0;
		if(afterSearch(root->left, leftdeep))
		{
			if(afterSearch(root->right, rightdeep))
			{
					int dos = leftdeep - rightdeep;
					if(dos<=1&&dos>=-1)
					{
						deep = (leftdeep>rightdeep)?leftdeep+1:rightdeep+1;
						return true;
					}
					else
					{
						return false;
					}
			}
		
		}
		
		return false;
	}
	


	bool isBalanced(TreeNode *root) {
		return afterSearch(root, 0);
	}
};
