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

Node root(50);

void add_node(Node *new_node) {
    Node *current_node = &root;
    
    while(current_node == NULL) {
        if(new_node->value < current_node->value) {
            
        }
        else if(new_node->value > current_node->value) {
            
        }
        else if(new_node->value < current_node->value) {
            cout << "Nó idêntico já encontrado!";
        }
    }
}

main() {
   //cout << root.value;
   /*Node *mine;
   mine = &root;
   cout << mine->value;*/
}