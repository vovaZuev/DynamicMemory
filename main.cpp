#include <iostream>
using namespace std;

void FillRand(int* arr, const int n);
void Print(int* arr, const int n);
/*--------------------------------------------------------
int* Push_Back(int* arr, const int n, int push_back);
int* Push_Front(int* arr, const int n, int push_front);
int* Insert(int* arr, const int n, int insert, const int insert_index);
int* Pop_Back(int* arr, const int n);
int* Pop_Front(int* arr, const int n);
int* Erase(int* arr, const int n, const int erase_index);
-----------------------------------------------------------*/
void PushBack(int** arr, int* n, int value);
void PushFront(int** arr, int* n, int value);
void Insert(int** arr, int* n, int value, int index);
void PopBack(int** arr, int* n);
void PopFront(int** arr, int* n);
void Erase(int** arr, int* n, int index);

int main()
{
	setlocale(LC_ALL, "");
	int n;
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
	
	delete[] arr;
}

void FillRand(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void Print(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void PushBack(int** arr, int* n, int value)
{
	int* temp = new int[*n + 1];
	for (int i = 0; i < *n; i++)
	{
		temp[i] = (*arr)[i];
	}
	temp[*n] = value;
	++(*n);
	delete[] * arr;
	*arr = temp;
}
void PushFront(int** arr, int* n, int value)
{
	int* temp = new int[*n + 1];
	temp[0] = value;
	for (int i = 1; i < *n + 1; i++)
	{
		temp[i] = (*arr)[i - 1];
	}
	++(*n);
	delete[] * arr;
	*arr = temp;
}
void Insert(int** arr, int* n, int value, int index)
{
	if (index >= 0 && index < *n)
	{
		int* temp = new int[*n + 1];
		for (int i = 0; i < index; i++)
		{
			temp[i] = (*arr)[i];
		}
		*(temp + index) = value;
		for (int i = index + 1; i < *n + 1; i++)
		{
			temp[i] = (*arr)[i - 1];
		}
		++(*n);
		delete[] * arr;
		*arr = temp;
	}
}
void PopBack(int** arr, int* n)
{
	int* temp = new int[*n - 1];
	for (int i = 0; i < *n - 1; i++)
	{
		temp[i] = (*arr)[i];
	}
	--(*n);
	delete[] * arr;
	*arr = temp;
}
void PopFront(int** arr, int* n)
{
	int* temp = new int[*n - 1];
	for (int i = 0; i < *n - 1; i++)
	{
		temp[i] = (*arr)[i + 1];
	}
	--(*n);
	delete[] * arr;
	*arr = temp;
}
void Erase(int** arr, int* n, int index)
{
	if (index >= 0 && index < *n)
	{
		int* temp = new int[*n - 1];
		for (int i = 0; i < index; i++)
		{
			*(temp + i) = (*arr)[i];
		}
		for (int i = index + 1; i < *n; i++)
		{
			temp[i - 1] = (*arr)[i];
		}
		--(*n);
		delete[] * arr;
		*arr = temp;
	}
}
/*----------------------------------------------------------
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
---------------------------------------------------------------*/