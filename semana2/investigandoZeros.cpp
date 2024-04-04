#include <bits/stdc++.h>

using namespace std;

vector<int> T1(100000, -1);
vector<int> T2(100000, -1);

int investigandoZerosUns(vector<int> V, int qtdDigitos){    
    
    int somaT1 = 0;
    T1[1] = 1; T2[1] = 0;

    if(V[1] == 0){
        T1[1] = 0;
        T2[1] = 1;
    }

    somaT1 = T1[1];
    
    for(int i=2; i<qtdDigitos+1; i++) {
        int numeroAtual = V[i];
        if(numeroAtual == 0){
            T1[i] = T1[i-1]; T2[i] = T2[i-1]+1;
        }else{
            T1[i] = T2[i-1]+1; T2[i] = T1[i-1];
        }
        somaT1 = somaT1 + T1[i]; 
    }

    return somaT1; 
}

int main(){
    int qtdDigitos = 0;
    cin >> qtdDigitos;

    vector<int> V(qtdDigitos+1, -1);

    for(int i=1; i<qtdDigitos+1; i++){
        cin >> V[i];
    }

    cout << investigandoZerosUns(V, qtdDigitos) << endl;
}