#include <bits/stdc++.h>
using namespace std;

struct posicao {
    vector<int> i;
    vector<int> j;
};

struct padrao{
    int index;
    char direcao;
};

vector<vector<string>> criarMatriz(int tamanhoMatriz){
        string T;
        vector<vector<string>> matrizLetras(tamanhoMatriz, vector<string>(tamanhoMatriz));

        for(int i=0; i<tamanhoMatriz; i++){
            cin >> T;
            for(int j=0; j<tamanhoMatriz; j++){
                matrizLetras[i][j] = T[j];
            }
        }
        return matrizLetras;
}

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

padrao encontrarIndice(string T, string P) { 
    
    int index = rabinKarp(T, P);
    string reversedP = P;
    reverse(reversedP.begin(), reversedP.end());
    int reverseIndex = rabinKarp(T, reversedP); 

    padrao p; // direcao N -> NORMAL R-> REVERSA

    if (index != -1) {
        p.index = index; p.direcao = 'N';
        return p;
    } 
    else if(reverseIndex!=-1) {
        p.index = reverseIndex; p.direcao = 'R';
        return p;
    }
    else {
        p.index = -1; p.direcao = 'N';
        return p;
    }
}

void imprimirCoordenada(posicao& pos, int index, int deslocamento) {
    cout << "" << pos.i[index] << "," << pos.j[index] << "";
    if (deslocamento != 0)
        cout << ", " << pos.i[index + deslocamento] << "," << pos.j[index + deslocamento] << "";
    cout << endl;
}

void imprimirCoordenadas(posicao& pos, int index, char direcao, int deslocamento) {
    if (index != -1) {
        if (direcao == 'N') {
            imprimirCoordenada(pos, index, deslocamento);
        } else if (direcao == 'R') {
            imprimirCoordenada(pos, index, 0);
        }
    }
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); // ignora \n
    while(t) {
        int tamanhoMatriz;
        cin >> tamanhoMatriz; 
        vector<vector<string>> matrizCaracteres = criarMatriz(tamanhoMatriz);

        string T; string Tvertical; string TDiagonalDireita; string TDiagonalEsquerda;
        
        string P; cin >> P;
        string reversedP = P;
        reverse(reversedP.begin(), reversedP.end());

        for(int i=0; i<tamanhoMatriz; i++){
            T = ""; Tvertical = ""; 

            posicao horizontal; posicao vertical;
            posicao diagonalDireita; posicao diagonalEsquerda;

            for(int j=0; j<tamanhoMatriz; j++){
                T += matrizCaracteres[i][j];
                Tvertical += matrizCaracteres[j][i];
                horizontal.i.push_back(i); horizontal.j.push_back(j);
                vertical.i.push_back(j); vertical.j.push_back(i);
            }

            TDiagonalDireita = "";
            for(int k=0; k<tamanhoMatriz-i; k++){
                TDiagonalDireita += matrizCaracteres[k][k+i];
                diagonalDireita.i.push_back(k); diagonalDireita.j.push_back(k+i);
            }

            TDiagonalEsquerda = "";
            int l = tamanhoMatriz-1;
            for(int k=0; k<tamanhoMatriz-i; k++){
                TDiagonalEsquerda += matrizCaracteres[k][l-i];
                diagonalEsquerda.i.push_back(k); diagonalEsquerda.j.push_back(l-i);
                l--;
            }
            int deslocamento = P.size()-1;

            imprimirCoordenadas(horizontal, encontrarIndice(T, P).index, encontrarIndice(T, P).direcao, deslocamento);
            imprimirCoordenadas(vertical, encontrarIndice(Tvertical, P).index, encontrarIndice(Tvertical, P).direcao, deslocamento);
            imprimirCoordenadas(diagonalDireita, encontrarIndice(TDiagonalDireita, P).index, encontrarIndice(TDiagonalDireita, P).direcao, deslocamento);
            imprimirCoordenadas(diagonalEsquerda, encontrarIndice(TDiagonalEsquerda, P).index, encontrarIndice(TDiagonalEsquerda, P).direcao, deslocamento);
        }
        t--;
    }
    return 0;
}
