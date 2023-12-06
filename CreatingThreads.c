#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime>
using namespace std;

void printFromMainThread(int iteration) {
    cout << "Main Thread. Iteration: " << iteration << endl;
    this_thread::sleep_for(chrono::seconds(3)); // Очікуємо 3 секунди
}

void printFromChildThread(int iteration) {
    cout << "Child Thread. Iteration: " << iteration << endl;
    this_thread::sleep_for(chrono::seconds(3)); // Очікуємо 3 секунди
}

int main() {
    for (int i = 1; i <= 10; ++i) {
        thread childThread(printFromChildThread, i); // Створюємо об'єкт який починає виконувати передану функцію в окремому потоці
        printFromMainThread(i); // Головний поток починає свою роботу
        childThread.join(); // Чекаємо, поки дитячий потік завершить виконання
    }
    return 0;
}
