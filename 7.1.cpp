#include <iostream>
#include <string>
#include <vector> // Для использования vector
using namespace std;

struct Film {
    string name;
    double price;
    string produser;
};

int main() {
    int n;
    cout << "Введите количество фильмов: ";
    cin >> n;
    cin.ignore();

    if (n <= 0) {
        cout << "Некорректное количество фильмов." << endl;
        return 1;
    }

    // Используем вектор вместо динамического массива
    vector<Film> films(n);

    for (int i = 0; i < n; ++i) {
        cout << "Фильм " << i + 1 << ":\n";
        cout << "Название: ";
        getline(cin, films[i].name);
        cout << "Стоимость: ";
        cin >> films[i].price;
        cin.ignore();
        cout << "Режиссер: ";
        getline(cin, films[i].produser);
    }

    double maxPrice = films[0].price;
    int maxIndex = 0;
    double minPrice = films[0].price;
    int minIndex = 0;

    for (int i = 1; i < n; ++i) {
        if (films[i].price > maxPrice) {
            maxPrice = films[i].price;
            maxIndex = i;
        }
        if (films[i].price < minPrice) {
            minPrice = films[i].price;
            minIndex = i;
        }
    }

    int start, end;
    if (maxIndex < minIndex) {
        start = maxIndex;
        end = minIndex;
    } else {
        start = minIndex;
        end = maxIndex;
    }

    if (end - start < 2) {
        cout << "Нет фильмов между максимальным и минимальным по стоимости." << endl;
    } else {
        cout << "Фильмы между максимальным и минимальным:" << endl;
        for (int i = start + 1; i < end; ++i) {
            cout << "Название: " << films[i].name 
                 << ", Стоимость: " << films[i].price 
                 << ", Режиссер: " << films[i].produser << endl;
        }
    }

    return 0;
}