class Solution {
public:
    bool isAnagram(string s, string t) {
       /* int arr[26]={0};
        if(s.size()!=t.size())return false;
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']++;
             arr[t[i]-'a']--;
        }
        /*for(int i=0;i<t.size();i++){
            arr[t[i]-'a']--;
        }*/
       /* for(int i=0;i<26;i++){
            if(arr[i])return false;
        }
        return true;*/
        if(s.size()!=t.size())return false;
       unordered_map<char,int>mpp;
       for(auto it:s){
        mpp[it]++;
       }
       for(auto it:t){
       mpp[it]--;
       if(mpp[it]<0)return false;
        }
       return true;
    }
};