class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=0;
        int maxi=0;
        int n=nums.size();

        for(int i=0;i<nums.size();i++){
            if(nums[i]<nums[mini]){
                mini=i;
            }
            if(nums[i]>nums[maxi]){
                maxi=i;
            }
        }
        int minn=min(maxi,mini);
        int maxx=max(maxi,mini);
        


        int back=maxx+1;
        int front=n-minn;
        int both=n-maxx + minn+1;


        return min({back,front,both});






 
    }
};