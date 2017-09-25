

// METHOD 1 : using one stack : This method can also be used to calculate the maximum height of a binary tree using size of stack
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans ;
        if(!root)return ans;
        stack<TreeNode*> st;
        TreeNode* p = root;
        while(!st.empty() || p != NULL){
            if(p != NULL){
                st.push(p);
                p = p->left;
            }
            else{
                if(!st.empty()){
                    TreeNode* temp = st.top()->right;
                    if(temp){
                        p = temp;
                    }
                    else{
                        temp = st.top() ; st.pop();
                        ans.push_back(temp->val);
                        while(!st.empty() && st.top()->right == temp){
                            temp = st.top() ; st.pop();
                            ans.push_back(temp->val);
                        }
                    }
                }
            }
        }
        return ans;
    }
    
    // METHOD 2 :  using 2 stacks . This method is quite intuitive
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans ; 
        if(!root)return ans;
        stack<TreeNode*> st1;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* n = st1.top(); st1.pop();
            ans.push_back(n->val);
            if(n->left)st1.push(n->left);
            if(n->right)st1.push(n->right);
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
