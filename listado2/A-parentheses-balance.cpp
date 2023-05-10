#include <bits/stdc++.h>

using namespace std;

int main(){
    int can_casos;
    cin>>can_casos;
    cin.ignore();
    for(int i=0;i<can_casos;++i){
        string cadena;
        getline(cin,cadena);
        stack<char> pila;
        int a=0;
        bool flag = true;
        while(a < cadena.length()){
            if(cadena[a] == '(' || cadena[a] == '['){
                pila.push(cadena[a]);
                ++a;
            }else if(cadena[a] == ')'){
                //compara que el ultimo elemento en la pila sea: '('
                if(pila.empty() || pila.top() != '('){
                    flag = false;
                    break;
                }
                pila.pop();
                a++;
            }else if(cadena[a] == ']'){
                //compara que el ultimo elemento de la pila sea el '['
                if(pila.empty() || pila.top() != '['){
                    flag = false;
                    break;
                }
                pila.pop();
                a++;
            }
        }
        if(!pila.empty()){
            flag = false;
        }
        if(flag)
            cout<<"Yes"<<endl;
        else 
            cout<<"No"<<endl;
    }
    
    return 0;
}



