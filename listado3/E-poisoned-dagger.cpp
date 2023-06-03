// autoria: diss1701
// fuente: vjudge status

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t; // Lee el número de casos de prueba

    while (t--)
    {
        long long monocarp, damage;
        cin >> monocarp >> damage; // Lee los valores de monocarp y damage

        long long array[monocarp];
        for (auto i = 0; i < monocarp; i++)
        {
            cin >> array[i]; // Lee los elementos del arreglo
        }

        long long minD = 1, maxD = damage;
        while (minD <= maxD)
        {
            long long promedio = minD + (maxD - minD) / 2; // Calcula el promedio entre minD y maxD

            long long count = 0;
            for (auto i = 0; i < monocarp - 1; i++)
            {
                if (promedio > array[i + 1] - array[i])
                {
                    count += (array[i + 1] - array[i]); // Suma la diferencia entre elementos si es menor que promedio
                }
                else
                {
                    count += promedio; // Suma promedio si es mayor o igual que la diferencia entre elementos
                }
            }
            count += promedio;

            if (count < damage)
            {
                minD = promedio + 1; // Actualiza minD si count es menor que damage
            }
            else
            {
                maxD = promedio - 1; // Actualiza maxD si count es mayor o igual que damage
            }
        }

        cout << minD << endl; // Imprime el valor mínimo de promedio encontrado
    }

    return 0;
}
