#include <iostream>
#include <thread>
#include <vector>
using namespace std;

// Функція для обчислення факторіалу числа
int factorial(int n) {
    if (n < 0) {
        // Якщо число від'ємне, повертаємо помилку (-1)
        return -1;
    } else if (n == 0 || n == 1) {
        // Факторіал 0 і 1 - це 1
        return 1;
    } else {
        // Обчислення факторіалу
        int fact = 1;
        for (int i = 2; i <= n; i++) {
            fact = fact * i;
        }
        return fact;
    }
}

// Функція для обчислення чисел Каталана
void calculateCatalanNumbers(int n, vector<int>& result) {
    int catalan = 1;
    result.clear();
    result.push_back(catalan);
    for (int i = 2; i <= n; i++) {
        catalan = factorial(2 * i) / (factorial(i + 1) * factorial(i)); // Незнаю чому але після числа 132 воно видає 6, 1, 0, 1, чому обчислення збивається я не розумію
        result.push_back(catalan);
    }
}

// Допоміжна функція для перевірки числа на простоту
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

// Функція для обчислення перших простих чисел
void calculatePrimeNumbers(int n, vector<int>& result) {
    result.clear();
    int count = 0;
    int num = 2;
    while (count < n) {
        if (isPrime(num)) {
            result.push_back(num);
            count++;
        }
        num++;
    }
}

int main() {
    int catalanCount = 10; // Кількість чисел Каталана
    int primeCount = 10;   // Кількість перших простих чисел
    vector<int> catalanResult;
    vector<int> primeResult;
    thread catalanThread(calculateCatalanNumbers, catalanCount, ref(catalanResult)); // Створюємо потік який виконує обчислення чисел Каталана
    thread primeThread(calculatePrimeNumbers, primeCount, ref(primeResult)); // Створюємо потік який виконує обчислення простих чисел
    // Чекаємо на завершення обох потоків
    catalanThread.join();
    primeThread.join();
    // Виводимо результати
    cout << "Перші " << catalanCount << " чисел Каталана: ";
    for (int num : catalanResult) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Перші " << primeCount << " простих чисел: ";
    for (int num : primeResult) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
