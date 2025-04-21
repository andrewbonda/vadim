#include <iostream>
#include <fstream>
using namespace std;


void p(const string& g_name, const string& f_name, const string& h_name) {
    ifstream g(g_name);
    ofstream f(f_name);
    ofstream h(h_name);

    int num;
    while (g >> num) {
        if (num == 0) break;
        if (num > 0) {
            f << num << " ";
        } else {
            h << num << " ";
        }
    }
}

int main() {
    ofstream g_file("g.txt");
    int number;
    cout << "Введите числа (0 для завершения): ";
    while (true) {
        cin >> number;
        g_file << number << " ";
        if (number == 0) break;
    }
    g_file.close();

    p("g.txt", "f.txt", "h.txt");

    ifstream f_file("f.txt");
    cout << "\nПоложительные числа (f.txt):\n";
    while (f_file >> number) {
        cout << number << " ";
    }
    f_file.close();

    ifstream h_file("h.txt");
    cout << "\n\nОтрицательные числа (h.txt):\n";
    while (h_file >> number) {
        cout << number << " ";
    }
    h_file.close();

    return 0;
}