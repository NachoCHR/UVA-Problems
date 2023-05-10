// autor: Michael Pfeifer
// fuente: https://github.com/mpfeifer1/Kattis/blob/master/integerlists.cpp

// Exporta las librerias estandar necesarias y la libreria pbds. Solo se ocupa la libreria estandar.
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Pone alias a algunos tipos de datos. Esto para simplificar su uso. No se utilizan para este codigo.
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

// Define algunas constantes que utiliza mas adelante. No se utilizan para este codigo.
const ld  pi   = 4.0*atanl(1.0);
const int iinf = 1e9 + 10;
const ll  inf  = 1e18 + 10;
const int mod  = 1000000007;
const ld  prec = .000001;

// Declara algunos atajos para escribir codigo mas rapido. Solo se utilizan algunos para este codigo.
#define enld endl
#define endl '\n'
#define pb push_back
#define debug(x) cout<<#x<<" -> "<<x<<'\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define umap unordered_map
#define uset unordered_set

// Define un alias para el tipo de dato tree de pbds. No se utiliza.
template<class TIn>
using indexed_set = tree<
        TIn, null_type, less<TIn>,
        rb_tree_tag, tree_order_statistics_node_update>;

// Estas funciones al parecer acelera la entrada de datos. No se utilizan en el codigo de todas formas.
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}


void file() {
    auto a = freopen("a.in",  "r", stdin);
    auto b = freopen("a.out", "w", stdout);
    if(!a || !b) cout << "uh oh" << endl;
}





int main() {
    //file();
    //fast();

    // Lee el numero de casos de prueba.
    int cases;
    cin >> cases;

    // Ciclo que corre cada caso de prueba.
    while(cases--) {

        // Lee la operacion a realizar.
        string command;
        cin >> command;

        // Lee el numero de enteros de la lista inicial.
        int n;
        cin >> n;

        // Lee la lista inicial 
        deque<int> d; // Declara una deque para almacenar la lista inicial de enteros.
        cin.ignore();
        for(int i = 0; i < n; i++) { // Lee los n enteros de la lista incial y los almacena en la deque usando pb() (atajo de push_back) para que sean insertados al final de la deque
            cin.ignore();
            int t;
            cin >> t;
            d.pb(t);
        }
        cin.ignore();
        if(n == 0) { // Esta es una validacion que se realiza para descartar un posible salto de linea en le bufer de entrada en caso de que la lista inicial este vacia.
            cin.ignore();
        }

        // Inicializa dos banderas para controlar el sentido de la operación
        bool beg = true; // Esta bandera se utiliza para controlar el sentido de las operaciones (de adelante hacia atras o de atras hacia adelante).
        bool printed = false; // Esta bandera se utiliza para indicar que hubo un error en las ejecucion de las operaciones.

        // Ciclo para realizar cada operación
        for(auto i : command) {
            if(i == 'R') { // Si la operación es 'R', invierte la bandera que indica el sentido de la operación
                beg = !beg;
            }
            if(i == 'D') { // Si la operacion es 'D', elimina el primer o ultimo elemento de la deque dependiendo del sentido de la operacion.
                if(d.size() == 0) {
                    printed = true;
                    cout << "error" << endl;
                    break;
                }
                else {
                    if(beg) {
                        d.pop_front();
                    }
                    else {
                        d.pop_back();
                    }
                }
            }
        }

        // Es una validacion que se realiza para imprimir el resultado de las operaciones solo si no se a producido ningun error. Si printed es false, se imprime el contenido de 'd' en el orden correspondiente al sentido de las operaciones.
        if(!printed) {
            cout << "[";
            while(!d.empty()) {
                if(beg) {
                    cout << d.front();
                    d.pop_front();
                }
                else {
                    cout << d.back();
                    d.pop_back();
                }

                if(d.size() != 0) {
                    cout << ",";
                }
            }
            cout << "]" << endl;
        }
    }

    return 0;
}