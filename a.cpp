#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int main(){
    int i,j,a,temp,ans1,ans2,card[MAX]= {},card2[MAX]= {};
    ans1=ans2=0;
    scanf("%d", &a);
    for(i=0;i<a;i++) // Este for almacena las cartas de Alice de forma ordenada (ascendente).
    {
        scanf("%d",&temp); // Lee el numero y lo almacena en la variable tipo entero "temp"
        //cout<<temp;
        card[temp]=temp;
    }

    for(j=0;j<MAX;++j)
        cout<<card[j];
    return 0;
}