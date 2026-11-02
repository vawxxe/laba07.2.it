
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Прототипи функцій
void Create(int** a, const int k, const int n,
    const int Low, const int High);

void Print(int** a, const int k, const int n);

bool SearchMinMaxOddColumns(int** a, const int k,
    const int n, int& result);

int main()
{
    srand((unsigned)time(NULL));

    // Межі діапазону випадкових чисел
    int Low = 7;
    int High = 65;

    // Розміри матриці
    int k = 5;
    int n = 6;

    // Створення динамічної матриці
    int** a = new int* [k];

    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    // Формування та виведення матриці
    Create(a, k, n, Low, High);

    cout << "Original matrix:" << endl;
    Print(a, k, n);

    // Пошук найменшого з максимальних
    // елементів по непарних стовпцях
    int result;

    if (SearchMinMaxOddColumns(a, k, n, result))
        cout << "Min of max elements in odd columns = "
        << result << endl;
    else
        cout << "There are no odd columns." << endl;

    // Звільнення пам'яті
    for (int i = 0; i < k; i++)
        delete[] a[i];

    delete[] a;

    return 0;
}

// Формування матриці випадковими числами
void Create(int** a, const int k, const int n,
    const int Low, const int High)
{
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

// Виведення матриці
void Print(int** a, const int k, const int n)
{
    cout << endl;

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];

        cout << endl;
    }

    cout << endl;
}

// Пошук найменшого з максимальних
// елементів по непарних стовпцях
bool SearchMinMaxOddColumns(int** a, const int k,
    const int n, int& result)
{
    bool found = false;

    for (int j = 0; j < n; j += 2)
    {
        int maxElement = a[0][j];

        for (int i = 1; i < k; i++)
        {
            if (a[i][j] > maxElement)
                maxElement = a[i][j];
        }

        if (!found || maxElement < result)
        {
            result = maxElement;
            found = true;
        }
    }

    return found;
}
