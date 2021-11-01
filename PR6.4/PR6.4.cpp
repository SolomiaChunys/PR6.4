#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* &a, const int size) 
{
	a = new int[size];
	for (int i = 0; i < size; i++)
	{
		cout << "a[i] = "; cin >> a[i];
	}
}
void Print(int* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << a[i];
	cout << endl;
}
int Min(int* a, const int size)
{
	int min = a[0];
	for (int i = 0; i < size; i++)
		if (a[i] < min)
			min = a[i];
	return min;
}
int Sum(int* a, const int size) 
{
	int id = 0;
	int s = 0;
	for (int i = 0; i < size; i++)
	{
		if (!id && a[i] < 0)
		{
			id = 1;
			continue;
		}
		if (id && a[i] > 0)
		{
			s += a[i];
			continue;
		}
		if (id && a[i] < 0)
		{
			break;
		}
	}
	return s;
}

void Sort(int* a, const int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int min = a[i];
		int imin = i;
		for (int j = i + 1; j < size; j++)
			if (min > a[j])
			{
				min = a[j];
				imin = j;
			}
		a[imin] = a[i];
		a[i] = min;
	}
}

int main()
{
	int n;
	int* a;
	cout << "n = "; cin >> n;

	Create(a, n);
	Print(a, n);

	cout << "min = " << Min(a, n) << endl;
	cout << "s = " << Sum(a, n) << endl;

	Sort(a, n);
	Print(a, n);
	return 0;
}