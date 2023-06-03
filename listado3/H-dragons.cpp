// autor: D0ggos
// fuente: vjudge status

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Función de comparación para ordenar los dragones en base a su fuerza y bonificación
bool comparicion(pair<int,int> a, pair<int, int> b){
    if (a.first != b.first){
        return a.first < b.first;
    }
    else{
        return a.second > b.second;
    }
}

int main(){
    int kirito_strength, n;
    bool yesOrNo = true;

    // Entrada de la fuerza de Kirito y el número de dragones
    cin >> kirito_strength >> n;

    vector<pair<int,int>> dragons; // Vector para almacenar los pares de fuerza y bonificación de los dragones

    // Entrada de la fuerza y bonificación de cada dragón y almacenamiento en el vector
    for (int i = 0; i < n; i++){
        int dragon_strength, dragon_bonus;
        cin >> dragon_strength >> dragon_bonus;
        dragons.emplace_back(dragon_strength, dragon_bonus);
    }

    // Ordenar los dragones en base a su fuerza y bonificación utilizando la función de comparación
    sort(dragons.begin(), dragons.end(), comparicion);

    // Recorrer los dragones y determinar si Kirito puede derrotarlos a todos
    for (int i = 0; i < n; i++){
        if (kirito_strength > dragons[i].first){
            // Si la fuerza de Kirito es mayor a la del dragón, incrementar su fuerza con la bonificación del dragón
            kirito_strength += dragons[i].second;
        }
        else{
            // Si la fuerza de Kirito es menor o igual a la del dragón, Kirito no puede derrotarlo y se imprime "NO"
            cout << "NO" << "\n";
            yesOrNo = false;
            break;
        }
    }

    // Si Kirito puede derrotar a todos los dragones, se imprime "YES"
    if (yesOrNo == true) cout << "YES" << "\n";

    return 0;
}