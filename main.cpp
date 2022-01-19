#include <iostream>
#include <fstream>

using namespace std;

int main() {
    char c[7][8];
    string line;
    string word[8];
    ifstream file;
    file.open("1.txt");
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 8; j++) {
            file >> c[i][j];
        }
    }
    int a = 0;
    while (getline(file, line)) {
        file >> word[a];
        a++;
    }
    file.close();
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 8; j++) {
            cout << c[i][j] << ' ';
        }
        cout << endl;
    }
    for (int k = 0; k < 8; k++) {
        cout << word[k] << endl;
    }
    return 0;
}