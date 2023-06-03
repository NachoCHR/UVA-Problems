#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; // n dormitorios m habitaciones
    cin >> n;
    cin >> m;
    
    // Se resolvera usando prefix sum (suma acumulada) y binary search iterativa.

    vector<long long> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        long long num;
        cin >> num;
        prefix_sum[i] = prefix_sum[i - 1] + num;
    }

    for (int i = 0; i < m; i++) {
        long long x;
        cin >> x;

        // Realizar búsqueda binaria para encontrar la posición 'pos' en 'prefix_sum'
        // tal que prefix_sum[pos] <= x < prefix_sum[pos + 1]

        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (prefix_sum[mid] >= x)
                r = mid;
            else
                l = mid + 1;
        }

        int pos = l;
        long long diff = x - prefix_sum[pos - 1];
        cout << pos << " " << diff << endl;
    }

    return 0;
}

