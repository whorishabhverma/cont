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

vector<int> morris(TreeNode* root){
    vector<int> result;
    TreeNode* curr = root;
    while(curr!=NULL){
        if(curr->left==NULL){   
            result.push_back(curr->val);
            curr=curr->right;
        }
        else{
            TreeNode* leftChild = curr->left;
            while(leftChild->right != NULL){
                leftChild=leftChild->right;
            } 
            leftChild->right = curr;
            TreeNode* temp = curr;
            curr=curr->left;
            temp->left=NULL;
        }
        
    }
    return result;
}

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
    vector<int> inorder = morris(root);

    // Print the result
    cout << "Inorder traversal: ";
    for(int val : inorder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}