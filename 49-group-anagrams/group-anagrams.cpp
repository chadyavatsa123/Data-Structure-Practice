class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string>temp;
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            temp.push_back(s);
        }
        vector<vector<string>>ans;
        unordered_map<string,bool>visited;
        for(int i=0;i<strs.size();i++){
           if(visited[strs[i]]==true)continue;
            vector<string>res;
            res.push_back(strs[i]);
            visited[strs[i]]=true;
            for(int j=0;j<strs.size();j++){
                if(i!=j && temp[i]==temp[j]){
                  res.push_back(strs[j]);
                  visited[strs[j]]=true;
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};