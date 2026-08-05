class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
          vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            int v=prerequisites[i][0];
            int u=prerequisites[i][1];
            adj[u].push_back(v);
        }
        queue<int>q;
        vector<int>inorder(numCourses);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i])
            inorder[it]++;
        }
        for(int i=0;i<numCourses;i++){
            if(inorder[i]==0)
            q.push(i);
        }
        vector<int>ans;
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            cnt++;
            for(auto it:adj[node]){
                inorder[it]--;
                if(inorder[it]==0)
                q.push(it);
            }

        }
      if(cnt==numCourses)
      return ans;
      return {};
    }
};