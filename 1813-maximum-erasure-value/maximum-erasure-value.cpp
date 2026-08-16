class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        unordered_map<int,int> freq;
        int ans=0;
        int sum=0;
        while(j<nums.size()){
            freq[nums[j]]++;
            sum+=nums[j];
            while(freq[nums[j]]>1){
                freq[nums[i]]--;
                sum-=nums[i];
                i++;

            }
            ans=max(ans,sum);
            j++;
        }
        return ans;
    }
};