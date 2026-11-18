class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
        int i=0;
        vector<string>res;
        while(i<s.size()){
          res.push_back(s.substr(i,k));
          i+=k;
        }
         //vector<int>num;
        for(int i=0;i<res.size();i++){
            int sum=0;
            for(int j=0;j<res[i].size();j++){
             sum+=res[i][j]-'0';
            }
            res[i]=to_string(sum);
        }
       
        string ans="";
        for(int i=0;i<res.size();i++){
          ans+=res[i];
        }
        if(ans.size()<=k)return ans;
        s=ans;
        }
        return s;
    }
};