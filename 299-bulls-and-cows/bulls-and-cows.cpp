class Solution {
public:
    string getHint(string secret, string guess){
        int cB=0;
        int cC=0;
        unordered_map<char,int> freqB;
        unordered_map<char,int> freqC;

        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                cB++;
            }
            else{
                freqB[secret[i]]++;
                freqC[guess[i]]++;
            }
        }

        for(auto i:freqB){
            char dig=i.first;
            int count=i.second;


            if(freqC.count(dig)){
                cC+=min(count, freqC[dig]);
            }
        }


        return to_string(cB)+"A"+to_string(cC)+"B";


        
    }
};