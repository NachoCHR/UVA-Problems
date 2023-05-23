// Aceptado
// Autoria: propio.

#include <bits/stdc++.h>

using namespace std;

int main(){
    int cant_casos;
    cin>>cant_casos;
    cin.ignore();
    
    for(int a=0;a<cant_casos;a++){
        //cout<<"e"<<endl;
        int tam;
        cin>>tam;
        cin.ignore();
        vector<long long> arreglo;
        for(int b=0; b<tam;b++){
            long long num;
            cin>>num;
            arreglo.push_back(num);
        }
        // Aqui viene lo chido.
        // Ordenar de menor a mayor.
        sort(arreglo.begin(), arreglo.end());
        
        // Ahora sabemos que los numeros mas grandes se encuentran al principio o al final, por lo que:
        long long dos_primeros = arreglo[0] * arreglo[1];
        long long dos_ultimos = arreglo[tam-1] * arreglo[tam-2];
        cout<<endl;
        // Comparamos cual de los dos es mayor.
        if(dos_primeros > dos_ultimos)
            cout<<dos_primeros;
        else 
            cout<<dos_ultimos;

        /*
        for(auto& element: arreglo){
            cout<<element<< " ";
        }
        cout<<endl; 
        */
    }
    return 0;
}