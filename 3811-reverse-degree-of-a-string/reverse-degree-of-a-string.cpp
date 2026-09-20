class Solution {
public:
    int reverseDegree(string s) {
        unordered_map<char,int>mp;
        int cnt=26;
       for(char ch='a';ch<='z';ch++){
        mp[ch]=cnt;
        cnt--;
       }
       int sum=0;
       int prod=1;
       for(int i=0;i<s.size();i++){ 
          prod=mp[s[i]]*(i+1);
          sum+=prod;
       }
       return sum;
    }
};