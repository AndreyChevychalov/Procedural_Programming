#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * \brief Функция нахождения случайного числа из заданного интервала
 * \param min минимальное случайное число
 * \param max максимальное случайное число
 * \return Возвращает случайное число из заданного интервала
 */
int random(int min, int max);

/**
 * \brief Функция замены максимального элемента массива на противоположный по знаку
 * \param array Введённый массив
 * \param num Количество элементов в массиве
 * \return Возвращает массив с максимальным элементом, противоположным по знаку
 */
int* maxFunction(int* array, int num);

/**
 * \brief Функция нахождения массива в котором после всех элементов, в которых есть цифра 1, вставлен максимальный элемент
 * \param array Введённый массив
 * \param num Количество элементов в массиве
 * \return Возвращает необходимый массив
 */
int* oneFunction(int* array, int num);

/**
 * \brief Функция нахождения индекса максимума массива
 * \param elem Введённый массив
 * \param num Количество элементов в массиве
 * \return Возвращает индекс максимума массива
 */
int maxElement(int* array, int num);

/**
 * \brief Функция формирования нового массива, сформированного по правилу из 3 задачи
 * \param array Введённый массив
 * \param num Количество элементов в массиве
 * \return Возвращает новый массив
 */
int* newArray(int* array, int n);

/**
 * \brief Функция нахождения количества элементов, в которых есть цифра 1
 * \param array Введённый массив
 * \param num Количество элементов в массиве
 * \return Возвращает количество элементов, в которых есть цифра 1
 */
int elementAmmount(int* array, int n);

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
    int answer;
    cin >> answer;
    if (answer == 1)
    {
        for (int i = 0; i < n; i++)
        {
            array[i] = random(-1000, 1000);
        }
    }
    else if (answer == 2)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Input element: ";
            cin >> array[i];
        }
    }
    else
    {
        cout << "Input error, array filled with random numbers";
        for (int i = 0; i < n; i++)
        {
            array[i] = random(-1000, 1000);
        }
    }
    array = maxFunction(array, n);

    int* secondArray = new int[n + elementAmmount(array, n)];

    secondArray = oneFunction(array, n);

    int* thirdArray = new int[n + elementAmmount(array, n)];

    for (int i = 0; i < n + elementAmmount(array, n); i++)
    {
        cout << i + 1 << ")" << thirdArray[i] << "\n";
    }

}

int* maxFunction(int* array, int num)
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
    array[index] = -array[index];
    return array;
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

int* oneFunction(int* array, int num)
{
    int* tempArray = new int[num + elementAmmount(array, num)];

    for (int i = 0; i < num; i++)
    {
        tempArray[i] = array[i];
    }

    for (int i = 0; i < num + elementAmmount(array, num); i++)
    {
        int temp = abs(tempArray[i]);
        int index = 0;
        while (temp > 0)
        {
            if (temp % 10 == 1)
            {
                index = 1;
            }
            temp = temp / 10;
        }
        if (index == 1)
        {
            for (int j = num + elementAmmount(array, num); j > i + 1; j = j - 1)
            {
                tempArray[j] = tempArray[j - 1];
            }
            tempArray[i + 1] = array[maxElement(array, num)];
            i++;
        }
    }
    return tempArray;
}

int maxElement(int* array, int num)
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

int* newArray(int* array, int num)
{
    int* newArray = new int[num];
    if (num > 10)
    {
        for (int i = 0; i < 11; i++)
        {
            newArray[i] = array[i] + i;
        }
        for (int i = 11; i < num + 1; i++)
        {
            newArray[i] = array[i] - i;
        }
    }
    else
    {
        for (int i = 0; i < num + 1; i++)
        {
            newArray[i] = array[i] + i;
        }
    }
    return newArray;
}

int elementAmmount(int* array, int n)
{
    int ammount = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = abs(array[i]);
        int index = 0;
        while (temp > 0)
        {
            if (temp % 10 == 1)
            {
                index = 1;
            }
            temp = temp / 10;
        }
        if (index == 1)
        {
            temp = 0;
            ammount++;
        }
    }
    return ammount;
}