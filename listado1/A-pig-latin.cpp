#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<string> words;
    string input;
    string aux;

    getline(cin, input); // Comando para leer una linea de texto.
    stringstream ss(input);
    while(getline(ss,aux,' ')){
        if(( aux[0]>= 65 && aux[0] <= 90) || (aux[0] >= 97 && aux[0] <=122)){
            if(aux[0] == 'a' || aux[0] == 'e' || aux[0] == 'i' || aux[0] == 'o' || aux[0] == 'u' || aux[0] == 'A' || aux[0] == 'E' || aux[0] == 'I' || aux[0] == 'O' || aux[0] == 'U'){
                if((aux[aux.length()-1]>=65 && aux[aux.length()-1] <=90) || (aux[aux.length()-1]>=97 && aux[aux.length()-1] <=122)){
                    aux = aux+"ay";
                    words.push_back(aux);     
                }else{
                    char ultim = aux[aux.length()-1];
                    aux.pop_back();
                    aux = aux+"ay";
                    aux = aux+ultim;
                    words.push_back(aux);
                }
                
            }else{
                if((aux[aux.length()-1]>=65 && aux[aux.length()-1] <=90) || (aux[aux.length()-1]>=97 && aux[aux.length()-1] <=122)){
                    char aux2 = aux[0];
                    aux.erase(aux.begin());
                    aux.push_back(aux2);
                    aux = aux + "ay";
                    words.push_back(aux);
                }else{
                    char ultim = aux[aux.length()-1];
                    aux.pop_back();
                    char aux2 = aux[0];
                    aux.erase(aux.begin());
                    aux.push_back(aux2);
                    aux = aux+"ay";
                    aux = aux+ultim;
                    words.push_back(aux);
                }
                
            }
        }else{
            words.push_back(aux);
        }        
    }
    string ret;
    for(int i = 0; i < words.size(); ++i ){
        if(i != words.size()-1){
            ret = ret + words[i] + ' ';
        }else{
            ret = ret + words[i];
        }
        
    }
    cout<<ret<<endl;
    return 0;
}


/*

int longitud = input.length();

    for(int i = 0 ; i < longitud; ++i){
        if(input[i] == 'A' || input[i]== 'a' || input[i] == 'E' || input[i]== 'e' || input[i] == 'I' || input[i]== 'i' || input[i] == 'O' || input[i]== 'o' || input[i] == 'U' || input[i]== 'u'){
            while(input[i]!='\n'){
                cout<<input[i];
            }
            cout<<"ay"<<endl;
        }else{
            
        }
*/