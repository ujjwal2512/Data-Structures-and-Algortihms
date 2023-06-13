vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        vector<int>res;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(q.size()>1){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL){
                ans.push_back(res);
                res.clear();
                q.push(NULL);
                continue;
               
            }
            res.push_back(curr->val);
             if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
        ans.push_back(res);
        return ans;

    }
