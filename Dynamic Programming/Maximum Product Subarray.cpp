   int maxProduct(vector<int>& nums) {
        int max_till_now=INT_MIN;
        int max_till_now2=INT_MIN;
        int max_now=1;
        for(int i=0;i<nums.size();i++){
            max_now*=nums[i];
            max_till_now=max(max_till_now,max_now);
            if(max_now==0){
                max_now=1;
            }
        }
         max_now=1;
        for(int i=nums.size()-1;i>=0;i--){
            max_now*=nums[i];
            max_till_now2=max(max_till_now2,max_now);
            if(max_now==0){
                max_now=1;
            }
        }
        return max(max_till_now,max_till_now2);
    }
