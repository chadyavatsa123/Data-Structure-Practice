class Solution {
public:
    void solve(int start,int end,string res,vector<string>&ans,int n){
        if(start==n && end==n){
            ans.push_back(res);
            return;
        }
        if(start<n){
            string op1=res;
            op1+="(";
           
            solve(start+1,end,op1,ans,n);
        }
        if(start>end){
            string op2=res;
            op2+=")";
           
            solve(start,end+1,op2,ans,n);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        int start=0;
        int end=0;
        vector<string>ans;
        string res="";
        solve(start,end,res,ans,n);
        return ans;
    }
};