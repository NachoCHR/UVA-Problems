// autor: andrewome
// fuente: https://github.com/andrewome/kattis-problems/blob/master/joinstrings.cpp

#include <bits/stdc++.h>
using namespace std;

// Esta función recursiva se utiliza para imprimir las cadenas concatenadas en el orden correcto. 
void printRecursively(vector<vector<int>> &v, vector<string> &s, int idx) { // Se pasa un vector de vectores "v" que contiene los índices de las cadenas que deben concatenarse, un vector "s" que contiene las cadenas originales y un índice "idx" que indica el índice de la cadena que se debe imprimir en primer lugar. 
    cout << s[idx]; // Imprime la cadena correspondiente al indice 'idx'.

    // Aca se llama a si misma para imprimir las cadenas correspondientes a los indicies contenidos en el vector v[idx]
    for(int i : v[idx]) {
        printRecursively(v, s, i);
    }
}

int main() {
    cin.tie(NULL);ios_base::sync_with_stdio(false); // No se que realiza esto. Al probar sacandolo, no paso nada. Lei que era como una funcion de entrada/salida mas rapida.
    int n; // Entero que almacena el numero de cadenas.
    cin >> n;
    vector<string> strings(n); // Este vector almacena las cadenas que se ingresan.
    for(int i=0;i<n;i++) {
        cin >> strings[i]; // Se leen las n cadenas a ingresar y se almacenan.
    }

   
    int idx1, idx2, lastIdx = 0; // Declaracion de indices a concatenar (idx1 e idx2).
    vector<vector<int>> v; // Se crea un vector de vectores que almacena los indices de las cadenas que deben concatenarse en cada posicion. 
    v.assign(n, vector<int>()); 
    for(int i=0;i<n-1;i++) { // for que lee los indices de las cadenas a unir.
        cin >> idx1 >> idx2; // Se leen los indices de las cadenas que se uniran.
        idx1--;idx2--; // Se les resta uno para convertirlos en indices del vector.
        v[idx1].push_back(idx2); // Se agrega 'idx2' a la lista de 'idx1' indicando que 'idx2' es su sucesor. 
        lastIdx = idx1; //  Se actualiza el valor de 'lastIdx' con el valor de 'idx1' para asegurarse que la raiz del arbol esta en el ultimo indice que se lee de la entrada.
    }
    /*
    Al final, el segmento de codigo anterior se construye un grafo dirigido a partir de los indices de las cadenas a unir.
    */


    
    // Finalmente, se llama a la función "printRecursively" para imprimir las cadenas concatenadas en el orden correcto. Se pasa el vector de vectores "v", el vector de cadenas "strings" y el índice "lastIdx" como argumentos. Luego se imprime un salto de línea para separar la salida del siguiente caso de prueba.
    printRecursively(v, strings, lastIdx);
    cout << endl;
}