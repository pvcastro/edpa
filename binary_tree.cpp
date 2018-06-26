#include <iostream>
using namespace std;

class Node {
    public:
        Node(int v) {
            value = v;
            left = NULL;
            right = NULL;
        }
        int value;
        Node *left;
        Node *right;
};

Node root(51);

void add_node(Node *new_node) {
    Node *current_node = &root;

    while(current_node != NULL) {
        if(new_node->value < current_node->value) {
            if(current_node->left != NULL){
                current_node = current_node->left;
            }
            else{
            	current_node->left = new_node;
            	break;
            }
        }
        else if(new_node->value > current_node->value) {
        	if(current_node->right != NULL){
        		current_node = current_node->right;
        	}
            else{
            	current_node->right = new_node;
            	break;
            }
        }
        else if(new_node->value < current_node->value) {
            cout << "Nó idêntico já encontrado!";
        }
    }
}

int main() {
	/*
	cout << root.value << endl;
	Node esquerdo(21);
	root.left = &esquerdo;
	cout << root.left->value << endl;
	*/

	add_node(new Node(10));

	Node *direito = new Node(60);
	add_node(direito);

	direito = new Node(61);
	add_node(direito);

	/*
   Node *esquerdo = new Node(21);
   mine.left = &esquerdo;

   mine->left = Node esq(21);
   mine->left = new Node(21);
   mine = &root;
   cout << mine->value;
	 */
	return 0;
}
