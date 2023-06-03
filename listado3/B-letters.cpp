#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
  
  int n,m;
  cin >> n;
  cin >> m;
  cin.ignore();
  
  // Se resolvera con prefix_sum (suma acumulada) y binary search.

  vector<int>prefix_sum (n+1);
  prefix_sum[0] = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    prefix_sum.push_back(prefix_sum[i-1]+x);
  }
  
  for(int i=0; i < prefix_sum.size(); ++i){
    cout << prefix_sum[i] << endl;
  }

  return 0;
}







