// jogo da soma
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> T(1000, vector<int>(1000, -1));
vector<int> V(1000, -1);
vector<int> A(1000, -1);


int jogoDaSoma(int n){
    for(int k=0; k<n; k++){
        T[k][k] = V[k];
    }
    
    A[0] = 0;
    for(int k=0; k<n; k++){
        A[k] = A[k-1]+V[k];
    }
    for(int d=0; d<n; d++){
        for(int i=0; i<n-d; i++){
            j = i+d;
            T[i][j] = A[j]-
        }
    }

    return 0;
}

int main(){

}