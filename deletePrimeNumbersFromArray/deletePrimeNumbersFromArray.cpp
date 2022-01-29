//Завдання 2.Написати функцію, яка отримує покажчик на  динамічний масив і його розмір.Функція має видалити з масиву всі прості числа та повернути покажчик на новий динамічний масив
#include <iostream>
#include <cmath>
#include <Windows.h>// підключення заголовного файлу Windows.h, завдяки чому зможемо використовувати українську мову
#include <ctime>//використовуємо дану бібліотеку для рандомного заповнення масивів
using namespace std;
void inputArr(int* arr, int size) {//створюємо функцію для заповнення масиву
    for (int i = 0; i < size; i++)//використовуємо цикл для заповнення масиву
    {
        arr[i] = rand() % 100+1;//рандомно заповнюєм масив (рандомні числа від 0 до 100)
    }
}
void printArr(const int* arr, const int size) {//створюємо функцію для виведення елементів масиву
    for (int i = 0; i < size; i++)//використовуємо цикл для виведення елементів масиву
    {
        cout << "arr[" << i << "]=" << " " << arr[i] << endl;//виводимо елементи масиву
    }
}
bool primeNumber(int n) {//функція пошуку простих чисел
    bool result(true);

    if ((n == 2) or (n == 3))
        result = true;
    else {
        for (int i = 2; i <= floor(sqrt(n)); ++i)
            if (n % i == 0)
            {
                result = false;
                break;
            }
    }
    return (result and (n!= 1));
}
void checkPrimeNumber(const int* arr, int* newArr, const int size) {// функція перевірки і видалення простих чисел
    int count = 0;//створюємо змінну для підрахунку кількості елементів
    for (int i = 0; i < size; ++i) {
        if (!primeNumber(arr[i]))//якщо числа не прості
            ++count; //підраховуємо кількість елементів без простих чисел
    }
    int j = 0;
    for (int i = 0; i < size; ++i) {
        if (!primeNumber(arr[i]))//якщо числа не прості
            newArr[j++] = arr[i];//створюємо новий масив без простих чисел
    }
    for (int j = 0; j < count; j++)
        cout << "newArr[" << j << "]=" << " " << newArr[j] << endl;
}
int main()
{
    srand(time(NULL));//завдяки даній функції, рандомні числа будуть постійно змінюватись 
    SetConsoleCP(1251); // встановлення кодування Windows-1251 в  потік введення
    SetConsoleOutputCP(1251); // встановлення кодування Windows-1251 в  потік виведення
    int size = 1, count = 1;//оголошуємо розмірність першого масиву size
    cout << "Введіть розмір   size  елементів  масиву" << endl;
    cin >> size;
    int* arr = new int[size];//оголошуємо вказівник  arr 
    int* newArr = new int[count]; //оголошуємо вказівник  newArr
    inputArr(arr, size);//звертаємось до функції inputArr - для введення масиву
    cout << "Елементи  масиву" << endl;
    printArr(arr, size);//звертаємось до функції printArr - для виведення масиву
    cout << "Елементи нового масиву- які не містять простих чисел" << endl;
    checkPrimeNumber(arr, newArr, size); //звертаємось до функції знаходження і видалення простих чисел
   // printArr(newArr, count);//звертаємось до функції printArr - для виведення масиву
    delete[]arr;//видаляємо вміст  масиву
    delete[]newArr;//видаляємо вміст  масиву
}
