#include <iostream>
#include <map>
#include <set>

using namespace std;

map<int, set<char>> initializeSoundexTable(){
    map<int, set<char>> soundexCode;

    soundexCode[1].insert('B');
    soundexCode[1].insert('P');
    soundexCode[1].insert('F');
    soundexCode[1].insert('V');

    soundexCode[2].insert('C');
    soundexCode[2].insert('S');
    soundexCode[2].insert('K');
    soundexCode[2].insert('G');
    soundexCode[2].insert('J');
    soundexCode[2].insert('Q');
    soundexCode[2].insert('X');
    soundexCode[2].insert('Z');

    soundexCode[3].insert('D');
    soundexCode[3].insert('T');

    soundexCode[4].insert('L');

    soundexCode[5].insert('M');
    soundexCode[5].insert('N');

    soundexCode[6].insert('R');

    return soundexCode;
}

void iterate(const map<int, set<char>>& mmap){
    for(const auto& key_value: mmap) {
        int key = key_value.first;
        const set<char>& value = key_value.second;

        cout << key << " - ";
        for(char ch : value) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

int main(){
    map<int, set<char>> soundexCode = initializeSoundexTable();
    string name;
    cin >> name;
    int numberKeys = 6;
    int it = 0;
    for(int i=1; i<=numberKeys; i++){
        for(int j=0; j<name.size(); j++){
            if(soundexCode[i].find(name[j]) != soundexCode[i].end()){
                cout << name[j]; 
            }
            it++;
        }
    }
}
