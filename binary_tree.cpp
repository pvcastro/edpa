#include <iostream>
using namespace std;

class Node {
    public:
        Node(int v) {
            value = v;
        }
        int value;
        Node *left;
        Node *right;
};

Node root(51);

void add_node(Node *new_node) {
    Node *current_node = &root;
    
    while(current_node == NULL) {
        if(new_node->value < current_node->value) {
            if(current_node->left != NULL){
                current_node = current_node->left;
            }
        }
        else if(new_node->value > current_node->value) {
            
        }
        else if(new_node->value < current_node->value) {
            cout << "Nó idêntico já encontrado!";
        }
    }
}

main() {
   cout << root.value;
   Node esquerdo(21);
   root.left = &esquerdo;
   cout << root.left->value;
   //Node *esquerdo = new Node(21);
   //mine.left = &esquerdo;
   
   //mine->left = Node esq(21);
   //mine->left = new Node(21);
   //mine = &root;
   //cout << mine->value;
}
