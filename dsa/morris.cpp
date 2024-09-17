#include<bits/stdc++.h>
using namespace std;
//morris inorder
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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

vector<int> morrisInorder(TreeNode* root) {
    vector<int> result;
    TreeNode* curr = root;
    while (curr != NULL) {
        if (curr->left == NULL) {   
            result.push_back(curr->val);
            curr = curr->right;
        } else {
            TreeNode* leftChild = curr->left;
            while (leftChild->right != NULL && leftChild->right != curr) {
                leftChild = leftChild->right;
            }
            if (leftChild->right == NULL) {
                leftChild->right = curr;
                curr = curr->left;
            } else {
                leftChild->right = NULL;
                result.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return result;
}
vector <int> morrisPreorder(TreeNode* root)
{
    vector<int> result;
    TreeNode* curr = root;
    while (curr != NULL) {
        if (curr->left == NULL) {
            result.push_back(curr->val);  // Visit the node
            curr = curr->right;
        } else {
            TreeNode* leftChild = curr->left;
            while (leftChild->right != NULL && leftChild->right != curr) {
                leftChild = leftChild->right;
            }
            if (leftChild->right == NULL) {
                result.push_back(curr->val);  // Visit the node
                leftChild->right = curr;
                curr = curr->left;
            } else {
                leftChild->right = NULL;
                curr = curr->right;
            }
        }
    }
    return result;
}
\
// line 60 ko line 55-56 je beech me daal do


TreeNode* buildTree() {
    int val;
    cin >> val;
    
    if(val == -1) return nullptr;  // -1 represents null node
    
    TreeNode* root = new TreeNode(val);
    
    cout << "Enter left child of " << val << " (-1 for null): ";
    root->left = buildTree();
    
    cout << "Enter right child of " << val << " (-1 for null): ";
    root->right = buildTree();
    
    return root;
}
int main(){
    cout << "Enter the root value (-1 for null): ";
    TreeNode* root = buildTree();
    // Perform Morris inorder traversal
    vector<int> inorder = morrisInorder(root);
    vector<int> postorder = morrisPostorder(root);
    vector<int> preorder = morrisPreorder(root);
    
    


    // Print the result
    cout << "Inorder traversal: ";
    for(int val : inorder) {
        cout << val << " ";
    }
    cout << endl;


    // Print the result
    cout << "postorder traversal: ";
    for(int val : postorder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}





