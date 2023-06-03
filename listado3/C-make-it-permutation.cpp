// autoria: doporto06 
// fuente: vjudge status.

#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t; // Lee el número de casos de prueba

  while (t--) { // Itera sobre cada caso de prueba
    map<long long int, long long int> perm; // Crea un mapa para almacenar los valores y sus frecuencias
    int n;
    long long int c, d;
    cin >> n >> c >> d; // Lee los valores n, c y d

    long long int cost = n * c + d; // Calcula el costo inicial

    for (int i = 0; i < n; i++) {
      long long int aux;
      cin >> aux; // Lee cada número del caso de prueba
      perm[aux] += 1; // Incrementa la frecuencia del número en el mapa
    }
    
    map<long long int, long long int>::iterator it = perm.begin(); // Crea un iterador para recorrer el mapa
    int aux = 1; // Variable auxiliar para contar la posición actual

    while (it != perm.end()) { // Itera sobre los elementos del mapa
      long long int cost1 = (it->first - aux) * d; // Calcula el costo de eliminar elementos del mapa y reemplazarlos por el siguiente valor
      cost1 += (n - aux) * c; // Añade el costo de eliminar los elementos restantes y reemplazarlos por el último valor
      cost = min(cost1, cost); // Actualiza el costo mínimo si se encuentra un costo más bajo
      it++; // Avanza al siguiente elemento del mapa
      aux++; // Incrementa el contador de posición
    }

    cout << cost << endl; // Imprime el costo mínimo para el caso de prueba actual
  }

  return 0;
}
