#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val)
  {
    data = val;
    left = right = NULL;
  }
};

/*
void insert(TreeNode* &root, int val){
    TreeNode* newNode = new TreeNode(val);

    if(root == NULL){
        root = newNode;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();

        if(curr->left == NULL){
            curr->left = newNode;
            return;
        } else {
            q.push(curr->left);
        }

        if(curr->right == NULL){
            curr->right = newNode;
            return;
        } else {
            q.push(curr->right);
        }
    }
}
*/

// Binary Search Tree Insert
TreeNode *insert(TreeNode *root, int val)
{
  if (root == NULL)
    return new TreeNode(val);

  if (val < root->data)
    root->left = insert(root->left, val);
  else
    root->right = insert(root->right, val);

  return root;
}

void preOrder(TreeNode *root)
{
  if (root == NULL)
    return;
  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}
void inOrder(TreeNode *root)
{
  if (root == NULL)
    return;
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}
void postOrder(TreeNode *root)
{
  if (root == NULL)
    return;
  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}

int countNodes(TreeNode* root){
  if(root == NULL) return 0;
  int x = countNodes(root->left);
  int y = countNodes(root->right);

  return x+y+1;
}

int countLeaves(TreeNode* root){
  if(root==NULL) return 0;
  if(root->left == NULL && root->right == NULL) return 1;
  int x = countLeaves(root->left);
  int y = countLeaves(root->right);

  return x+y;
}

int height(TreeNode* root){
  if(root==NULL) return -1;
  return 1 + max(height(root->left), height(root->right));
}

int sumofTree(TreeNode* root){
  if(root == NULL) return 0;
}

int main()
{
  TreeNode *root = new TreeNode(25);
  insert(root, 10);
  insert(root, 20);
  insert(root, 30);
  insert(root, 40);
  insert(root, 60);

  cout<<height(root);

  return 0;
}