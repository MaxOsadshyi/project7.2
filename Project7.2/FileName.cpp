#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
void RearrangeMaxElements(int** a, const int n);

int main() {
    srand((unsigned)time(NULL));
    int Low = 7;
    int High = 65;
    int n;
    cout << " n: ";
    cin >> n;
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Create(a, n, Low, High);
    cout << "Original Matrix:" << endl;
    Print(a, n);

    RearrangeMaxElements(a, n);

    cout << "Matrix with max elements on the main diagonal:" << endl;
    Print(a, n);

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int n, const int Low, const int High) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
}

void RearrangeMaxElements(int** a, const int n) {
    for (int i = 0; i < n; i++) {
        int maxElement = a[i][i];
        int maxElementIndex = i;

        // Знаходимо найбільший елемент в поточному рядку
        for (int j = 0; j < n; j++) {
            if (a[i][j] > maxElement) {
                maxElement = a[i][j];
                maxElementIndex = j;
            }
        }

        // Міняємо місцями найбільший елемент із елементом на головній діагоналі
        int temp = a[i][i];
        a[i][i] = maxElement;
        a[i][maxElementIndex] = temp;
    }
}
