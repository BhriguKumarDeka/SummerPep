#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
  int data;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int val){
    data = val;
    left = right = NULL;
  }
};

void preOrder(TreeNode* root){
  if(root == NULL) return;
  cout<<root->data<<" ";
  preOrder(root->left);
  preOrder(root->right);
}
void inOrder(TreeNode* root){
  if(root == NULL) return;
  inOrder(root->left);
  cout<<root->data<<" ";
  inOrder(root->right);
}
void postOrder(TreeNode* root){
  if(root == NULL) return;
  postOrder(root->left);
  postOrder(root->right);
  cout<<root->data<<" ";
}

int main(){
  TreeNode* root = new TreeNode(1);

  return 0;
}