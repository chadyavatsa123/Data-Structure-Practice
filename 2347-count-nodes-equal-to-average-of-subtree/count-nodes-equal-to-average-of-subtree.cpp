/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* node,int &sum,int &size){
        if(node==NULL)return;
        sum+=node->val;
        size++;
        solve(node->left,sum,size);
        solve(node->right,sum,size);

    }
    int averageOfSubtree(TreeNode* root) {
        int cnt=0;
        int sum=0;
        int size=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            solve(node,sum,size);
            if(sum/size == node->val)
            cnt++;
            sum=0;
            size=0;
            if(node->left)
            q.push(node->left);
            if(node->right){
            q.push(node->right);
            }
            
        }
        return cnt;
    }
};