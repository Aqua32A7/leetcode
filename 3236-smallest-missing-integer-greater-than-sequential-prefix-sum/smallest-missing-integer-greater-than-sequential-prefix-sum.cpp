class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                sum+=nums[i];
            }
            else {
                break;
            }
        }

        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }


        while(mp.count(sum)>0){
                sum++;
            }
        return sum;
        





    }
};