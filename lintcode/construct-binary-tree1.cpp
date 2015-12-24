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
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
	TreeNode* PreTraversal(vector<int> &preorder, vector<int> &inorder,int& preNow, int Inlow, int Inhigh)//当前前序访问位置PreNow，当前中序的方维[Inlow,Inhigh]
	{


		if(Inlow>Inhigh)
			return nullptr;

		int Divide = Inlow;
		for(; Divide != Inhigh+1 && preorder[preNow] != inorder[Divide]; Divide++)//查找当前的前序数组的值在后序的数组中的位置
		{
		}

		TreeNode* NowTreeNode = new TreeNode(preorder[preNow]);
		preNow++;//go next
		NowTreeNode->left = PreTraversal(preorder, inorder, preNow, Inlow, Divide-1);
		NowTreeNode->right = PreTraversal(preorder, inorder, preNow, Divide+1, Inhigh);
		return NowTreeNode;
	}

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		int Now = 0;
		PreTraversal(preorder, inorder, Now, 0, preorder.size()-1);
    }
    
};
