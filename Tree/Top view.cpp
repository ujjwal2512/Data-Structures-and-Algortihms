   void check(Node*root,int level,int height,map<int,pair<int,int>>&mp){
        if(root==NULL) return;
       
        check(root->left,level-1,height+1,mp);
        check(root->right,level+1,height+1,mp);
         if(mp.find(level)==mp.end()){
            mp[level]={root->data,height};
        }else{
            if(mp[level].second>height){
                mp[level]={root->data,height}; 
            }
        }
    }
    
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>ans;
        map<int,pair<int,int>>mp;
        check(root,0,0,mp);
        for(auto i:mp){
            ans.push_back(i.second.first);
        }
        return ans;
        
    }
