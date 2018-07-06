#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include "simple_stack.h"
#include "simple_stack.cpp"
#include "simple_queue.h"
#include "simple_queue.cpp"

using namespace std;

/**
 * Classe que representa os nós da Árvore Binária de Busca
 *
 */
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

// Nó que representa a raiz da árvore
Node *root = NULL;

/**
 * Método responsável por adicionar nós na Árvore Binária de Busca, de acordo com suas propriedades.
 * Garante que cada nó tem na sua sub-árvore esquerda somente valores menores do que o do nó, e somente
 * valores maiores na sub-árvore direita.
 *
 */
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
				cout << "Nó idêntico já encontrado! " << current_node->value
						<< "\n";
				break;
			}
		}
	}
}

/**
 * Método responsável pelo percurso em pré-ordem, imprimindo os nós no percurso em profundidade.
 *
 */
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

/**
 * Método responsável pela impressão dos nós no percurso em largura.
 *
 */
void breadth_traversal(Node *root) {
	cout << "Imprimindo os nós da árvore em largura: \n";
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

/**
 * Método responsável pelo cálculo da altura da árvore.
 *
 */
int get_tree_height(Node* node) {
	if (node == NULL)
		return 0;
	else {
		int left_depth = get_tree_height(node->left);
		int right_depth = get_tree_height(node->right);

		if (left_depth > right_depth) {
			return (left_depth + 1);
		} else {
			return (right_depth + 1);
		}
	}
}

/**
 * Realiza a divisão da string informada, de acordo com o separador especificado. Armazenando no vetor
 * cada elemento obtido a partir da separacão da string.
 *
 */
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

/**
 * Método responsável construcão da árvore a partir da pilha de listas de folhas.
 *
 */
void build_tree(simple_stack<string> &leavesStack) {
	// Enquanto tiver folhas na pilha de folhas...
	clock_t begin = clock();
	cout << "\n";
	cout << "Construindo a partir das folhas:\n\n";
	while (!leavesStack.empty()) {
		// Obtém a última linha de folhas adicionada
		string lastLeaves = leavesStack.top();
		cout << lastLeaves << "\n";
		std::vector<string> leaves;
		split(lastLeaves, leaves, ' ');
		for (int j = 0; j < leaves.size(); j++) {
			// Para cada folha da linha, adiciona a folha na árvore
			int value = std::stoi(leaves[j]);
			add_node(new Node(value));
		}
		leavesStack.pop();
	}
	cout << '\n';
	clock_t end_build = clock();
	// Calcula a altura da árvore
	cout << "Altura da árvore: " << get_tree_height(root) << "\n\n";
	clock_t end_height = clock();
	// Exibe a árvore de acordo com algum percurso
	breadth_traversal(root);
	clock_t end_breadth_traversal = clock();
	preorder_traversal(root);
	clock_t end_preorder_traversal = clock();
	cout << '\n';
	cout << "==================================================\n";
	cout << "Tempo de execução dos algoritmos:\n";
	cout << "==================================================\n";
	cout << "  Duração da construção da árvore: "
			<< double(end_build - begin) / (CLOCKS_PER_SEC / 1000) << " ms. \n";
	cout << "  Duração do cálculo da altura: "
			<< double(end_height - end_build) / (CLOCKS_PER_SEC / 1000)
			<< " ms. \n";
	cout << "  Duração do percurso em largura: "
			<< double(end_breadth_traversal - end_height)
					/ (CLOCKS_PER_SEC / 1000) << " ms. \n";
	cout << "  Duração do percurso em profundidade: "
			<< double(end_preorder_traversal - end_breadth_traversal)
					/ (CLOCKS_PER_SEC / 1000) << " ms. \n";
	cout << "==================================================\n";
	cout << '\n';
}

/**
 * Método responsável pela execucão da rotina da solucão. Faz uma leitura dos dados de entrada a
 * partir do caminho especificado no vetor de argumentos, e percorre cada linha do arquivo. Se for
 * uma lista de folhas armazena em uma pilha, se for o carácter '*' indica o fim da lista de folhas
 * de uma árvore, e se for o carácter '$' indica o final dos dados no arquivo.
 *
 */
int main(int argc, char* argv[]) {

	root = NULL;

	string line;
	string path = argv[1];
	cout << "...lendo dados em " << path << "\n\n";

	simple_stack<string> leaves;
	int linha = 1;

	ifstream myfile(path);
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			if (line.empty()) {
				// Se estiver vazia, continua
				cout << path << "vazio";
				cout << '\n';
				continue;
			} else if (line == "*") {
				// Se chegou ao final de uma árvore, constrói a árvore e continua para a próxima
				build_tree(leaves);
				root = NULL;
				int linha = 1;
			} else if (line == "$") {
				// Se chegou ao final da última árvore, constrói a árvore e finaliza
				build_tree(leaves);
				root = NULL;
				int linha = 1;
				return 0;
			} else {
				cout << "linha: " << linha << ": " << line << '\n';
				// Adiciona a linha contendo os nós na pilha de folhas
				leaves.push(line);
				linha++;
			}
		}
		myfile.close();
	} else {
		cout << path << " não encontrado";
	}

	return 0;
}
