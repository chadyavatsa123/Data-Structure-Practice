class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string ans;
      for(char ch:s){
        if(ch=='('){//agar stack empty hoga to wo outermost element hoga usko answer me include nhi krna hai
            if(!st.empty())//agar stack empty nhi to wo outermost element nhi h to usko ans me include kr do
            ans.push_back(ch);
            st.push(ch);
        }
        else{
            st.pop();
            if(!st.empty())
            ans.push_back(ch);
        }
      }
      return ans;

    }
};