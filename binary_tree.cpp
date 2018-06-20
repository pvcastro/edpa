#include <iostream>
using namespace std;

class Node {
    public:
        Node(int v) {
            value = v;
        }
        int value;
        Node* left;
        Node* right;
};

Node root(50);

main() {
   cout << "Hello World\n"; // prints Hello World
   cout << root.value;
   
   return 0;
}