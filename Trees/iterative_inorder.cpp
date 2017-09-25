    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)return {};
        vector<int> ans;
        TreeNode* p = root;
        stack<TreeNode*> st;
        while(!st.empty() || p != NULL){
            if(p != NULL){
                st.push(p);
                p = p->left;
            }
            else{
                if(!st.empty()){
                    ans.push_back(st.top()->val);
                    TreeNode* n = st.top() ; st.pop();
                    p = n->right;
                }
            }
        }
        return ans;
    }
