class Solution {
public:
    bool uniformArray(vector<int>& nums1){
        int miniO=INT_MAX;
        int miniE=INT_MAX;
        int e=0,o=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0){
                e++;
            }
            else{
                o++;
            }
        }
        if(e==0 || o==0){
            return true;
        }
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2!=0){
                miniO=min(nums1[i],miniO);
            }
            else {
                miniE=min(nums1[i],miniE);
            }
        }




        if(miniE>miniO){
            return true;
        }

        
        return false;
        
    }
};