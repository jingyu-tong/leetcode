class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == nullptr) return nullptr;
        
        //has right child
        if(pNode->right) {
            TreeLinkNode* ans = pNode->right;
            while(ans->left) {
                ans = ans->left;
            }
            return ans;
        } else if(pNode->next) {
            TreeLinkNode* cur = pNode->next;
            TreeLinkNode* pre = pNode;
            while(cur && pre != cur->left) {
                pre = cur;
                cur = cur->next;
            }
            return cur;
        } 
        return nullptr;
    }
};