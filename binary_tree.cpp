#include <iostream>
#include <string>
#include <stack>

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

	if (root == NULL) {
		root = new_node;
	} else {
		Node *current_node = root;

		while (current_node != NULL) {
			if (new_node->value < current_node->value) {
				if (current_node->left != NULL) {
					current_node = current_node->left;
				} else {
					current_node->left = new_node;
					break;
				}
			} else if (new_node->value > current_node->value) {
				if (current_node->right != NULL) {
					current_node = current_node->right;
				} else {
					current_node->right = new_node;
					break;
				}
			} else if (new_node->value < current_node->value) {
				cout << "Nó idêntico já encontrado!";
			}
		}
	}
}

void display() {
	std::cout << "tree";
}

void buildTree(stack<string> leaves) {
	// Enquanto tiver folhas na pilha de folhas...
	while (!leaves.empty()) {
		// Obtém a última linha de folhas adicionada
		string lastLeaves = leaves.top();
		for (int j = 0; j < lastLeaves.length(); j++) {
			// Para cada folha da linha, adiciona a folha na árvore
			int value = std::stoi(lastLeaves.substr(j, 1));
			add_node(new Node(value));
		}
		leaves.pop();
	}
	// Exibe a árvore de acordo com algum percurso
	display();
	std::cout << '\n';
}

int main() {
//	add_node(new Node(50));
//	add_node(new Node(10));
//	add_node(new Node(60));
//	add_node(new Node(61));

	std::stack<string> leaves;

	for (std::string line; std::getline(std::cin, line);) {
		//std::cout << line << std::endl;
		//line = line.trim();
		if (line.empty()) {
			// Se estiver vazia, continua
			continue;
		} else if (line.compare("*")) {
			// Se chegou ao final de uma árvore, constrói a árvore e continua para a próxima
			buildTree(leaves);
			root = NULL;
		} else if (line.compare("$")) {
			// Se chegou ao final da última árvore, constrói a árvore e finaliza
			buildTree(leaves);
			return 0;
		} else {
			// Adiciona a linha contendo os nós na pilha de folhas
			leaves.push(line);
		}
	}

	return 0;
}
