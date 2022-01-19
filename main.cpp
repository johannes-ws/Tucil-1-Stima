#include <iostream>
#include <fstream>
#include <chrono>

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
    auto started = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 8; j++) {
            int p = i;
            int q = j;
            int b = 0;
            int d = 0;
            while (b < 8) {
                while (c[p][q] == word[b][d]) {
                    p--;
                    d++;
                    if (word[b].length() == d) {
                        cout << word[b] << endl;
                        d = 0;
                        p = i;
                        q = j;
                        break;
                    }
                    if (p == -1) {
                        d = 0;
                        p = i;
                        q = j;
                        break;
                    }
                }
                p = i;
                q = j;
                d = 0;
                while (c[p][q] == word[b][d]) {
                    p++;
                    d++;
                    if (word[b].length() == d) {
                        cout << word[b] << endl;
                        d = 0;
                        p = i;
                        q = j;
                        break;
                    }
                    if (p == 7) {
                        d = 0;
                        p = i;
                        q = j;
                        break;
                    }
                }
                p = i;
                q = j;
                d = 0;
                while (c[p][q] == word[b][d]) {
                    q++;
                    d++;
                    if (word[b].length() == d) {
                        cout << word[b] << endl;
                        d = 0;
                        p = i;
                        q = j;
                        break;
                    }
                    if (q == 8) {
                        d = 0;
                        p = i;
                        q = j;
                        break;
                    }
                }
                p = i;
                q = j;
                d = 0;
                while (c[p][q] == word[b][d]) {
                    q--;
                    d++;
                    if (word[b].length() == d) {
                        cout << word[b] << endl;
                        d = 0;
                        p = i;
                        q = j;
                        break;
                    }
                    if (q == -1) {
                        d = 0;
                        p = i;
                        q = j;
                        break;
                    }
                }
                p = i;
                q = j;
                d = 0;
                while (c[p][q] == word[b][d]) {
                    p--;
                    q++;
                    d++;
                    if (word[b].length() == d) {
                        cout << word[b] << endl;
                        d = 0;
                        p = i;
                        q = j;
                        break;
                    }
                    if ((p == -1) || (q == 8)) {
                        d = 0;
                        p = i;
                        q = j;
                        break;
                    }
                }
                p = i;
                q = j;
                d = 0;
                while (c[p][q] == word[b][d]) {
                    p++;
                    q++;
                    d++;
                    if (word[b].length() == d) {
                        cout << word[b] << endl;
                        d = 0;
                        p = i;
                        q = j;
                        break;
                    }
                    if ((p == 7) || (q == 8)) {
                        d = 0;
                        p = i;
                        q = j;
                        break;
                    }
                }
                p = i;
                q = j;
                d = 0;
                while (c[p][q] == word[b][d]) {
                    p--;
                    q--;
                    d++;
                    if (word[b].length() == d) {
                        cout << word[b] << endl;
                        d = 0;
                        p = i;
                        q = j;
                        break;
                    }
                    if ((p == -1) || (q == -1)) {
                        d = 0;
                        p = i;
                        q = j;
                        break;
                    }
                }
                p = i;
                q = j;
                d = 0;
                while (c[p][q] == word[b][d]) {
                    p++;
                    q--;
                    d++;
                    if (word[b].length() == d) {
                        cout << word[b] << endl;
                        d = 0;
                        p = i;
                        q = j;
                        break;
                    }
                    if ((p == 7) || (q == -1)) {
                        d = 0;
                        p = i;
                        q = j;
                        break;
                    }
                }
                p = i;
                q = j;
                d = 0;
                b++;
            }
        }
    }
    auto done = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(done-started).count();
    return 0;
}