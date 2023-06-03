// autoria: BrendanRubila
// fuente: vjudge status

#include <bits/stdc++.h>
using namespace std;

// Función que verifica si se puede reordenar el vector 'a' de manera que la suma de 'a[i]' y 'b[i]' sea menor o igual que 'x' para todo 'i'
bool reorder(vector<long long> a, vector<long long> b, int x)
{
    sort(b.rbegin(), b.rend()); // Ordena el vector 'b' en orden descendente para maximizar los valores que se sumarán a 'a'

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] + b[i] > x)
        {
            return false; // Si la suma de 'a[i]' y 'b[i]' es mayor que 'x', retorna falso indicando que no se puede cumplir la condición
        }
    }
    return true; // Si la condición se cumple para todos los elementos, retorna verdadero indicando que se puede reordenar 'a'
}

int main()
{
    int n, x, testcases;
    cin >> testcases; // Lee el número de casos de prueba

    while (testcases--)
    {
        cin >> n >> x; // Lee los valores de 'n' y 'x'

        vector<long long> a(n); // Crea un vector 'a' de tamaño 'n' para almacenar los valores a reordenar
        vector<long long> b(n); // Crea un vector 'b' de tamaño 'n' para almacenar los valores originales

        for (int i = 0; i < n; i++)
        {
            cin >> b[i]; // Lee los elementos del vector 'b'
        }

        if (reorder(a, b, x))
        {
            cout << "YES" << endl; // Si es posible reordenar los vectores según la condición dada, imprime "YES"
        }
        else
        {
            cout << "NO" <<endl; // Si no es posible, imprime "NO"
        }
    }

    return 0;
}
