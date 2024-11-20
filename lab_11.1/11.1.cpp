#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Функція для створення файлу
void CreateTXT(const char* fname) {
    ofstream fout(fname);
    char ch;
    string line;
    do {
        cin.ignore(); // очищення буфера вводу
        cout << "Enter line: ";
        getline(cin, line);
        fout << line << endl;
        cout << "Continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

// Функція для виведення вмісту файлу
void PrintTXT(const char* fname) {
    ifstream fin(fname);
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
}

// Функція для підрахунку входжень символів '+', '-', '='
void CountSymbols(const char* fname, int& plusCount, int& minusCount, int& equalCount) {
    ifstream fin(fname);
    string line;
    plusCount = minusCount = equalCount = 0;
    while (getline(fin, line)) {
        for (char c : line) {
            if (c == '+') plusCount++;
            else if (c == '-') minusCount++;
            else if (c == '=') equalCount++;
        }
    }
}

int main() {
    char fname[100];
    cout << "Enter file name: ";
    cin >> fname;

    // Створення текстового файлу
    CreateTXT(fname);

    // Виведення вмісту файлу
    cout << "File content:" << endl;
    PrintTXT(fname);

    // Підрахунок символів
    int plusCount, minusCount, equalCount;
    CountSymbols(fname, plusCount, minusCount, equalCount);

    cout << "Occurrences:" << endl;
    cout << "'+' = " << plusCount << endl;
    cout << "'-' = " << minusCount << endl;
    cout << "'=' = " << equalCount << endl;

    return 0;
}
