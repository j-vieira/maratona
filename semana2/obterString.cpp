#include <bits/stdc++.h>

using namespace std;  

stringstream ss;  string s, s2;

string obterString(){

}

int main() 
{     
    while(1){  
        ss.clear();
        getline(cin, s);          
        ss.str(s);            
        while( ss >> s2 ) {              
            cout << s2 << endl;       
        }
      }
      return 0;    
}
