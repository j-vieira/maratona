#include <bits/stdc++.h>

using namespace std;

// SA SUFFIX ARRAY
// RA

void suffixSort(vector<int>& SA, vector<int>& RA, int n, int k) {
    vector<int> C(max(n, 256), 0);
    vector<int> tempSA(n), tempRA(n);

    for (int i = 0; i < n; i++)
        C[i + k < n ? RA[i + k] : 0]++;

    int sum = 0;
    for (int i = 0; i < C.size(); i++) {
        int t = C[i];
        C[i] = sum;
        sum += t;
    }

    for (int i = 0; i < n; i++)
        tempSA[C[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];

    SA = tempSA;
}

void suffixArray(vector<int>& SA, vector<int>& RA, string& s) {
    s += '\1'; // Sentinel needed for the algorithm
    int n = s.size();

    RA.resize(n);
    for (int i = 0; i < n; i++)
        RA[i] = s[i] - 1;

    SA.resize(n);
    for (int i = 0; i < n; i++)
        SA[i] = i;

    for (int k = 1; k < n; k *= 2) {
        suffixSort(SA, RA, n, k);
        suffixSort(SA, RA, n, 0);

        int r = RA[SA[0]] = 0;
        for (int i = 1; i < n; i++) {
            int s1 = SA[i], s2 = SA[i - 1];
            bool equal = true;
            equal &= RA[s1] == RA[s2];
            equal &= RA[s1 + k] == RA[s2 + k];

            RA[SA[i]] = equal ? r : ++r;
        }
    }
}

void constructLCP(vector<int>& SA, string& s, vector<int>& LCP) {
    int n = s.size();
    vector<int> Phi(n), PLCP(n);

    for (int i = 0; i < n; i++)
        Phi[SA[i]] = (i == 0) ? -1 : SA[i - 1];

    int L = 0;
    for (int i = 0; i < n; i++) {
        if (Phi[i] == -1) {
            PLCP[i] = 0;
            continue;
        }
        while (s[i + L] == s[Phi[i] + L])
            L++;

        PLCP[i] = L;
        L = max(L - 1, 0);
    }

    LCP.resize(n);
    for (int i = 1; i < n; i++)
        LCP[i] = PLCP[SA[i]];
}

void findLCS(const string& a, const string& b) {
    string s = a + "\1" + b + "\2";

    vector<int> SA, RA, LCP, O;
    suffixArray(SA, RA, s);
    constructLCP(SA, s, LCP);

    int m = a.length();
    int n = s.size();
    O.resize(n);

    for(int i = 0; i < n; i++) {
        if(SA[i] < m)
            O[i] = 1;
        else
            O[i] = 2;
    }
    int t = 0;
    vector<int> positions;

    string str;

    for(int i = 1; i < n; i++) {
        if(O[i] != O[i - 1]) {
            if(t < LCP[i]) {
                positions.clear();
                t = LCP[i];
                positions.push_back(SA[i]);
            } else if(t == LCP[i]) {
                positions.push_back(SA[i]);
            }
        }
    }

    if(positions.size() > 0) {
        for(int i = 0; i < positions.size(); i++) {
            int pos = positions[i];
            for(int i = pos; i < pos + t; i++)
                cout << s[i];
            cout << endl;
        }
    } else {
        cout << "No common sequence." << endl;
    }    
}


int main(){
    string a;
    string b;
    int it = 0;
    while (cin >> a >> b && !a.empty() && !b.empty()) {
        if(it != 0)
                cout << endl; 
        findLCS(a, b);
        it++;
    }

    return 0;
}