//Algoritmos de Busca em String: Knuth-Morris-Pratt, Boyer-Moore, Rabin-Karp
//KMP acertado em 05/03/2024
#include <bits/stdc++.h>
using namespace std;

char P[1000001], T[1000001];
int n, m, F[1000001], R[256];

void KMP(){
    int i,j,k;   
    //Preprocessamento
    F[0] = 0;  F[1] = 0;  j = -1;  i = 0;
    while (i < (m-1)) {  
        if (P[i+1] == P[j+1]){ j++; F[++i] = j+1; }
        else if (j == -1)  F[++i] = 0;
        else j = F[j]-1;
    } 
    //cout<<"Tabela KMP:";
	//for(i=0; i<=m-1; i++) cout <<F[i]<<" " ; cout<<endl;    
    //Busca 
    i=-1;  j=-1;    
    while ((i-j) <= (n-m)){
        //cout<<"Comeco i , j ="<<i<<" "<<j<<" ";  
        while (j < (m-1)){
            if (P[j+1] == T[i+1]){ i++;  j++;}
            else break;
        }   
        if (j == (m-1)) cout <<"Encontrou padrao na pos. " << i <<endl;
        //if (j == -1)cout<<"Meio i, j = "<<i+1<<" "<<j<<" ";
        //else cout<<"Meio i, j = "<<i<<" "<<j<<" ";
        if (j == -1) i++;
        else j = F[j]-1;
        //cout<<"Fim j= "<<j<<endl;
    } 
}
void BM()
{  int i,j,k;
    //Preprocessamento
    for(i = 0; i < 256; i++)  R[i] = m;      
    for(i = 0; i < m-1; i++)  R[P[i]] = m-i-1; 
    //Busca              
    k = m-1;           
    while(k < n) {
       i = k; j = m-1;                
       while(T[i] == P[j] && j >= 0) {  i--;  j--;
       }            
       if(j < 0) cout << "Encontrou padrao na pos. " << i+m <<endl;             
       k+= R[T[k]];
    }
}

void RK(){
	int i, k, dM, h1, h2, d=256, q=3355439;     
    //Preprocessamento
	dM = 1;  
	for (i=0; i<m-1; i++) 
		dM = (d*dM)%q;
    h1 = 0;  
	for (i=0; i<m; i++)   
		h1 = (h1*d+P[i])% q;
    h2 = 0;  
	for (i=0; i<m; i++)   
		h2 = (h2*d+T[i])% q;
    //Busca              
    i = m-1;
    while (i < n) {
        if (h1 == h2){
            k = 1;
            while ((T[i-k+1] = P[m-k]) && (k < m)) 
				k++;
            if (k == m) 
				cout <<"Encontrou padrao na pos. " << i <<endl;
        }
        i++;
        if (i < n) {
            h2 = (h2+d*q-T[i-m]*dM)% q;
            h2 = (h2*d+T[i])% q;
        }
    }
}

int main()
{   while(true){
        cout <<"Texto: ";    cin >> T;
        cout <<"Padao: ";    cin >> P;
        n = strlen(T);
        m = strlen(P);    cout<<"m= "<<m<<endl;
        cout <<"KMP"<<endl;  KMP();
        cout <<"BM"<<endl;   BM();
        cout <<"RK"<<endl;   RK();    
    }
}
