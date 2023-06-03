// autoria: diss1701
// fuente: Vjudge status.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testCases;
    cin >> testCases; // Lee el número de casos de prueba

    while (testCases--)
    { // Itera sobre cada caso de prueba
        int n, index, count = 0;
        cin >> n; // Lee el tamaño del arreglo
        map<int, int> matryoskas; // Crea un mapa para almacenar los valores y sus frecuencias

        for (int i = 0; i < n; i++)
        {
            cin >> index; // Lee cada elemento del arreglo
            matryoskas[index]++; // Incrementa la frecuencia del elemento en el mapa
            matryoskas[index + 1]--; // Decrementa la frecuencia del siguiente elemento en el mapa
        }

        for (auto &it : matryoskas)
        {
            count += abs(it.second); // Calcula la suma de las frecuencias absolutas en el mapa
        }

        int finalRes = count / 2; // Divide la suma de frecuencias por 2
        cout << finalRes << endl; // Imprime el resultado final para el caso de prueba actual
    }

    return 0;
}
