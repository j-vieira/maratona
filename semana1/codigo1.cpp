#include <bits/stdc++.h>
using namespace std;

int rabinKarp(string T, string P) {
    int tamanhoTexto = T.size();
    int tamanhoPadrao = P.size();

    int dM = 1;
    int hash1 = 0, hash2 = 0;
    int base = 256, primo = 3355439;

    // preprocessamento
    for(int i = 0; i < tamanhoPadrao - 1; i++) {
        dM = (base * dM) % primo;
    }
    for(int i = 0; i < tamanhoPadrao; i++)  {
        hash1 = (hash1 * base + P[i]) % primo;
    }
    for(int i = 0; i < tamanhoPadrao; i++) {
        hash2 = (hash2 * base + T[i]) % primo;
    }

    int i = tamanhoPadrao - 1;
    int k;
    while (i < tamanhoTexto) {
        if (hash1 == hash2) {
            k = 0;
            while (k < tamanhoPadrao && T[i - k] == P[tamanhoPadrao - 1 - k]) {
                k++;
            }
            if (k == tamanhoPadrao) {
                return i - tamanhoPadrao + 1; // indice inicial da palavra em T
            }
        }
        i++;
        if (i < tamanhoTexto) {
            hash2 = (hash2 + base * primo - T[i - tamanhoPadrao] * dM) % primo;
            hash2 = (hash2 * base + T[i]) % primo;
        }
    }
    return -1; // pattern nao encontrado
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); // ignora \n
    while(t) {
        string T, P;
        getline(cin, T);
        getline(cin, P);
        
        string reversedP = P;
        reverse(reversedP.begin(), reversedP.end());

        int index = rabinKarp(T, P);
        int reverseIndex = rabinKarp(T, reversedP);
        if (index != -1) {
            cout << "Encontrou padrao na pos. " << index << endl;
        } 
        else if(reverseIndex!=-1) {
            cout << "Encontrou padrao na pos. " << reverseIndex << endl;
        }
        else {
            cout << "Padrao nao encontrado" << endl;
        }
        t--;
    }
    return 0;
}
