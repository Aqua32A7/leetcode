class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed){
        vector<pair<int,int>> pr;

        for(int i=0;i<position.size();i++){
            pr.push_back({position[i],speed[i]});
        }

        sort(pr.begin(), pr.end());

        stack<double> st;
        int n = position.size();
        for(int i=n-1;i>=0;i--){
            double time=(double)(target-pr[i].first)/pr[i].second;
            if(st.empty() || st.top()<time){
                st.push(time);
            }
        }
        return st.size();
        
    }
};