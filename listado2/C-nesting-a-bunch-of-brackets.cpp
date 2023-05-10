// autoria: ackoroa 
// fuente: https://github.com/ackoroa/UVa-Solutions/blob/master/UVa%20551%20-%20Nesting%20a%20Bunch%20of%20Brackets/src/UVa%20551%20-%20Nesting%20a%20Bunch%20of%20Brackets.cpp


#include <cstdio>
#include <stack>
#include <cstring>
#include <iostream>
using namespace std;

stack<char> checker; // se crea una pila para verificar si los simbolos de apertura y cierre estan bien anidados. 

bool isOpening(char c) {
	if (c == '(' || c == '[' || c == '<' || c == '{')
		return true;
	return false;
}

bool isClosing(char c) {
	if (c == ')' || c == ']' || c == '>' || c == '}')
		return true;
	return false;
}

int main() {
	char s[3001];
	while (gets(s)) { // Esta funcion lee una cadena de caracteres en ciclo.
		int count = 0; // este contador almacena la cantidad de caracteres leidos.
		int len = strlen(s), i; // enteros que almacenan largo de la string y un contador del for.
		for (i = 0; i < len; i++) {
			count++;
			if (isOpening(s[i])) {
				if (s[i] == '(' && s[i + 1] == '*') {
					checker.push('*');
					i++;
				} else {
					checker.push(s[i]);
				}
			} else if (isClosing(s[i]) || (s[i] == '*' && s[i + 1] == ')')) {
				if (checker.empty())
					break;
				if (s[i] == '*') {
					if (checker.top() != '*') {
						break;
					}
					checker.pop();
					i++;
				} else if (s[i] == ')') {
					if (checker.top() != '(') {
						break;
					}
					checker.pop();
				} else if (s[i] == ']') {
					if (checker.top() != '[') {
						break;
					}
					checker.pop();
				} else if (s[i] == '>') {
					if (checker.top() != '<') {
						break;
					}
					checker.pop();
				} else if (s[i] == '}') {
					if (checker.top() != '{') {
						break;
					}
					checker.pop();
				}
			}
		}

		if (i < len || !checker.empty()) {
			if (i>=len && !checker.empty())
				count++;
			printf("NO %d\n", count);
		} else
			printf("YES\n");

		while (!checker.empty())
			checker.pop();
	}

	return 0;
}