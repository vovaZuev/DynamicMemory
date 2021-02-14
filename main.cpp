#include <iostream>
using namespace std;

void FillRand(int* arr, const int n);
void Print(int* arr, const int n);

int* Push_Back(int* arr, const int n, int push_back);
int* Push_Front(int* arr, const int n, int push_front);
int* Insert(int* arr, const int n, int insert, const int insert_index);
int* Pop_Back(int* arr, const int n);
int* Pop_Front(int* arr, const int n);
int* Erase(int* arr, const int n, const int erase_index);


int main()
{
	setlocale(LC_ALL, "");
	int n;
	int push_back, push_front;
	int insert, insert_index;
	int erase_index;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	cout << "Исходный массив: " << endl;
	Print(arr, n);

	// ??? push_back(???);	//Добавляет значение в конец динамического массива.
	cout << "Введите число, чтобы добавить в конец массива: "; cin >> push_back;
	arr = Push_Back(arr, n, push_back);
	Print(arr, ++n);

	// ? ? ? push_front(? ? ? );	//Добавляет значение в начало динамического массива.
	cout << "Введите число, чтобы добавить в начало массива: "; cin >> push_front;
	arr = Push_Front(arr, n, push_front);
	Print(arr, ++n);

	// ??? insert(???);	//Добавляет значение в массив по указанному индексу.
	cout << "Введите число, которое нужно вставить в массив, и индекс вставки: "; cin >> insert >> insert_index;
	arr = Insert(arr, n, insert, insert_index);
	Print(arr, ++n);

	// ??? pop_back(???);	//Удаляет последний элемент массива.
	cout << "Последний элемент массива удалён: " << endl;
	arr = Pop_Back(arr, n);
	Print(arr, n--); // Выводим n элементов, чтобы увидеть мусор на месте последнего элемента.

	// ??? pop_front(???);	//Удаляет нулевой элемент массива.
	cout << "Нулевой элемент массива удалён: " << endl;
	arr = Pop_Front(arr, n);
	Print(arr, --n);

	// ??? erase(???);		//Удаляет значение из массива по указанному индексу.
	cout << "Введите индекс, по которому нужно удалить элемент: "; cin >> erase_index;
	arr = Erase(arr, n, erase_index);
	Print(arr, --n);

	delete[] arr;
}

void FillRand(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		// * - оператор разыменования, возвращает значение по адресу.
		*(arr + i) = rand() % 100;
	}
}
void Print(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		// [] - оператор индексирования, возвращает значение по индексу.
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int* Push_Back(int* arr, const int n, int push_back)
{
	int* temp = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		temp[i] = arr[i];
	}
	temp[n] = push_back;
	return temp;
}
int* Push_Front(int* arr, const int n, const int push_front)
{
	int* temp = new int[n + 1];
	temp[0] = push_front;
	for (int i = 1; i < n + 1; i++)
	{
		temp[i] = arr[i - 1];
	}
	return temp;
}
int* Insert(int* arr, const int n, int insert, const int insert_index)
{
	if (insert_index >= 0 && insert_index < n)
	{
		int* temp = new int[n + 1];
		for (int i = 0; i < insert_index; i++)
		{
			temp[i] = arr[i];
		}
		temp[insert_index] = insert;
		for (int i = insert_index + 1; i < n + 1; i++)
		{
			temp[i] = arr[i - 1];
		}
		return temp;
	}
	else
		return arr;
}
int* Pop_Back(int* arr, const int n)
{
	int* temp = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		temp[i] = arr[i];
	}
	return temp;
}
int* Pop_Front(int* arr, const int n)
{
	int* temp = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		temp[i] = arr[i + 1];
	}
	return temp;
}
int* Erase(int* arr, const int n, const int erase_index)
{
	if (erase_index >= 0 && erase_index < n)
	{
		int* temp = new int[n - 1];
		for (int i = 0; i < erase_index; i++)
		{
			temp[i] = arr[i];
		}
		for (int i = erase_index + 1; i < n; i++)
		{
			temp[i - 1] = arr[i];
		}
		return temp;
	}
	else
		return arr;
}