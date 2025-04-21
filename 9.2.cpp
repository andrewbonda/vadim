#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

bool PerfectSquare(int x) {
    if (x < 0) return false;
    int s = sqrt(x);
    return (s * s == x);
}

bool Fibonacci(int n) {
    return PerfectSquare(5 * n * n + 4) || PerfectSquare(5 * n * n - 4);
}

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Ошибка: не удалось открыть файл." << endl;
        return 1;
    }

    vector<int> numbers;
    int num;
    while (inputFile >> num) {
        numbers.push_back(num);
    }
    inputFile.close();

    int sum = 0;
    for (int n : numbers) {
        if (n >= 0 && Fibonacci(n)) {  
            sum += n;
        }
    }

    cout << "Сумма чисел Фибоначчи в файле: " << sum << endl;
    return 0;
}