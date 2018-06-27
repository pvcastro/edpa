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

Node *root = NULL;

void add_node(Node *new_node) {

	if(root == NULL){
		root = new_node;
	}
	else{
		Node *current_node = root;

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
}

int main() {
	add_node(new Node(50));
	add_node(new Node(10));
	add_node(new Node(60));
	add_node(new Node(61));

	return 0;
}
