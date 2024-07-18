 class Solution {
public:
    map<TreeNode*,TreeNode*>parent;
    vector<TreeNode*>leafnode;
    void findparent(TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right]=node;
                q.push(node->right);
            }
            if(node->left==nullptr && node->right==nullptr){
                leafnode.push_back(node);
            }
        }
    }
    int bfs(TreeNode* root,int distance){
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int cnt = 0;
        map<TreeNode*,int>mp;
        while(!q.empty()){
            auto node = q.front().first;
            int dis = q.front().second;
            q.pop();
            mp[node]++;
            if(node->left && mp.find(node->left)==mp.end()){
                if(dis+1<=distance)q.push({node->left,dis+1});
            }
            if(node->right && mp.find(node->right)==mp.end()){
                if(dis+1<=distance)q.push({node->right,dis+1});
            }
            if((parent[node])){
                if(dis+1<=distance)q.push({parent[node],dis+1});
            }
            if(node->left==nullptr && node->right==nullptr && root!=node){
                if(dis<=distance)cnt++;
            }
        }
        return cnt;
    }
    int countPairs(TreeNode* root, int distance) {
        findparent(root);
        int ans = 0;
        for(int i = 0 ; i < leafnode.size() ; i++){
            ans += bfs(leafnode[i],distance);
        }
        return ans/2;

    }
};