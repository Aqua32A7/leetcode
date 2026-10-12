class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums){
        unordered_map<int,int> freq;
        for(int i:nums){
            freq[i]++;
        }
        int n=nums.size();
        if(freq[nums[n/2]]>1) return false;
        return true;
        
    }
};