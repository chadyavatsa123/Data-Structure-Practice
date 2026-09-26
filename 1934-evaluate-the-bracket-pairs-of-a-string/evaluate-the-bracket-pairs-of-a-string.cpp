class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
    for(auto it:knowledge){
        mp[it[0]]=it[1];
    };
    int i=0;
    string res="";
    while(i<s.size()){
        if(s[i]=='('){
        int j=i+1;
        while(s[j]!=')')
        j++;
        
        int start=i+1;
        int end=j-1;
        string ans="";
        for(int k=start;k<=end;k++){
            ans+=s[k];
        }
        if(mp.find(ans)!=mp.end()){
          res+=mp[ans];
        }
        else{
            res+="?";
        }
         i=j+1;
        }
        else{
            res+=s[i];
            i++;
        }
       

    }
    return res;

    }
};