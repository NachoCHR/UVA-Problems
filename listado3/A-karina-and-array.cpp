#include <bits/stdc++.h>

using namespace std;

int main(){
    int cant_casos;
    cin>>cant_casos;
    cin.ignore();
    while(--cant_casos){
        int tam;
        cin>>tam;
        cin.ignore();
        vector<int> arreglo;
        while(--tam){
            int num;
            cin>>num;
            cin.ignore();
            arreglo.push_back(num);
        }
        // Aqui viene lo chido.

        for(int i=0;i<arreglo.size();++i){
            cout<<arreglo[i];
        }
        cout<<endl;

    }
    return 0;
}