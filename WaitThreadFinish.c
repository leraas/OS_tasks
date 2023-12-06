#include <iostream>
#include <thread>
#include <ctime>
using namespace std;

// Функція для виведення заданої кількості разів заданого рядка
void printString(int count) {
    for (int i = 0; i < count; ++i) {
        cout << "Child Thread. Iteration: " << i << endl;
        this_thread::sleep_for(chrono::seconds(2)); // Потік засинає на 2 секунди
    }
}

// Функція для генерації псевдовипадкових чисел та їх виведення
void generateRandomNumbers(int count, int stopValue) {
    srand((time(nullptr)));
    for (int i = 0; i < count; i++) {
        int randomNumber = rand() % 10 + 1;
        cout << "Random Number: " << randomNumber << endl;
        if (randomNumber == stopValue) {
            cout << "Thread is stopping due to the specified random number!" << endl;
            return;
        }
        this_thread::sleep_for(chrono::seconds(3)); // Потік засинає на 3 секунди
    }
}

int main() {
    int stringCount = 20;
    int randomNumberCount = 10;
    int stopRandomNumber = 5;
    // Створення потоку для виведення рядка
    thread stringThread(printString, stringCount);
    // Створення потоку для генерації псевдовипадкових чисел
    thread randomThread(generateRandomNumbers, randomNumberCount, stopRandomNumber);
    // Очікування завершення обох потоків
    stringThread.join();
    randomThread.join();
    // Виведення повідомлення основним потоком
    cout << "Main thread is done!" << endl;
    return 0;
}
