#include <iostream>
#include <cstring> 
using namespace std;


void FillArray(int* const arr, const int size)	// ������� ���������� �������
{
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 30;
}

void ShowArray(const int* const arr, const int size)  // ������� ������ ������� �� �������
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << "\t";

	cout << endl;
}

void push_back(int*& arr, int& size, const int value)  // ������� ���������� ������� ����� ������� � ���������� � ������
{
	int* newArray = new int[size + 1];

	for (int i = 0; i < size; i++)
		newArray[i] = arr[i];

	newArray[size] = value;
	size++;

	delete[] arr;
	arr = newArray;
}

void pop_back(int*& arr, int& size)  // ������� �������� �� ������� ��������� ������
{
	size--;
	int* newArray = new int[size];

	for (int i = 0; i < size; i++)
		newArray[i] = arr[i];

	delete[] arr;
	arr = newArray;
}

void push_zero(int*& arr, int& size, const int value)  // ������� ���������� ����� � ������ ������ �� ������� ����� ������� �� ���� �������� ������
{
	int* newArray = new int[size + 1];
	size++;

	for (int i = 0; i < size; i++)
		newArray[i + 1] = arr[i];

	newArray[0] = value;
	delete[] arr;
	arr = newArray;
}

void pop_zero(int*& arr, int& size)  // ������� �������� ������ ������ �������
{
	int* newArray = new int[size];

	for (int i = 1; i < size; i++)
		newArray[i - 1] = arr[i];

	size--;
	delete[] arr;
	arr = newArray;
}


int main()
{
	//	srand(time(NULL));
	int size = 7;
	int* arr = new int[size];

	FillArray(arr, size);  // ������� ���������� �������
	ShowArray(arr, size);  // ������� ������ ������� �� �������

	push_back(arr, size, 111);  // ������� ���������� ������� ����� ������� � ���������� � ������ 111.
	ShowArray(arr, size);

	pop_back(arr, size);  // ������� �������� �� ������� ��������� ������ � ������ value = 111
	ShowArray(arr, size);

	push_zero(arr, size, 222);  // ������� ���������� ������� ������ [�������] ������� � ���������� � ������ value = 222
	ShowArray(arr, size);

	pop_zero(arr, size);  // ������� �������� �� ������� ������ ������ � ������ value = 222
	ShowArray(arr, size);

	delete[] arr;
	cout << endl;
}
