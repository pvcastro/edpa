/*
 * Main.cpp
 *
 *  Created on: 22 de jun de 2018
 *      Author: home
 */

#include "Main.h"
#include <stack>
#include <iostream>

namespace edpa {

Main::Main() {

}

Main::~Main() {
	// TODO Auto-generated destructor stub
}

int main(int argc, char **argv) {
	std::stack<int> mystack;

	for (int i = 0; i < 5; ++i)
		mystack.push(i);

	std::cout << "Popping out elements...";
	while (!mystack.empty()) {
		std::cout << ' ' << mystack.top();
		mystack.pop();
	}
	std::cout << '\n';

	return 0;
}

}
