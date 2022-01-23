#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

int main() {
    string txt;
    int baris, kolom, keywords, i, j, a, b, c, d;
    int checking = 0;
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
    for (i = 0; i < baris; i++) {
        for (j = 0; j < kolom; j++) {
            a = i;
            b = j;
            c = 0;
            d = 0;
            while (c < keywords) {
                if (a - word[c].length() + 1 >= 0) { // vertikal ke atas
                    while (character[a][b] == word[c][d]) {
                        a--;
                        d++;
                        checking++;
                        if (word[c].length() == d) {
                            a = i;
                            b = j;
                            d = 0;
                            cout << word[c] << endl;
                            break;
                        }
                    }
                    checking += 1;
                    a = i;
                    b = j;
                    d = 0;
                }
                if (a + word[c].length() - 1 < baris) { // vertikal ke bawah
                    while (character[a][b] == word[c][d]) {
                        a++;
                        d++;
                        checking++;
                        if (word[c].length() == d) {
                            a = i;
                            b = j;
                            d = 0;
                            cout << word[c] << endl;
                            break;
                        }
                    }
                    checking += 1;
                    a = i;
                    b = j;
                    d = 0;
                }
                if (b + word[c].length() - 1 < kolom) { // horizontal ke kanan
                    while (character[a][b] == word[c][d]) {
                        b++;
                        d++;
                        checking++;
                        if (word[c].length() == d) {
                            a = i;
                            b = j;
                            d = 0;
                            cout << word[c] << endl;
                            break;
                        }
                    }
                    checking += 1;
                    a = i;
                    b = j;
                    d = 0;
                }
                if (b - word[c].length() + 1 >= 0) { // horizontal ke kiri
                    while (character[a][b] == word[c][d]) {
                        b--;
                        d++;
                        checking++;
                        if (word[c].length() == d) {
                            a = i;
                            b = j;
                            d = 0;
                            cout << word[c] << endl;
                            break;
                        }
                    }
                    checking += 1;
                    a = i;
                    b = j;
                    d = 0;
                }
                if ((a - word[c].length() + 1 >= 0) && (b + word[c].length() - 1 < kolom)) { // diagonal ke kanan atas
                    while (character[a][b] == word[c][d]) {
                        a--;
                        b++;
                        d++;
                        checking++;
                        if (word[c].length() == d) {
                            a = i;
                            b = j;
                            d = 0;
                            cout << word[c] << endl;
                            break;
                        }
                    }
                    checking += 1;
                    a = i;
                    b = j;
                    d = 0;
                }
                if ((a + word[c].length() - 1 < baris) && (b + word[c].length() - 1 < kolom)) { // diagonal ke kanan bawah
                    while (character[a][b] == word[c][d]) {
                        a++;
                        b++;
                        d++;
                        checking++;
                        if (word[c].length() == d) {
                            a = i;
                            b = j;
                            d = 0;
                            cout << word[c] << endl;
                            break;
                        }
                    }
                    checking += 1;
                    a = i;
                    b = j;
                    d = 0;
                }
                if ((a - word[c].length() + 1 >= 0) && (b - word[c].length() + 1 >= 0)) { // diagonal ke kiri atas
                    while (character[a][b] == word[c][d]) {
                        a--;
                        b--;
                        d++;
                        checking++;
                        if (word[c].length() == d) {
                            a = i;
                            b = j;
                            d = 0;
                            cout << word[c] << endl;
                            break;
                        }
                    }
                    checking += 1;
                    a = i;
                    b = j;
                    d = 0;
                }
                if ((a + word[c].length() - 1 < baris) && (b - word[c].length() + 1 >= 0)) { // diagonal ke kiri bawah
                    while (character[a][b] == word[c][d]) {
                        a++;
                        b--;
                        d++;
                        checking++;
                        if (word[c].length() == d) {
                            a = i;
                            b = j;
                            d = 0;
                            cout << word[c] << endl;
                            break;
                        }
                    }
                    checking += 1;
                    a = i;
                    b = j;
                    d = 0;
                }
                c++;
            }
        }
    }
    auto done = std::chrono::high_resolution_clock::now();
    std::cout << "Waktu eksekusi program : " << std::chrono::duration_cast<std::chrono::milliseconds>(done-started).count() << " ms" << endl;
    cout << "Jumlah total perbandingan huruf yang dilakukan : " << checking << endl;
    return 0;
}