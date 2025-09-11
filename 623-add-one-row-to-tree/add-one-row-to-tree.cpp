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
// class Solution {
// public:
//     void dfs(TreeNode* root, int val, int depth,int curr){
//         if(curr == depth - 1){
//             TreeNode* l = root->left;
//             TreeNode* r = root->right;
//             TreeNode* nodel = new TreeNode(val);
//             TreeNode* noder = new TreeNode(val);
//             root->left = nodel;
//             root->right = noder;
//             nodel->left = l;
//             noder->right = r;
//             return;
//         }
//         if(root->left != NULL) dfs(root->left, val, depth, curr+1);
//         if(root->right != NULL) dfs(root->right, val, depth, curr+1);
//         return;
//     }
//     TreeNode* addOneRow(TreeNode* root, int val, int depth) {
//         if(depth==1){
//             TreeNode* nd = new TreeNode(val);
//             nd->left = root;
//             //nd->right = NULL;
//             return nd;
//         }
//         dfs(root,val,depth,1);
//         return root;
//     }
// };



//BFS


class Solution {
public:
    void bfs(TreeNode* root, int val, int depth,int curr){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            if(curr == depth-1){
                int st = sz;
            while(st--){
                TreeNode* node = q.front();
                q.pop();
                
                
                    TreeNode* l = node->left;
                    TreeNode* r = node->right;
                    TreeNode* nodel = new TreeNode(val);
                    TreeNode* noder = new TreeNode(val);
                    node->left = nodel;
                    node->right = noder;
                    nodel->left = l;
                    noder->right = r;
                    
                }
                return;
            }
            while(sz--){
                TreeNode* node = q.front();
                q.pop();

                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }
            curr++;
        }
        return;
       
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* nd = new TreeNode(val);
            nd->left = root;
            //nd->right = NULL;
            return nd;
        }
        bfs(root,val,depth,1);
        return root;
    }
};