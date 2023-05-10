#include <bits/stdc++.h>

using namespace std;

int main(){
    bool Noganadores = true;
    int cant_jugadores, score_min, lines;
    cin>>cant_jugadores;
    cin>>score_min;
    cin>>lines;
    cin.ignore();

    map<string, int> map_jugadores;

    while(cant_jugadores--){
        string nombre;
        cin>>nombre;

        map_jugadores[nombre] = 0;
    }

    while(lines--){
        string nombre;
        int puntaje;
        cin>>nombre;
        cin>>puntaje;
        if(map_jugadores[nombre] == -1) continue;
        map_jugadores[nombre] += puntaje;
        if(map_jugadores[nombre] >= score_min){
            cout<<nombre+" wins!"<<endl;
            Noganadores = false;
            map_jugadores[nombre] = -1;
        }
    }
   
   
   if(Noganadores){
    cout<<"No winner!"<<endl;
   }
   
    return 0;

}


/*
 
    vector<pair<string, int>> planilla_jugadores;
    for (const auto& [nombre, puntaje] : map_jugadores) {
       /* 
        if(puntaje >= score_min){
            cout<<nombre+" wins!"<<endl;
            Noganadores = false;
        }
        
        planilla_jugadores.push_back(make_pair(nombre,puntaje));
        
       //planilla_jugadores.push_back(make_pair(nombre,puntaje));
    }
    
    sort(planilla_jugadores.begin(),planilla_jugadores.end(),
            [](const pair<string,int>& x, const pair<string,int>& y) {
                // compara el segundo valor
                if (x.second != y.second) {
                    return x.second < y.second;
                }
 
                // comparar primero solo si el segundo valor es igual
                return x.first < y.first;
            });
    


    for (const auto& [nombre, puntaje] : planilla_jugadores) {
        if(puntaje >= score_min){
            cout << nombre+" wins!"<< endl;
        }
        Noganadores = false;
    }
*/