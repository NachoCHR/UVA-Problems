// autoria: wrong submission 
// fuente: https://www.youtube.com/watch?v=75XH4YsEW2E

#include<bits/stdc++.h>
using  namespace  std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
#define sq(x)   (x)*(x)
#define PI      acos(-1.0)
#define all(x) x.begin(),x.end()
#define nl      '\n'
 #define mod 1000000007
typedef long long int ll;
typedef unsigned long long int  llu;
 
// PRIME NUMBER TEST//
bool prime(int n)
{
    if(n<2)return false;
    if(n<=3)return true;
    if(n%2==0)return false;
    for(int i=3;i*i<=n;i+=2)
    {
        if(n%i==0)return false;
    }
    return true;
}
 
// Graph Grid //
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
 
int main()
{
    int t;
    cin>>t;   // Lee el número de casos de prueba
    while(t--)
    {
        int n;
        cin>>n;   // Lee el tamaño de los arreglos
        
        int a[n+3], b[n+3];   // Declaración de los arreglos a y b
        
        for(int i=0; i<n; i++)
            cin>>a[i];   // Lee los elementos del arreglo a
        
        for(int i=0; i<n; i++)
            cin>>b[i];   // Lee los elementos del arreglo b
        
        vector<int> mn, mx;   // Vectores para almacenar los resultados mínimos y máximos
        
        int ind=0;
        for(int i=0; i<n; i++)
        {
            while(ind<n && a[i]>b[ind])   // Encuentra el índice más pequeño en b tal que a[i] <= b[ind]
                ind++;
            mn.push_back(b[ind]-a[i]);   // Agrega la diferencia b[ind]-a[i] al vector mn
        }
        
        for(int i=0; i<n; i++)
            cout<<mn[i]<<" ";   // Imprime los elementos del vector mn
        cout<<endl;
 
        ind=n-1;
        for(int i=n-1; i>=0; i--)
        {
            mx.push_back(b[ind]-a[i]);   // Agrega la diferencia b[ind]-a[i] al vector mx
            if(a[i]>b[i-1]) ind=i-1;   // Actualiza el índice ind si a[i] > b[i-1]
        }
        reverse(mx.begin(),mx.end());   // Invierte el orden de los elementos en el vector mx
        for(int i=0; i<n; i++)
            cout<<mx[i]<<" ";   // Imprime los elementos del vector mx
        cout<<endl;
    }
}