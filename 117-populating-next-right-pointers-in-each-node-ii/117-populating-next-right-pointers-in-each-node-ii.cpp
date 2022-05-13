/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL){
            return NULL;
        }
        queue<Node*> que;
        que.push(root);
        while(!que.empty()){
            int level = que.size();
            Node *currRight = NULL;
            for(int i = 1 ; i <= level ; i++){
                Node* top = que.front();
                top->next = currRight;
                currRight = top;
                if(top->right) que.push(top->right);
                if(top->left) que.push(top->left);
                que.pop();
            }
        }
        return root;
    }
};












