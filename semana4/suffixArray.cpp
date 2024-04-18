#include <bits/stdc++.h>

using namespace std;

void suffixSort(vector<int> &SA, vector<int> &RA, int n, int k){
    vector<int> C(max(n,256), 0);
}

void suffixArray(vector<int> &SA, vector<int> &RA, string s){
    s += '\1';
    int n = s.size();

    RA.resize(n);
    for(int i=0; i<n; i++){
        RA[i] = s[i] - 1;
    }

    SA.resize(n);
    for(int i=0; i<n; i++){
        SA[i] = i;
    }

    for(int k=1; k<n; k*=2){
        
    }
}

int main(){
    
}