#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
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


vector<vector<int>> levelOrderTraversal(TreeNode* root){
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            TreeNode* node = q.front(); q.pop();
            if(node->left)  q.push(node->left);
            if(node->right) q.push(node->right);
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
}
int main(){
    cout << "Enter the root value (-1 for null): ";
    TreeNode* root = buildTree();

    vector<vector<int>> levels =  levelOrderTraversal(root);
    cout<<"level Order Traversal"<<endl;
    for(auto ele:levels){
        for(auto it:ele){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}