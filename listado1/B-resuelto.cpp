/*
    autor y fuente: https://github.com/Ash-ik/Programming-Problems-Solutions/blob/master/UVA-Online-Judge-Solved-problems/UVA%2011678.cpp
*/
#include<stdio.h>
#include<bits/stdc++.h>
#define MAX 100099
int main()
{
    int a,b; // Enteros que almacenan la cantidad de cartas que tiene cada niña.
    while(scanf("%d %d",&a,&b)==2 && !(a==0 && b==0)) // Se leen la cantidad de cartas de las dos niñas siempre y cuando se lean 2 entradas y estas sean distintas de cero.
    {
        int i,j,temp,ans1,ans2,card[MAX]= {},card2[MAX]= {};
        ans1=ans2=0;
        for(i=0;i<a;i++) // Este for almacena las cartas de Alice de forma ordenada (ascendente).
           {
                scanf("%d",&temp); // Lee el numero y lo almacena en la variable tipo entero "temp"
                card[temp]=temp; // almacena la variable int temp en la posicion temp dentro del arreglo card. Si ya existe el num, lo sobreecribe. 
           }
           for(i=0;i<b;i++)
           {
                scanf("%d",&temp); // Aca realiza lo mismo que arriba.
                card2[temp]=temp;
           }
           for(i=0;i<=100000;i++)
            {   
                if(card[i]){ // entra unicamente si hay cartas en la posicion i dentro del vector card. Esto quiere decir que si el numero registrado en la posicion i del arreglo no es distinto de cero no entrara.
                    if(card[i]!=card2[card[i]]) // Aca se hace la comparacion de que la carta que tenga Alice no la tenga Betty. 
                    {
                        ans1++; // Si la carta de alice no la tiene betty se aumenta el contador.
                    }
                }
            // Aca sigue una logica bastante parecida, incrementando el contador cuando la carta que tiene Betty no la tiene Alice
               if(card2[i]){
                    if(card2[i]!=card[card2[i]])
                    {
                        ans2++; 
                    }
               }
            }
           if(ans1>ans2) // Aca unicamente se imprime el maximo de combinaciones posibles. Es decir, en minimo entre ans1 y ans2.
            ans1=ans2;
           printf("%d\n",ans1);
    }
    return 0;
}
