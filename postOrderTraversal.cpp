/*
Tree: Postorder
Traversal
Complete the postOrder function in your editor below, which has parameter: a pointer to the root of a
binary tree. It must print the values in the tree's postorder traversal as a single line of space-separated
values.
Input Format
Our hidden tester code passes the root node of a binary tree to your postOrder function.
Constraints
1 Nodes in the tree 500
Output Format
Print the tree's postorder traversal as a single line of space-separated values.
Sample Input
1
\
 2
  \
   5
  / \
  3 6
  \
   4
Sample Output
4 3 6 5 2 1

solution:
*/

#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/


    void postOrder(Node *root) {
        if(root==NULL)
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.postOrder(root);
    return 0;
}
