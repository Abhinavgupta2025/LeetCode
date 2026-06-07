class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
            TreeNode* root = NULL;
            unordered_set<int> st;
            for(auto it : descriptions){
                st.insert(it[1]);
            }
            for(auto it : descriptions){
                if(st.find(it[0])==st.end()){
                    root = new TreeNode(it[0]);
                    break;
                }
            }
            unordered_map<int,TreeNode*> mp;
            mp[root->val] = root;
            for(auto it : descriptions){
                int parent = it[0];
                int child  = it[1];
                int left   = it[2];
                TreeNode* parentRoot = NULL;
                TreeNode* childRoot = NULL;
                if(mp.find(parent)!=mp.end())parentRoot = mp[parent];
                else parentRoot = new TreeNode(parent);
                if(mp.find(child)!=mp.end()) childRoot = mp[child];
                else childRoot = new TreeNode(child);
                if(left==1) parentRoot->left = childRoot;
                else parentRoot->right = childRoot;
                mp[parentRoot->val] = parentRoot;
                mp[childRoot->val] = childRoot;
            }
            return root;
    }
};