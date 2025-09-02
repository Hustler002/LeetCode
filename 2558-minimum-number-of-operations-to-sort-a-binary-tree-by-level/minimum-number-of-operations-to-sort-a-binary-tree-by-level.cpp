/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int ress = 0;
    int minSwaps(vector<int>& arr){
        
        int n = arr.size();
        vector<pair<int,int>> mpp;
        mpp.reserve(n);
        for(int i = 0; i < n; i++){
            mpp.push_back({arr[i],i});
        }

        sort(mpp.begin(),mpp.end());

        vector<bool> vis(n,false);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(mpp[i].second == i || vis[i]) continue;
            int cycle_size = 0;
            int j = i;
            while(!vis[j]){
                vis[j] = true;
                j = mpp[j].second;
                cycle_size++;
            }
            if(cycle_size > 1) ans += cycle_size -1;
        }
        return ans;
    }
    int minimumOperations(TreeNode* root) {
        if(!root) return 0;
        vector<vector<int>> res;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> tmp;
            tmp.reserve(sz);
            for (int i = 0; i < sz; i++) {
                TreeNode* nd = q.front();
                tmp.push_back(nd->val);
                q.pop();
                if (nd->left != NULL)
                    q.push(nd->left);
                if (nd->right != NULL)
                    q.push(nd->right);
            }
            res.push_back(tmp);
        }
        for (auto& it : res) {

            if (it.size() == 1)
                continue;
            ress+=minSwaps(it);
        }

        return ress;
    }
};