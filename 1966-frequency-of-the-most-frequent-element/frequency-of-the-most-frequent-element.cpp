class Solution {
public:
    int maxFrequency(vector<int>& nums, int n) {
        sort(nums.begin(),nums.end());
        int i=0,j=0,ans=0;
        long long sum=0;
        while(j<nums.size()){
            sum+=nums[j];
            long long cost=(long long)nums[j]*(j-i+1)-sum;
            while(cost>n){
                sum-=nums[i];
                i++;
                cost = (long long) nums[j] * (j - i + 1) - sum;
            }
            ans=max(ans,j-i+1);
            j++;

        }

        return ans;

        
    }
};