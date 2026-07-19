class Solution {
public:
    string smallestSubsequence(string s) {
       unordered_map<char,int>mp;
       for(int i=0;i<s.size();i++){
        mp[s[i]]=i;
       } 
       stack<char>st;
       vector<bool>visited(26,false);
       for(int i=0;i<s.size();i++){
       if(visited[s[i]-'a'])continue;
       while(!st.empty() && s[i]<st.top() && mp[st.top()]>i){
        visited[st.top()-'a']=false;
        st.pop();
       }
       st.push(s[i]);
       visited[s[i]-'a']=true;
       }
       vector<char>ans;
       while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
       }
       reverse(ans.begin(),ans.end());
       string res="";
       for(int i=0;i<ans.size();i++){
        res+=ans[i];
       }
       return res;
    }
};