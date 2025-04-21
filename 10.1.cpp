#include <iostream>
#include <string>
using namespace std;

int digits(const string& s) {
    if (s.empty()) {
        return 0;
    }
    int count = (s[0] >= '0' && s[0] <= '9') ? 1 : 0;
    return count + digits(s.substr(1));
}

int main() {
    string input;
    cout << "Введите строку: ";
    getline(cin, input);

    cout << "Количество цифр в строке: " << digits(input) << endl;
    return 0;
}