#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * \brief Функция нахождения суммы четных отрицательных элементов массива
 * \param massive Массив
 * \param num количество элементов в массиве
 * \return Возвращает сумму четных отрицательных элементов массива.
 */
int SumFuntction(int* massive, int num);

/**
 * \brief Функция вывода индексов элементов, значения которых кратны 3 и 6
 * \param massive Массив
 * \param num Количество элементов в массиве
 * \return Возвращает 0
 */
int IndexFunction(int* massive, int num);

/**
 * \brief Функция нахождения индекса максимума массива
 * \param massive Массив
 * \param num Количество элементов в массиве
 * \return Возвращает индекс максимума массива
 */
int MaxFunction(int* massive, int num);

/**
 * \brief Функция нахождения индекса минимума массива
 * \param massive Массив
 * \param num Количество элементов в массиве
 * \return Возвращает индекс минимума массива
 */
int MinFunction(int* massive, int num);

/**
 * \brief Функция нахождения случайного числа из заданного интервала
 * \param min минимальное случайное число
 * \param max максимальное случайное число
 * \return Возвращает случайное число из заданного интервала
 */
int random(int min, int max);

/**
 * \brief Функция замены нулями элементов массива между минимальным и максимальным, кроме их самих
 * \param massive Массив
 * \param n Количество элементов в массиве
 * \return Возвращает изменённый массив
 */
int* changeFunction(int* massive, int num);

/**
 * \brief Точка входа в программу
 * \return Возвращает нуль, в случае успеха
 */
int main()
{
    int n;
    cout << "Enter integer value: ";
    cin >> n;
    int* array = new int[n];
    cout << "Input 1, if you want random numbers. Input 2 if you want to input numbers manualy: ";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        for (int i = 0; i < n; i++)
        {
            array[i] = random(-1000, 1000);
        }
    }
    else if (choice == 2)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Input element: ";
            cin >> array[i];
        }
    }
    SumFuntction(array, n);

    IndexFunction(array, n);

    array = changeFunction(array, n);
        for (int i = 0; i < n; i++)
        {
            cout << array[i] << "\n";
        }
    return 0;
}

int SumFuntction(int* array, int num)
{
    int sum = 0;
    for (int i = 0; i < num; i++)
    {
        if (array[i] % 2 == 0 and massive[i] < 0)
        {
            sum = sum + array[i];
        }
    }
    cout << "Sum of even negative elements = " << sum << "\n";
    return 0;
}

int IndexFunction(int* array, int num)
{
    for (int i = 0; i < num; i++)
    {
        if (array[i] % 3 == 0 and massive[i] % 6 == 0)
        {
            cout << "Index of element divisible by 3 and 6 = " << i << "\n";
        }
    }
    return 0;
}

int MaxFunction(int* array, int num)
{
    int max = -1000;
    int index = 0;
    for (int i = 0; i < num; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
            index = i;
        }
    }
    return index;
}

int MinFunction(int* array, int num)
{
    int min = 1000;
    int index = 0;
    for (int i = 0; i < num; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
            index = i;
        }
    }
    return index;
}

int random(int min, int max)
{
    srand(time(NULL) + rand());

    int temp = max - min;

    if (temp == 0)
        temp = 1;

    int value = rand() % temp + min;
    return value;
}

int* changeFunction(int* array, int num)
{
    if (MaxFunction(array, num) > MinFunction(array, num))
    {
        for (int i = MinFunction(array, num) + 1; i < MaxFunction(array, num); i++)
        {
            array[i] = 0;
        }
    }
    else
    {
        for (int i = MaxFunction(array, num) + 1; i < MinFunction(array, num); i++)
        {
            array[i] = 0;
        }
    }
    return array;
}