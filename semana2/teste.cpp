#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<int> T1(10000, -1);
vector<int> T2(10000, -1);

void printarVetor(vector<int> vetor, int qtdDigitos){
    for(int i=0; i<qtdDigitos; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;
}

int investigandoZerosUns(string n, int qtdDigitos){
    n.erase(std::remove_if(n.begin(), n.end(), ::isspace),n.end());
    //cout << n << endl;
    //int qtdDigitos = n.size();  
    //size_t qtdDigitos = sizeof(n)/sizeof(int);
    //cout << qtdDigitos;
    T1[0] = 1; int somaT1 = 0;
    T2[0] = 0; int somaT2 = 0;
    for(int i=0; i<qtdDigitos; i++) {
        int numeroAtual = n[i] - '0';
        if(numeroAtual == 0){
            T1[i] = T1[i-1];
            T2[i] = T2[i-1]+1;
        }else{
            T1[i] = T2[i-1]+1;
            T2[i] = T1[i-1];
        }
        somaT1 = somaT1 + T1[i]; 
    }
    //printarVetor(T1, qtdDigitos);
    return somaT1; // +1 de T[0] = 1
}

int main(){
     int quantidadeDigitos;
    printf("Digite a quantidade de digitos: ");
    scanf("%d", &quantidadeDigitos);

    int numero = 0;
    printf("Digite os %d digitos separados por espaco: ", quantidadeDigitos);
    for (int i = 0; i < quantidadeDigitos; i++) {
        int digito;
        scanf("%d", &digito);
        numero += digito * pow(10, quantidadeDigitos - i - 1);
    }

    printf("O numero formado pelos digitos e: %d\n", numero);
}