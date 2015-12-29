class Solution {
public:

   TreeNode** SearchTree(TreeNode* root, int value)
   {
		if(nullptr == root)
			return &root;

		if(root->val == value)
			return &root;
		

		if(root->val > value)
			return SearchTree(root->left, value);
		else
			return SearchTree(root->right, value);

   }

      TreeNode** SearchLeftTree(TreeNode* root)
   {
		
	   if(nullptr == root->right)
		   return &(root->right);
	   
	   return SearchLeftTree(root->left);

   }

   TreeNode* removeNode(TreeNode* root, int value) {
	   TreeNode** NowNodePtr = SearchTree(root, value);
	   TreeNode* NowNode = *NowNodePtr;
	   if(NowNode == nullptr)
			return root;

	   if(NowNode->left == nullptr && NowNode->right == nullptr)
	   {
		   NowNode = nullptr; 
	   }
	   else if(NowNode->left == nullptr)//only left is null
	   {
		   TreeNode* Right = NowNode->right;
		   delete NowNode;
		   NowNode = Right;
		   return root;
	   }
	   else if(NowNode->right == nullptr)
	   {
			TreeNode* Left = NowNode->left;
		   delete NowNode;
		   NowNode = Left;
		   return root;
	   }
	   else
	   {

		TreeNode *s = NULL;  
		TreeNode *q = NULL;
        q = NowNode;  
        s = NowNode->left;       //左子树根结点  
        while(s->right) //寻找结点*NowNode的中序前驱结点，                      
        {                   //也就是以*s为根结点的子树中最右的结点   
            s = s->right;      
        }  
        s->right = NowNode->right;//*NowNode的右子树接到*s的右子树上   
        NowNode = NowNode->left;           //*NowNode的左子树接到父节点上   
        delete q;           //删除结点*q  
		return NowNode;

		 
	   }
    }
};
