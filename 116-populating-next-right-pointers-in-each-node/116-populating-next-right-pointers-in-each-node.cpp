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
        if(root == NULL) return root;
        queue<Node*> que;
        que.push(root);
        while(!que.empty()){
            int level = que.size();
            for(int i = 1 ; i <= level ; i++){
                auto top = que.front();
                que.pop();
                if(i == level){
                    top->next = NULL;
                }else{
                    top->next = que.front();
                }
                if(top->left) que.push(top->left);
                if(top->right) que.push(top->right);
            }
        }
        return root;
    }
};