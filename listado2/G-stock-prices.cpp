// autor: matthewreff
// fuente: https://github.com/matthewReff/Kattis-Problems/blob/master/code/stockprices.cpp

#define _USE_MATH_DEFINES
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <ctype.h>
#include <queue>
#include <map>
#include <set>
typedef long long ll; // Define un atajo para el tipo de dato long long como ll.
typedef unsigned long long ull;
using namespace std;

int main()
{
    ll i, j, k; // Declara variables de tipo long long. todos seran indices que se ocuparan en ciclos posteriores.
    ios::sync_with_stdio(false); // Al parecer esto es para optimizar la rapidez con la que se leen y escriben los datos.
    cin.tie(0);
    cout.tie(0);

    ll cases; // Tipo long long que almacena la cantidad de casos.
    cin >> cases; // Se lee la cantidad de casos.

    for(i = 0; i < cases; i++) // For que ejecutara todos los casos ingresados.
    {
    	ll trades; // long long que almacena el numero de intercambios.
    	cin >> trades; 
    	string type, garb; // Declara dos string: type y garb. type es el tipo de transaccion ("buy" o "sell"). Garb se usa para descartar la entrada de texto que no se ocupara.
    	ll numShares, priceShares; // Declaracion de long long. numShares almacena el numero de acciones que se van a comprar o vender. priceShares almacena el valor de cada accion que se va a comprar o vender.
    	ll tradePrice = -1; // Almacena el precio de la ultima transaccion realizada.
    	map<int, int, greater<int>> buyPrices; // Mapa ordenaddo por clave (precio de la accion) de mayor a menor, que almacena el numero de acciones que se van a comprar a cierto precio.
    	map<int, int> sellPrices; // Mapa ordenado por clave (precio de la accion) de menor a mayor,  que almacena el numero de acciones que se van a vender a cada precio.

        // Se leen los valores de cada transaccion.  
    	for(j = 0; j < trades; j++)
    	{
    		//input step
    		cin >> type >> numShares >> garb >> garb >> priceShares; // Cada accion tiene 5 datos. El tipo de accion ("buy" o "sell"), el numero de acciones que se van a comprar o vender, la entrada de texto que no se ocupara (garb) y el precio de cada accion que se va a comprar o vender.
    		if(type == "buy") // si el tipo de accion es "buy" se almacena en  el Mapa buyPrices.
    		{
    			buyPrices[priceShares] += numShares; // Aca se almacena el precio de la accion como clave y la cantidad de acciones compradas o vendidas como valor.
    		}
    		else // Si el tipo de acciones es "sell" se almacena en el mapa sellPrices.
    		{
    			sellPrices[priceShares] += numShares; // Aca se almacena el precio de la accion como clave y la cantidad de acciones compradas o vendidas como valor.
    		}

    		//parse trades step
    		while(buyPrices.size() && sellPrices.size() && buyPrices.begin()->first >= sellPrices.begin()->first) // Este while se encarga de analizar los trades y transacciones necesarias mientras haya elementos en los 'map' y el precio del primer elemento en buyPrices es mayor o igual que el precio del primer elemento en sellPrices
    		{
    			tradePrice = sellPrices.begin()->first; // Establecemos el precio de la transaccion 'tradePrice' al precio del primer elemento del map sellPrices.
    			ll transactionAmount = min(sellPrices.begin()->second, buyPrices.begin()->second); // Aca se determina la cantidad minima de acciones a realizar entre la cantidad de acciones en venta y la cantidad de acciones en compra.
    			sellPrices.begin()->second -= transactionAmount; // Se resta 'transactionAmount' de ambas cantidad de acciones involucradas en la transaccion. (if de sellPrices e if de buyPrices).
    			if(sellPrices.begin()->second == 0) // Si la alguna de las dos llega a cero, se elimina el elemento del map. (esto es para este if como para el de buyPrices.)
    			{
    				sellPrices.erase(sellPrices.begin());
    			}
    			buyPrices.begin()->second -= transactionAmount;
    			if(buyPrices.begin()->second == 0)
    			{
    				buyPrices.erase(buyPrices.begin());
    			}
    		}

    		//print step
    		if(sellPrices.size()) // Se verifica si hay precios de venta en sellPrices.
    		{
    			cout << sellPrices.begin()->first << " "; // Imprime el menor precio de venta.
    		}
    		else
    		{
    			cout << "-" << " "; // Imprime un guion si la condicion anterior no se cumple.
    		}

    		if(buyPrices.size()) // Esto de aca sigue la misma logica de los if de arriba.
    		{
    			cout << buyPrices.begin()->first << " ";
    		}
    		else
    		{
    			cout << "-" << " ";
    		}

    		if(tradePrice != -1) // se verifica si tradePrice es distinto de -1, lo que quiere decir que se realizo una transaccion.
    		{
    			cout << tradePrice << " "; // imprime el precio de la transaccion. 
    		}
    		else
    		{
    			cout << "-" << " "; // Imprime un guion si no se realizaron transacciones.
    		}
    		cout << "\n";
    	}
    }
    return 0;
}