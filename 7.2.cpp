#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    string surname;
    int math;
    int informatics;
    int physics;
};

int main() {
    int n;
    cout << "Введите количество студентов: ";
    cin >> n;
    cin.ignore();

    if (n <= 0) {
        cout << "Некорректное количество студентов." << endl;
        return 1;
    }

    vector<Student> students(n);
    int sum_math = 0, sum_inf = 0, sum_phys = 0;

    for (int i = 0; i < n; ++i) {
        cout << "Студент " << i + 1 << ":\n";
        cout << "Фамилия: ";
        getline(cin, students[i].surname);
        cout << "Оценка по математике: ";
        cin >> students[i].math;
        cout << "Оценка по информатике: ";
        cin >> students[i].informatics;
        cout << "Оценка по физике: ";
        cin >> students[i].physics;
        cin.ignore();

        sum_math += students[i].math;
        sum_inf += students[i].informatics;
        sum_phys += students[i].physics;
    }

    double avg_math = static_cast<double>(sum_math) / n;
    double avg_inf = static_cast<double>(sum_inf) / n;
    double avg_phys = static_cast<double>(sum_phys) / n;

    // Вывод без форматирования (по умолчанию)
    cout << "\nСредний балл по математике: " << avg_math << endl;
    cout << "Средний балл по информатике: " << avg_inf << endl;
    cout << "Средний балл по физике: " << avg_phys << endl;

    return 0;
}