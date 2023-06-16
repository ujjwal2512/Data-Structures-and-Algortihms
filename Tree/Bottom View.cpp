 void check(Node* root,int level,int count,map<int,pair<int,int>> &mp){
      if(root==NULL) return;
     if(mp.find(level)==mp.end()){
         mp[level]={root->data,count};
     }else{
         if(mp[level].second<=count){
             mp[level]={root->data,count};
         }
     }
     check(root->left,level-1,count+1,mp);
     check(root->right,level+1,count+1,mp);
      
  }
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int>ans;
        map<int,pair<int,int>>mp;
        check(root,0,0,mp);
        for(auto i:mp){
            ans.push_back(i.second.first);
        }
        return ans;
       
    }
