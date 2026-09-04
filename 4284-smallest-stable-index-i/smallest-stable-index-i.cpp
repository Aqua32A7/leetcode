class Solution {
public:
    int maxi(vector<int>& nums,int st,int end){
        int maxii=INT_MIN;
        for(int i=st;i<=end;i++){
            maxii=max(maxii,nums[i]);
        }
        return maxii;
    }
    int mini(vector<int>&  nums,int st,int end){
        int minii=INT_MAX;
        for(int i=st;i<=end;i++){
            minii=min(minii,nums[i]);

        }
        return minii;
    }
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            if((maxi(nums,0,i)-mini(nums,i,n-1))<=k){
                return i;
            }
        }
        return -1;
        
    }
};