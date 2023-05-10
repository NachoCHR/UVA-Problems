#include <bits/stdc++.h>

using namespace std;

int buscarjugador(string nombre, vector<pair<string,int>> jugadores){
  int pos = 0;
  for(int i=0;i<jugadores.size();++i){
    if(nombre == jugadores[i].first){
      pos = i;
      break;
    }
 }
  return pos;
}


int main(){
  int cant_jugadores, score_max, lineas_puntos;
  bool Noganadores = true;
  vector<string> ganadores;
  cin>>cant_jugadores;
  cin>>score_max;
  cin>>lineas_puntos;
  cin.ignore();

  vector<pair<string,int>> jugadores;

  while(cant_jugadores--){
    pair<string,int>jugador;
    getline(cin,jugador.first);
    jugador.second = 0;
    jugadores.push_back(jugador);
  }

  while(lineas_puntos--){
    string nombre;
    string puntos;
    string jugador_puntos;
    getline(cin,jugador_puntos);
    stringstream st(jugador_puntos);
    getline(st,nombre,' ');
    getline(st,puntos,' ');
    int pos = buscarjugador(nombre,jugadores);
    int aux_puntos = stoi(puntos);
    jugadores[pos].second += aux_puntos;
    if(jugadores[pos].second >= score_max){
      //ganadores.push_back(jugadores[pos].first);
      cout<<jugadores[pos].first+" wins!"<<endl;
      Noganadores = false;
    } 
  }
  if(Noganadores) cout<<"No winner!"<<endl;

  return 0;
}
