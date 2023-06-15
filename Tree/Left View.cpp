void check(Node* root,int& max_count,vector<int>&ans,int level){
    if(root==NULL) return;
        if(level==max_count){
        ans.push_back(root->data);
        max_count++;
    }
    if(root->left){
        check(root->left,max_count,ans,level+1);
    }

    if(root->right){
        check(root->right,max_count,ans,level+1);
    }
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>ans;
   int max_count=0;
   check(root,max_count,ans,0);
   return ans;
}
