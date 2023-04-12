/*
    Autor y fuente: https://github.com/Diusrex/UVA-Solutions/blob/master/492%20Pig-Latin.cpp
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool vowel[128]; // Crea un arreglo de bool.

bool IsLetter(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'); // Funcion para saber si el caracter con el cual
                                                             // se llama es letra o no. 
}

int main()
{
    vowel['A'] = vowel['a'] = vowel['E'] = vowel['e'] = vowel['I'] = vowel['i'] 
        = vowel['O'] = vowel['o'] = vowel['U'] = vowel['u'] = true; // Todos los espacion del arreglo de bool
                                                                    // correspondientes a las vocales, convertidas a int
                                                                    // se vuelven verdaderas. Esto se hace por conveniencia. A = 65, B = 66 ... Todas esas posiciones se vuelven verdaderas.
                                                            
    
    string line; // Line: guarda el string leido desde la entrada de la terminal.  
    while (getline(cin, line)) // Entra en un ciclo infinito y lee la entrada de la terminal. 
    {
        for (int i = 0; i < line.size(); ++i) // Con este for recorrimos la string ingresada en el input.
        {
            if (IsLetter(line[i])) //Llama a la funcion "IsLetter" para saber si lo que esta en la posicion "i" de la string pertenece a una letra.
            {
                char startingCharacter = line[i]; // Guarda la primera letra de cada palabra. En este caso de la primera palabra que se tiene al ingresar un texto. 
                if (vowel[startingCharacter]) // Si "stratingCharacter", que pertenece a la primera letra de la palabra, es una vocal, entonces la imprime y continua.
                    cout << startingCharacter;
                
                ++i; // aumenta el i en 1 para pasar a la siguiente letra.
                for (; i < line.size() && IsLetter(line[i]); ++i) // Esta funcion se encarga de imprimir las letras de la palabra hasta llegar a un espacio. Cuando llega a un espacio,
                                                                  // este no es reconocido como letra por la funcion "IsLetter" por lo que no se cumple la condicion del for y para la impresion. 
                    cout << line[i];
                
                if (!vowel[startingCharacter]) // Si "startingCharacter" no pertenece a una vocal, entonces se imprime. 
                    cout << startingCharacter;
                
                cout << "ay"; // imprime la string "ay"
                --i; // decrementa el contador. 
            }
            else
                cout << line[i]; // Imprime el caracter en caso de que no corresponda a una letra.
        }
        
        cout << '\n';
    }
}

/*
    Logica de funcionamiento: Cuando se ingresa una cadena de caracteres por pantalla, en este caso "Hola, como estan." este es leido con getline, luego se utiliza el for para iterar sobre el string
                              En este caso, se comienza por el caracter "H" de la string. Se llama a la funcion IsLetter, que retornara verdadero si es una letra. Luego, se guarda la H en la variable 
                              "startingCharacter" y se entra al primer if. Como la H no pertenece a una vocal, se pasa directamente al for para imprimir todas las letras que se encuentran posterior a ella
                              hasta encontrar el primer espacio. Una vez ahi, se prosigue con el segundo if, en el cual entraria e imprimiria la letra "H" seguido del string "ay". Lo interesante es que
                              imprimira la primera como corresponde siempre y cuando esta sea una vocal, puesto que entraria en el primer if. 
                              Una vez que tenemos impreso "olaHay" el contador se decrementa quedando en la posicion de la letra "a" del input dado como ejemplo. Como ya se realizo una iteracion con el for 
                              principal, este aumenta nuevamente el contador quedando en la posicion de la coma, la cual no es reconocida como letra y se imprime junto al string "aloHay", quedando "aloHay,"
                              Algo similar ocurre con el espacio, el cual no es reconocido como letra y es impreso al lado de la coma. Esta logica se sigue hasta llegar al final de cada string.

*/