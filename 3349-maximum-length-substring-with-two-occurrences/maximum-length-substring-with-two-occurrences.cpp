class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>mp;
        int l=0;
        int r=0;
        int mxcnt=0;
        while(r<s.size()){
            mp[s[r]]++;
            while(mp[s[r]]>2){
                mp[s[l]]--;
                if(mp[s[l]]==0)
                mp.erase(s[l]);
                l++;
            }
            mxcnt=max(mxcnt,r-l+1);
            r++;
        }
        return mxcnt;
    }
};