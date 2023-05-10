// autoria: ackoroa 
// fuente: https://github.com/ackoroa/UVa-Solutions/blob/master/UVa%20551%20-%20Nesting%20a%20Bunch%20of%20Brackets/src/UVa%20551%20-%20Nesting%20a%20Bunch%20of%20Brackets.cpp


#include <cstdio>
#include <stack>
#include <cstring>
#include <iostream>
using namespace std;

stack<char> checker; // se crea una pila para verificar si los simbolos de apertura y cierre estan bien anidados. 

// Funcion isOpening retorna verdadero si es un caracter de apertura.
bool isOpening(char c) {
	if (c == '(' || c == '[' || c == '<' || c == '{')
		return true;
	return false;
}

// Funcion isClising retorna verdadero si es un caracter de cierre.
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
			count++; // Se aumenta el contador cada vez que pasamos un caracter. 
			if (isOpening(s[i])) { // Comprueba si el caracter que estamos leyendo es de apertura.
				if (s[i] == '(' && s[i + 1] == '*') { // Si resulta ser un caracter de apertura, verifica si se trata del caracter "(*". 
					checker.push('*'); // Ingresa el caracter "*" a la cola. Esto pasa cuando se trata del caracter "(*".
					i++;
				} else {
					checker.push(s[i]);
				}
			} else if (isClosing(s[i]) || (s[i] == '*' && s[i + 1] == ')')) { // Comprueba si el caracter que estamos leyendo es de cierre.
				if (checker.empty()) // si la pila se encuentra vacia se sale del bucle puesto que no hay un caracter de apertura que corresponda con el caracter de cierre que estamos leyendo.
					break;
				if (s[i] == '*') { // Verifica que el caracter con el que nos encotramos es "*", puesto que es el primer caracter que se lee del caracter especial "*)".
					if (checker.top() != '*') { // Si el ultimo caracter ingresado en la pila no coincide con el caracter *, que es el caracter que almacenamos cuando se tiene "(*", se sale del bucle puesto que no es el caracter de apertura correspondiente para el caracter de cierre "*)".
						break;
					}
					checker.pop(); // Si el caracter de cierre "*)" corresponde con el ultimo caracter de apertura ingresado en la pila, entonces se saca de la pila.
					i++;
				} else if (s[i] == ')') {			// Los siguientes casos siguen la misma logica anterior. Buscar si el ultimo caracter de apertura ingresado en la pila corresponde con el caracter de cierre que se esta leyendo actualmente. SI no coincide nos salimos del bucle. 
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

		if (i < len || !checker.empty()) { // Si no se completo el bucle o si la pila no se encuentra vacia. 
			if (i>=len && !checker.empty()) // Si se completo el bucle y la pila no esta vacia
				count++;
			printf("NO %d\n", count); // se imprime NO junto a la ultima posicion que se leyo de forma correcta. Esto puesto que o no se completo el bucle y quedaron elementos en la pila o se completo y aun asi quedaron elementos en la pila sin sacar.
		} else
			printf("YES\n"); // imprime yes si se termino el bucle y la pila esta vacia.

		while (!checker.empty())
			checker.pop(); // se vacia la pila para la siguiente string. 
	}

	return 0;
}


/*
		EXPLICACION DEL CODIGO:

El programa primero define dos funciones, `isOpening` e `isClosing`, que devuelven verdadero si el carácter dado es un carácter de apertura o cierre, respectivamente. Luego, se define una pila de caracteres llamada `checker`.
El programa lee la entrada de la cadena utilizando la función `gets` y entra en un bucle `while` que procesa cada línea de entrada. Dentro del bucle, se inicializan una variable de contador `count` y una variable `len` que contiene la longitud de la cadena de entrada. Luego, se recorre cada carácter de la cadena y se incrementa el contador `count`.
Si el carácter es un carácter de apertura, se comprueba si es un carácter de apertura de comentario "(*" y se agrega a la pila `checker`.
Si el carácter es un carácter de cierre o un carácter de cierre de comentario "*)", se comprueba si la pila `checker` está vacía o si el carácter de cierre coincide con el carácter de apertura más reciente en la pila. Si no coincide o si la pila está vacía, se rompe el bucle y se imprime "NO" junto con el contador `count`. Si se completa el bucle y la pila no está vacía, también se imprime "NO" junto con el contador `count`.
Si el bucle se completa y la pila está vacía, se imprime "YES" para indicar que la cadena de entrada tenía una anidación correcta de corchetes, paréntesis, llaves y signos de menor y mayor que.
Por último, se vacía la pila `checker` para prepararse para la próxima línea de entrada.
*/