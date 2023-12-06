#include <iostream>
#include <thread>
#include <string>
using namespace std;

// Функція, яка приймає параметри name, str і num
void threadFunction(string name, string str, int num) {
    for (int i = 1; i <= num; ++i) {
        cout << "Thread " << name << ". " << str << " " << i << endl;
    }
}

int main() {
    // Параметри для кожного з чотирьох потоків
    string names[] = { "Itachi", "Sasuke", "Obito", "Madara" };
    string str[] = { "Amaterasu", "Chidori", "Kamui", "Susano" };
    int num[] = { 5, 2, 3, 1 };
    // Створення та запуск чотирьох потоків
    thread threads[4];
    for (int i = 0; i < 4; ++i) {
        threads[i] = thread(threadFunction, names[i], str[i], num[i]);
        threads[i].join(); // Очікування завершення всіх потоків
    }
    return 0;
}
