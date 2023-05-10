/*
*	autoria: Isanchez_Aguilar
*	fuente: https://github.com/isanchez-aguilar/UVa-Solutions/blob/master/10172%20-%20The%20Lonesome%20Cargo%20Distributor.cpp
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int sets; // Entero que almacena el numero de pruebas que se tendran.
	cin >> sets; // Se almacena el numero de pruebas.

	while(sets--) // While para ejecutar toda la cantidad de pruebas que se registro.
	{
		int n; // Entero que almacena el numero de estaciones.
		int s; // Entero que almacena el tamanpo maximo de la pila del transportador. 
		int q; // Entero que almacena  el tamano maximo de la cola de cada estaciones.
		cin >> n >> s >> q;

		stack<int> carrier; // Se define la pila carrier que representa la carga que llevara el transportador.
		vector< queue<int> > stations(n); // Se define la cola stations que representa las cajas en cada estacion. 
		
		for(int i = 0; i < n; ++i) // For para leer el numero de cajas de cada estacion.
		{
			int boxes; // entero que almacena el numero de cajas de cada estacion i.
			cin >> boxes;

			while(boxes--) // Bucle para almacenar la identificacion de las cajas que estan en la estacion i.
			{
				int temp; // variable para almacenar la idetificacion de la caja.
				cin >> temp;
				stations[i].push(temp - 1); // Se agregan a la cola. Se le resta 1 para que coincidan con los indices que se estan ocupando (0 a N-1)
				
			}
		}
		int time = 0; // Variable que almacena el tiempo transcurrido.
		bool empty = 0; // Variable que indica si las estaciones estan vacias.
		int position = 0; // Variable que almacena la posicion del transportador.

		while(!empty) // Bucle que persiste mientras que el transportador no este vacia.
		{
			while(!carrier.empty() && (carrier.top() == position || stations[position].size() < q)) // Este bucle se encarga de descargar las cajas de el transportador en la estacion actual si no esta completamente llena y si la identificacion de la caja superior de la pila tiene la misma identificacion de la estacion. Se descargan hasta que no hayan mas cajas o que la pila de el transportador quede vacia.
			{
				if(carrier.top() != position)
					stations[position].push(carrier.top());
			
				++time; // Se aumenta el tiempo. 
				carrier.pop();
			}

			while(carrier.size() < s && !stations[position].empty()) // Aqui se cargan todas las cajas disponibles en la estacion a el transportador si hay espacio en ella. Termina si la estacion quda vacia o si el transportador no tiene mas espacio.
			{
				carrier.push(stations[position].front());

				++time;
				stations[position].pop();
			}

			empty = carrier.empty();

			if(empty) // Si tanto estaciones como el transportador quedan vacias se sale del bucle.
			{
				for(int i = 0; i < n; ++i)
				{
					if(!stations[i].empty())
					{
						empty = 0;
						break;	
					}
				}
			}

			if(!empty) // Si aun quedan cajas, se aumenta el tiempo en 2 y se cambia de posicion el transportador.
			{
				time += 2;
				position = (position + 1) % n;
			}
		}

		cout << time << "\n"; // Imprime el tiempo total que llevo repartir todas las cajas.
	}

	return 0;
}

