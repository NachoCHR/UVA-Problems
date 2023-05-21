#include <bits/stdc++.h>

using namespace std;

int main(){
    int cant_casos;
    cin>>cant_casos;
    cin.ignore();
    for(int a=0;a<cant_casos;a++){
        cout<<"e"<<endl;
        int tam;
        cin>>tam;
        cin.ignore();
        vector<int> arreglo;
        for(int b=0; b<tam;b++){
            int num;
            cin>>num;
            cin.ignore();
            arreglo.push_back(num);
        }
        // Aqui viene lo chido.

        for(int i=0;i<arreglo.size();++i){
            cout<<arreglo[i]<< " ";
        }
        cout<<endl;

    }
    return 0;
}