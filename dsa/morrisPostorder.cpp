#include<bits/stdc++.h>
vector<int> morrisPostorder(TreeNode* root) {
    vector<int> result;
    TreeNode* curr = root;

    while (curr != NULL) {
        if (curr->right == NULL) {
            result.push_back(curr->val);
            curr = curr->left;
        } else {
            TreeNode* rightChild = curr->right;
            while (rightChild->left != NULL && rightChild->left != curr) {
                rightChild = rightChild->left;
            }
            if (rightChild->left == NULL) {
                rightChild->left = curr;
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                rightChild->left = NULL;
                curr = curr->left;
            }
        }
    }

    reverse(result.begin(), result.end());
    return result;
}