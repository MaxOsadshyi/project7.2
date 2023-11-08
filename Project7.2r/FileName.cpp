#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void CreateRow(int** a, const int rowNo, const int n, const int Low,
    const int High, int colNo);
void CreateRows(int** a, const int n, const int Low, const int High, int rowNo);
void PrintRow(int** a, const int rowNo, const int n, int colNo);
void PrintRows(int** a, const int n, int rowNo);
void RearrangeMaxElements(int** a, const int n, int row = 0);

int main() {
    srand((unsigned)time(NULL));
    int n;
    cout << "n = "; cin >> n;
    cout << endl;
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];
    int Low = -9, High = 9;
    CreateRows(a, n, Low, High, 0);
    PrintRows(a, n, 0);

    RearrangeMaxElements(a, n);

    cout << "Matrix with max elements on the main diagonal:" << endl;
    PrintRows(a, n, 0);

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void CreateRow(int** a, const int rowNo, const int n, const int Low,
    const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < n - 1)
        CreateRow(a, rowNo, n, Low, High, colNo + 1);
}

void CreateRows(int** a, const int n, const int Low, const int High, int rowNo)
{
    if (rowNo < n)
    {
        CreateRow(a, rowNo, n, Low, High, 0);
        CreateRows(a, n, Low, High, rowNo + 1);
    }
}

void PrintRow(int** a, const int rowNo, const int n, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < n - 1)
        PrintRow(a, rowNo, n, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int n, int rowNo)
{
    if (rowNo < n)
    {
        PrintRow(a, rowNo, n, 0);
        PrintRows(a, n, rowNo + 1);
    }
}

void RearrangeMaxElements(int** a, const int n, int row)
{
    if (row == n)
        return;

    int maxElement = a[row][row];
    int maxElementIndex = row;

    // Знаходимо найбільший елемент в поточному рядку
    for (int j = 0; j < n; j++) {
        if (a[row][j] > maxElement) {
            maxElement = a[row][j];
            maxElementIndex = j;
        }
    }

    // Міняємо місцями найбільший елемент із елементом на головній діагоналі
    int temp = a[row][row];
    a[row][row] = maxElement;
    a[row][maxElementIndex] = temp;

    RearrangeMaxElements(a, n, row + 1);
}
