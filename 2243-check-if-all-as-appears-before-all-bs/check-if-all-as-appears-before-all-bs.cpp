class Solution {
public:
    bool checkString(string s) {
        vector<int>arr;
        vector<int>brr;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a')
            arr.push_back(i);
            else if(s[i]=='b')
            brr.push_back(i);
        }
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<brr.size();j++){
                if(arr[i]>brr[j])
                return false;
            }
        }
        return true;
    }
};