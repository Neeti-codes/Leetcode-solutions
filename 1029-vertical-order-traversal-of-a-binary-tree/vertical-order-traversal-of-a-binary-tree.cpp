
class Solution {
public:
    map<int, map<int, multiset<int>>> nodes;

    void dfs(TreeNode* root, int row, int col) {
        if (root == NULL)
            return;

        nodes[col][row].insert(root->val);

        dfs(root->left, row + 1, col - 1);
        dfs(root->right, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);

        vector<vector<int>> ans;

        for (auto &col : nodes) {
            vector<int> vertical;

            for (auto &row : col.second) {
                for (int val : row.second) {
                    vertical.push_back(val);
                }
            }

            ans.push_back(vertical);
        }

        return ans;
    }
};
