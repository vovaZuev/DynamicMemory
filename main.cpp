#include <iostream>
#include "Memory.h"
#include "Memory.cpp"
#include "FillRand.h"
#include "FillRand.cpp"
#include "Print.h"
#include "Print.cpp"
#include "Array.h"
#include "Array.cpp"
using namespace std;
using std::cout;
using std::cin;
using std::endl;

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

int main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	/*int n;
	int pb_value, pf_value;
	int ins_value, ins_index;
	int ers_index;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	cout << "Исходный массив: " << endl;
	Print(arr, n);

	//Добавляет значение в конец динамического массива.
	cout << "Введите число, чтобы добавить в конец массива: "; cin >> pb_value;
	PushBack(&arr, &n, pb_value);
	Print(arr, n);

	//Добавляет значение в начало динамического массива.
	cout << "Введите число, чтобы добавить в начало массива: "; cin >> pf_value;
	PushFront(&arr, &n, pf_value);
	Print(arr, n);

	//Добавляет значение в массив по указанному индексу.
	cout << "Введите число, которое нужно вставить в массив, и индекс вставки: "; cin >> ins_value >> ins_index;
	Insert(&arr, &n, ins_value, ins_index);
	Print(arr, n);

	//Удаляет последний элемент массива.
	cout << "Последний элемент массива удалён: " << endl;
	PopBack(&arr, &n);
	Print(arr, n); // Выводим n элементов, чтобы увидеть мусор на месте последнего элемента.

	//Удаляет нулевой элемент массива.
	cout << "Нулевой элемент массива удалён: " << endl;
	PopFront(&arr, &n);
	Print(arr, n);

	//Удаляет значение из массива по указанному индексу.
	cout << "Введите индекс, по которому нужно удалить элемент: "; cin >> ers_index;
	Erase(&arr, &n, ers_index);
	Print(arr, n);

	delete[] arr;*/
#endif

#ifdef DYNAMIC_MEMORY_2
	int m; // Количество строк.
	int n; // Количество столбцов.
	cout << "Введите количество строк: "; cin >> m;
	cout << "Введите количество столбцов: "; cin >> n;

	typedef double DataType;
	DataType** arr = Allocate<DataType>(m, n);
	cout << "Memory allocated" << endl;

	FillRand(arr, m, n);
	Print(arr, m, n);
	
	cout << "Добавляем столбец в начало массива: " << endl;
	PushColFront(arr, m, n);
	Print(arr, m, n);
	cout << "Добавляем столбец по индексу " << (n - 2 > 0 ? n - 2 : n) << ":\n";
	InsertCol(arr, m, n, n - 2 > 0 ? n - 2 : n);
	Print(arr, m, n);
	cout << "Удаляем столбец в конце массива: " << endl;
	PopColBack(arr, m, n);
	Print(arr, m, n);
	cout << "Удаляем столбец в начале массива: " << endl;
	PopColFront(arr, m, n);
	Print(arr, m, n);
	cout << "Удаляем столбец по индексу " << (n - 2 > 0 ? n - 2 : n) << ":\n";
	EraseCol(arr, m, n, n - 2 > 0 ? n - 2 : n);
	Print(arr, m, n);
	
	Clear(arr, m);

#endif
}