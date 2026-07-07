class Solution {
public:
    void check(TreeNode* root,vector<int>& ans){
        if(root==NULL) return;
        ans.push_back(root->val);
        check(root->left,ans);
        check(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
            vector<int> ans;
            check(root,ans);
            return ans;
    }
};