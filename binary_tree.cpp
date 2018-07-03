#include <iostream>
#include <vector>
#include <string>
//#include <stack>
//#include <queue>
#include "simple_stack.h"
#include "simple_stack.cpp"
#include "simple_queue.h"
#include "simple_queue.cpp"

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
			} else if (new_node->value == current_node->value) {
				cout << "Nó idêntico já encontrado! \n";
				break;
			}
		}
	}
}

//imprime os nós no percurso em prfundidade(pré-ordem)
void preorder_traversal(Node *root) {
	cout << "Imprimindo os nós da árvore em pré-ordem: \n";
	if (root == NULL) {
		cout << "Árvore Vazia. \n";
		return;
	}

	simple_stack<Node *> stack;
	stack.push(root);
	while (!stack.empty()) {
		Node *current_node = stack.top();
		cout << current_node->value << " ";
		stack.pop();

		if (current_node->right) {
			stack.push(current_node->right);
		}
		if (current_node->left) {
			stack.push(current_node->left);
		}
	}
	cout << "\n";

}

//imprime os nós no percurso em largura
void breadth_traversal(Node *root) {
	cout << "Imprimindo os nós árvore em largura: \n";
	if (root == NULL) {
		cout << "Árvore Vazia. \n";
		return;
	}

	simple_queue<Node *> queue;
	queue.push(root);
	while (!queue.empty()) {
		Node *current_node = queue.front();
		cout << current_node->value << " ";
		queue.pop();

		if (current_node->left) {
			queue.push(current_node->left);
		}
		if (current_node->right) {
			queue.push(current_node->right);
		}
	}
	cout << "\n";
}

size_t split(const string &txt, std::vector<string> &strs, char ch) {
	size_t pos = txt.find(ch);
	size_t initialPos = 0;
	strs.clear();

	// Decompose statement
	while (pos != std::string::npos) {
		strs.push_back(txt.substr(initialPos, pos - initialPos));
		initialPos = pos + 1;

		pos = txt.find(ch, initialPos);
	}

	// Add the last one
	strs.push_back(
			txt.substr(initialPos, std::min(pos, txt.size()) - initialPos + 1));

	return strs.size();
}

void build_tree(simple_stack<string> leavesStack) {
	// Enquanto tiver folhas na pilha de folhas...
	cout << "entrou no build tree\n";
	while (!leavesStack.empty()) {
		// Obtém a última linha de folhas adicionada
		string lastLeaves = leavesStack.top();
		cout << "últimas folhas: " << lastLeaves << "\n";
		std::vector<string> leaves;
		split(lastLeaves, leaves, ' ');
		for (int j = 0; j < leaves.size(); j++) {
			// Para cada folha da linha, adiciona a folha na árvore
			int value = std::stoi(leaves[j]);
			add_node(new Node(value));
		}
		leavesStack.pop();
	}
	// Exibe a árvore de acordo com algum percurso
	breadth_traversal(root);
	preorder_traversal(root);
	cout << '\n';
}

void test_tree() {
	//teste árvore nula
	preorder_traversal(root);
	breadth_traversal(root);

	//teste árvore 1
	add_node(new Node(50));
	add_node(new Node(10));
	add_node(new Node(60));
	add_node(new Node(5));
	add_node(new Node(65));
	add_node(new Node(65));

	//pré-ordem esperada: 50 10 5 60 65
	preorder_traversal(root);
	//percurso em largura esperada: 50 10 60 5 65
	breadth_traversal(root);

	root = NULL;
	//teste arvore 2
	add_node(new Node(6));
	add_node(new Node(2));
	add_node(new Node(7));
	add_node(new Node(1));
	add_node(new Node(4));
	add_node(new Node(9));
	add_node(new Node(3));
	add_node(new Node(5));
	add_node(new Node(8));
	add_node(new Node(10));

	//árvore em pré-ordem: 6 2 1 4 3 5 7 9 8 10
	preorder_traversal(root);
	//árvore em pré-ordem: 6 2 7 1 4 9 3 5 8 10
	breadth_traversal(root);

	root = NULL;
}

int main() {

	root = NULL;

	string lines[] = { "6 2 7 1", "4 9 3", "5 8", "0", "$" };

	simple_stack<string> leaves;
	//for (std::string line; std::getline(std::cin, line);) {
	for (int i = 0; i < sizeof(lines); i++) {
		string line = lines[i];
		if (line.empty()) {
			// Se estiver vazia, continua
			cout << "vazio";
			cout << '\n';
			continue;
		} else if (line == "*") {
			// Se chegou ao final de uma árvore, constrói a árvore e continua para a próxima
			build_tree(leaves);
			root = NULL;
		} else if (line == "$") {
			// Se chegou ao final da última árvore, constrói a árvore e finaliza
			build_tree(leaves);
			return 0;
		} else {
			cout << "adicionando linha na pilha: " << line << '\n';
			// Adiciona a linha contendo os nós na pilha de folhas
			leaves.push(line);
		}
	}

	return 0;
}
