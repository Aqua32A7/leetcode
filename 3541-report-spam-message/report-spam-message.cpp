class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> s;
        for(auto x:bannedWords){
            s.insert(x);
        }
        int ans=0;
        for(int i=0;i<message.size();i++){
            if(s.find(message[i])!=s.end()){
                ans++;
            }
        }

        return ans>=2;
    }
};