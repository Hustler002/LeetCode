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

// class Solution {
// public:
//     void fun(vector<string>& vec, TreeNode* root, string ss) {
//         // string tmp = "";

//         // if (root == NULL){
//         //     vec.push_back(ss);
//         //     return;
//         // }

//         ss += to_string(root->val);
//         if (root->left != NULL) {
//             fun(vec, root->left, ss);
//         }
//         if (root->right != NULL) {
//             fun(vec, root->right, ss);
//         }
//         if (root->left == NULL && root->right == NULL) {
//             vec.push_back(ss);
//             return;
//         }

//         return;
//     }
//     int sumNumbers(TreeNode* root) {

//         long long res = 0;

//         vector<string> vec;
//         string ss = "";
//         fun(vec, root, ss);

//         for (auto it : vec) {
//             long long x = stoll(it);
//             res += x;
//         }

//         return res;
//     }
// };

// optimiseddddddddddddddddddddd

class Solution {
public:
    int dfs(TreeNode* root, int res) {
        if (root == NULL)
            return 0;

        res = 10 * res + root->val;
        if (root->left == NULL && root->right == NULL) {
            return res;
        }

        return dfs(root->left, res) + dfs(root->right, res);
    }
    int sumNumbers(TreeNode* root) {

        long long res = 0;

        return dfs(root, res);
    }
};