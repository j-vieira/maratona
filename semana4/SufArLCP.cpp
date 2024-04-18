#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void suffix_sort(vector<int>& SA, vector<int>& RA, int n, int k) {
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

void suffix_array(vector<int>& SA, vector<int>& RA, string& s) {
    s += '\1'; // Sentinel needed for the algorithm
    int n = s.size();

    RA.resize(n);
    for (int i = 0; i < n; i++)
        RA[i] = s[i] - 1;

    SA.resize(n);
    for (int i = 0; i < n; i++)
        SA[i] = i;

    for (int k = 1; k < n; k *= 2) {
        suffix_sort(SA, RA, n, k);
        suffix_sort(SA, RA, n, 0);

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

void construct_lcp(vector<int>& SA, string& s, vector<int>& LCP) {
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

int main() {
    string s;
    while (getline(cin, s)) {
        vector<int> SA, RA, LCP;
        suffix_array(SA, RA, s);
        construct_lcp(SA, s, LCP);

        cout << "Suffix Array: ";
        for (int i = 0; i < s.length(); i++)
            cout << SA[i] << " ";
        cout << endl;

        cout << "LCP Array: ";
        for (int i = 0; i < s.length(); i++)
            cout << LCP[i] << " ";
        cout << endl;
    }
    return 0;
}
