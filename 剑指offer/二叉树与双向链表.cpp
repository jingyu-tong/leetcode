//这里prev需要能向上传递的参数，这里采用的是指针的引用，单纯的指针是不能正确运行的
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree) return nullptr;
        TreeNode* prev = nullptr;
        inorder(pRootOfTree, prev);
        while(pRootOfTree->left) {
            pRootOfTree = pRootOfTree->left;
        }
        return pRootOfTree;
    }
    
    //void inorder(TreeNode* node, TreeNode* prev) //不行，需要能向上传递的prev参数
    void inorder(TreeNode* node, TreeNode*& prev) {
        if(!node) return;
        
        if(node->left) inorder(node->left, prev);
        
        node->left = prev;
        if(prev) {
            prev->right = node;
        }
        prev = node;
        if(node->right) inorder(node->right, prev);
    }
};