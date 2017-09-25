vector<int> preorderTraversal(TreeNode* root) {
        if(!root)return {};
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* p = root;
        while(!st.empty() || p != NULL){
            if(p != NULL){
                ans.push_back(p->val);
                st.push(p);
                p = p->left;
            }
            else{
                if(!st.empty()){
                    TreeNode* n = st.top() ; st.pop();
                    p = n->right;
                }
            }
        }
        return ans;
    }
