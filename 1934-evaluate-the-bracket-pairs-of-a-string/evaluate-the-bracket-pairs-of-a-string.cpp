class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge){
        unordered_map<string,string> check;
        for(auto it:knowledge){
            check[it[0]]=it[1];
        }
        string ans1="";
        for(int i=0;i<s.size();i++){
            string ans="";
            if(s[i]=='('){
                int j;
                
                for(j=i+1;s[j]!=')';j++){
                    ans+=s[j];
                }
                if(check.find(ans)!=check.end()){
                ans1+=check[ans];
                }
                else{
                ans1+='?';

                }
                i=j;
            }
            

            else{
                ans1+=s[i];
            }

        }
        return ans1;
        
    }
};