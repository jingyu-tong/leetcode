/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //inorderTraversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
private:
    void inorder(TreeNode* root, vector<int>& ans) {
        if(!root) return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
};
//inorder iteration
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* cur = root;
        stack<TreeNode*> s;
        while(cur || !s.empty()) {
            while(cur) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            ans.push_back(cur->val);
            cur = cur->right;
        }
        return ans;
    }
};

//preorder
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
    void preorder(TreeNode* root, vector<int>& ans) {
        if(!root)
            return;
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
};
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(cur || !s.empty()) {
            while(cur) {
                ans.push_back(cur->val);
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top(); s.pop();
            cur = cur->right;
        }
        return ans;
    }
};

//postorder
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
    void postorder(TreeNode* root, vector<int>& ans) {
        if(!root) return;
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }
};
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* last = root;
        while(!s.empty()) {
            TreeNode* cur = s.top();
            if((!cur->left && !cur->right) || last == cur->left || last == cur->right) {
                ans.push_back(cur->val);
                s.pop();
                last = cur;
            } else {
                if(cur->right) s.push(cur->right);
                if(cur->left) s.push(cur->left);
            }
        }
        return ans;
    }
};

//level traversal
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q{{root}};
        while(!q.empty()) {
            vector<int> level;
            for(int i = q.size(); i > 0; --i) {
                TreeNode* temp = q.front(); q.pop();
                level.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
