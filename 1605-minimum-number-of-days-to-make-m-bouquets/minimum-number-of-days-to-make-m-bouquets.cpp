class Solution {
public:
    int check(vector<int>& bloomDay,int d,int k){
        int s=0;
        int c=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=d){
                s++;
                if(s==k){
                c++;
                s=0;
            }
            }

            else{
                s=0;
            }

        }
        return c;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<(long long)m*k){
            return -1;
        }

        int end=INT_MIN;
        int start=INT_MAX;

        for(int i=0;i<bloomDay.size();i++){
            start=min(start,bloomDay[i]);
            end=max(end,bloomDay[i]);

        }
        while(start<=end){
            int mid=start+(end-start)/2;
            int ans =check(bloomDay,mid,k);
            if(ans>=m){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }

        return start;




        
        
    }
};