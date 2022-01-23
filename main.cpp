#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

int main() {
    string txt;
    int baris, kolom, keywords, i, j, k, a, b, c;
    int checking = 0;
    bool found;
    cout << "Masukkan nama file : ";
    cin >> txt;
    cout << "Masukkan jumlah baris : ";
    cin >> baris;
    cout << "Masukkan jumlah kolom : ";
    cin >> kolom;
    cout << "Masukkan jumlah kata kunci : ";
    cin >> keywords;
    char character[baris][kolom];
    string word[keywords];
    string line;
    ifstream file;
    file.open(txt);
    for (i = 0; i < baris; i++) {
        for (j = 0; j < kolom; j++) {
            file >> character[i][j];
        }
    }
    int idx = 0;
    while (getline(file, line)) {
        file >> word[idx];
        idx++;
    }
    file.close();
    auto started = std::chrono::high_resolution_clock::now();
    for (i = 0; i < keywords; i++) {
        found = false;
        for (j = 0; j < baris; j++) {
            for (k = 0; k < kolom; k++) {
                a = j;
                b = k;
                c = 0;
                if (a - word[i].length() + 1 >= 0) { // vertikal ke atas
                    while (character[a][b] == word[i][c]) {
                        a--;
                        c++;
                        checking++;
                        if (word[i].length() == c) {
                            found = true;
                            cout << word[i] << endl;
                            break;
                        }
                    }
                    if (found) {
                        break;
                    }
                    checking += 1;
                    a = j;
                    b = k;
                    c = 0;
                }
                if (a + word[i].length() - 1 < baris) { // vertikal ke bawah
                    while (character[a][b] == word[i][c]) {
                        a++;
                        c++;
                        checking++;
                        if (word[i].length() == c) {
                            found = true;
                            cout << word[i] << endl;
                            break;
                        }
                    }
                    if (found) {
                        break;
                    }
                    checking += 1;
                    a = j;
                    b = k;
                    c = 0;
                }
                if (b + word[i].length() - 1 < kolom) { // horizontal ke kanan
                    while (character[a][b] == word[i][c]) {
                        b++;
                        c++;
                        checking++;
                        if (word[i].length() == c) {
                            found = true;
                            cout << word[i] << endl;
                            break;
                        }
                    }
                    if (found) {
                        break;
                    }
                    checking += 1;
                    a = j;
                    b = k;
                    c = 0;
                }
                if (b - word[i].length() + 1 >= 0) { // horizontal ke kiri
                    while (character[a][b] == word[i][c]) {
                        b--;
                        c++;
                        checking++;
                        if (word[i].length() == c) {
                            found = true;
                            cout << word[i] << endl;
                            break;
                        }
                    }
                    if (found) {
                        break;
                    }
                    checking += 1;
                    a = j;
                    b = k;
                    c = 0;
                }
                if ((a - word[i].length() + 1 >= 0) && (b + word[i].length() - 1 < kolom)) { // diagonal ke kanan atas
                    while (character[a][b] == word[i][c]) {
                        a--;
                        b++;
                        c++;
                        checking++;
                        if (word[i].length() == c) {
                            found = true;
                            cout << word[i] << endl;
                            break;
                        }
                    }
                    if (found) {
                        break;
                    }
                    checking += 1;
                    a = j;
                    b = k;
                    c = 0;
                }
                if ((a + word[i].length() - 1 < baris) && (b + word[i].length() - 1 < kolom)) { // diagonal ke kanan bawah
                    while (character[a][b] == word[i][c]) {
                        a++;
                        b++;
                        c++;
                        checking++;
                        if (word[i].length() == c) {
                            found = true;
                            cout << word[i] << endl;
                            break;
                        }
                    }
                    if (found) {
                        break;
                    }
                    checking += 1;
                    a = j;
                    b = k;
                    c = 0;
                }
                if ((a - word[i].length() + 1 >= 0) && (b - word[i].length() + 1 >= 0)) { // diagonal ke kiri atas
                    while (character[a][b] == word[i][c]) {
                        a--;
                        b--;
                        c++;
                        checking++;
                        if (word[i].length() == c) {
                            found = true;
                            cout << word[i] << endl;
                            break;
                        }
                    }
                    if (found) {
                        break;
                    }
                    checking += 1;
                    a = j;
                    b = k;
                    c = 0;
                }
                if ((a + word[i].length() - 1 < baris) && (b - word[i].length() + 1 >= 0)) { // diagonal ke kiri bawah
                    while (character[a][b] == word[i][c]) {
                        a++;
                        b--;
                        c++;
                        checking++;
                        if (word[i].length() == c) {
                            found = true;
                            cout << word[i] << endl;
                            break;
                        }
                    }
                    if (found) {
                        break;
                    }
                    checking += 1;
                    a = j;
                    b = k;
                    c = 0;
                }
            }
            if (found) {
                break;
            }
        }
    }
    auto done = std::chrono::high_resolution_clock::now();
    std::cout << "Waktu eksekusi program : " << std::chrono::duration_cast<std::chrono::milliseconds>(done-started).count() << " ms" << endl;
    cout << "Jumlah total perbandingan huruf yang dilakukan : " << checking << endl;
    return 0;
}