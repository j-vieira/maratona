#include <bits/stdc++.h>

using namespace std;

vector<int> T(1000, -1);
vector<int> P(1000, -1);

void printarVetor(string s, vector<int> vetor, int qtdDigitos){
    int k = 0;
    for(int i=0; k<qtdDigitos; i++){
        for(int j=0; j<P[i]; j++){
            cout << s[k];
            k++;
        }
        cout << "|";
    }
    cout << endl;
}

int val(char c){
    return c - '0';
}

void particionamentoSomaMaxima(string s){
    T[0] = s[0] - '0';
    T[1] = 10*(s[0]-'0') + s[1];
    P[0] = 1; P[1] = 2;
    int soma1 = 0; int soma2 = 0;
    
    for(int i=2; i<s.size(); i++){
        soma1 = T[i-1] + val(s[i]); 
        T[i] = soma1;
        P[i] = 1;
        
        soma2 = T[i-2] + 10*val(s[i-1]) + val(s[i]);
        if(soma2 > soma1){
            T[i] = soma2;
            P[i] = 2;
        }
    }
    printarVetor(s, P, s.size());

}

int main(){
    particionamentoSomaMaxima("19375243");
}