class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int st=i+1;
            int num=target-nums[i];
            int end=nums.size()-1;
            while(st<=end){
                int mid=st+(end-st)/2;
                if(num<nums[mid]){
                    end=mid-1;
                }
                else if(nums[mid]<num){
                    st=mid+1;
                }
                else{
                    return {i+1,mid+1};
                }
            }
        }
        return {};
        
    }
};