#include <bits/stdc++.h>

using namespace std;

long int moedas(int m, long int n, vector<long int>& V) {
    vector<vector<long int>> T(m+1, vector<long int>(n+1, 0));

    for (long int j = 0; j <= n; j++)
        T[0][j] = 0;

    for (long int i = 1; i <= m; i++) {
        T[i][0] = 1;
        for (long int j = 1; j <= n; j++) {
            if (j >= V[i])
                T[i][j] = T[i][j-V[i]] + T[i-1][j];
            else
                T[i][j] = T[i-1][j];
        }
    }

    return T[m][n];
}

int main() {
    int m=21;
    int n;
    
    vector<long int> V(m + 1);
    for (int i = 0; i <= m; i++){
        V[i] = pow(i, 3); 
    }
    while(cin >> n){
        cout << moedas(m, n, V) << endl;
    }
    return 0;
}
