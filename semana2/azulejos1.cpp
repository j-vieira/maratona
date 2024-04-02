#include <bits/stdc++.h>

using namespace std;

vector<int> T(10000, -1);

int azulejosMemo(int n){ // recursao e memorizacao
    if(n<=2) {
        T[n] = n;
        return T[n];
    }
    else {
        T[n] =  azulejosMemo(n-1) + azulejosMemo(n-2);
    }
    return T[n];
}

int azulejos(int n){
    T[1] = 1;
    T[2] = 2;
    for(int i=3; i<n; i++){
        T[i] = T[i-1] + T[i-2];
    }
    return T[n];
}


int main(){
    cout << azulejos(10) << endl;
}