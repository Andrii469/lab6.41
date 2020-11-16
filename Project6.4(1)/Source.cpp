#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

void max_i(int a[], const int SIZE);
long long dobutok(int a[], int null1, int null2);
int null1i(int a[], const int SIZE);
int null2i(int a[], const int SIZE);
void peretvorennya(int a[], const int SIZE);
int max_r(int a[], const int SIZE, int i, int max);
void nomer_r(int a[], const int SIZE, int n, int max);
int null1r(int a[], const int SIZE, int i);
int null2r(int a[], const int SIZE, int i);
void dobutok_r(int a[], int null1, int null2, int d);
void peretvorennya_r(int a[], const int SIZE, int j, int k);

int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int SIZE, D;
    do
    {
        cout << "������ ����� ������ a[]:"; cin >> SIZE;
        int* a = new int[SIZE];

        cout << "a[] = ";
        for (int i = 0; i < SIZE; i++)
            a[i] = rand() % SIZE;

        int one = rand() % SIZE;
        int two = rand() % SIZE;    //����� ���� ���� ���� �������� ����� ��� 
        a[one] = 0;                 //���������� ����'��������
        a[two] = 0;

        for (int i = 0; i < SIZE; i++)
            cout << a[i] << " ";


        cout << "\n\n�����ֲ���� ���Ѳ�: " << endl; cout << endl;
        max_i(a, SIZE);
        cout << "\n����� ������� ��������, ���� ������� ����: " << null1i(a, SIZE) + 1 << endl;
        cout << "����� ������� ��������, ���� ������� ����: " << null2i(a, SIZE) + 1 << endl;
        cout << "\n������� ��������, �� ������������ �����: ";
        cout << dobutok(a, null1i(a, SIZE) + 1, null2i(a, SIZE)) << endl;
        peretvorennya(a, SIZE);
       
       

        cout << "\n���� ������ ��������� �� ���, ������ 1\n���� � - ����-���� ����� ������ " << endl;
        cin >> D;

        delete[]a;
    } while (D == 1);
    return 0;
}
//����������� �����
void max_i(int a[], const int SIZE)
{
    cout << "�����(�) �����: ";
    int max = a[0];
    for (int i = 1; i < SIZE; i++)
        if (a[i] > max)
            max = a[i];
    for (int j = 0; j < SIZE; j++)
        if (max == a[j])
            cout << j + 1 << " ";
    cout << "\n����������� �����:" << max << endl;
}
long long dobutok(int a[], int null1, int null2)
{
    long long  d = 1;
    for (null1; null1 < null2; null1++)
        d *= a[null1];
    return d;

}
int null1i(int a[], const int SIZE)
{
    for (int c = 0; c < SIZE; c++)
        if (a[c] == 0)
            return c;
}
int null2i(int a[], const int SIZE)
{
    for (int b = 0; b < SIZE; b++)
        if ((a[b] == 0) && (b != null1i(a, SIZE)))
            return b;
}
void peretvorennya(int a[], const int SIZE)
{
    cout << "\n������������� �����: ";
    for (int i = 0; i < SIZE; i++)
        if (i % 2 != 0)
            cout << a[i] << " ";
    for (int i = 0; i < SIZE; i++)
        if (i % 2 == 0)
            cout << a[i] << " ";
}