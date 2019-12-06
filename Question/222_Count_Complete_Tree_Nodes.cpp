//后序遍历
//这种方式没有用完全二叉树的性质
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        int left = countNodes(root->left);
        int right = countNodes(root->right);
        
        return left + right + 1;
    }
};

//利用左右高度判断是否为满二叉树
class Solution {
public:
    int countNodes(TreeNode* root) {
        int hLeft = 0, hRight = 0;
        TreeNode *pLeft = root, *pRight = root;
        while (pLeft) {
            ++hLeft;
            pLeft = pLeft->left;
        }
        while (pRight) {
            ++hRight;
            pRight = pRight->right;
        }
        if (hLeft == hRight) return pow(2, hLeft) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};