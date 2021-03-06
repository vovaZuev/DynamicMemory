#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void FillRand(int* arr, const int n);
void FillRand(int ** arr, const int m, const int n);
void Print(int* arr, const int n);
void Print(int ** arr, const int m, const int n);
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

int** PushRowBack(int** arr, int &m, const int n);
int** PushRowFront(int** arr, int& m, const int n);

void PushColBack(int** arr, const int m, int&n);

int main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
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
#endif

#ifdef DYNAMIC_MEMORY_2
	int m; // Количество строк.
	int n; // Количество столбцов.
	cout << "Введите количество строк: "; cin >> m;
	cout << "Введите количество столбцов: "; cin >> n;
	// 1) Создаем массив указателей.
	int** arr = new int* [m];
	// 2) Выделяем память под строки.
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n] {};
	}
	cout << "Memory allocated" << endl;
	FillRand(arr, m, n);
	// Обращение к элементам массива.
	/*for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}*/
	Print(arr, m, n);
	cout << "Добавляем строку в конец массива: " << endl;
	arr = PushRowBack(arr, m, n);
	Print(arr, m, n);
	cout << "Добавляем строку в начало массива: " << endl;
	arr = PushRowFront(arr, m, n);
	Print(arr, m, n);
	cout << "Добавляем столбец в конец массива: " << endl;
	PushColBack(arr, m, n);
	Print(arr, m, n);
	// Удаление массива.
	// 1) Удаляем строки массива.
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	// 2) Удаляем массив указателей.
	delete[] arr;

#endif
}

void FillRand(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void FillRand(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
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
void Print(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
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
	//if (index >= 0 && index < *n)
	//{
		if (index >= *n)return;
		int* temp = new int[*n + 1];
		for (int i = 0; i < index; i++)
		{
			temp[i] = (*arr)[i];
		}
		//*(temp + index) = value;
		temp[index] = value;
		for (int i = index + 1; i < *n + 1; i++)
		{
			temp[i] = (*arr)[i - 1];
		}
		++(*n);
		delete[] * arr;
		*arr = temp;
	//}
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
int** PushRowBack(int** arr, int &m, const int n)
{
	// 1) Создаем буферный массив.
	int** temp = new int* [m + 1];
	// 2) Копируем адреса существующих строк в новый массив указателей.
	for (int i = 0; i < m; i++)
		temp[i] = arr[i];
	/*for (int i = 0; i < m + 1; i++)
	{
		temp[i] = new int[n] {};
	}*/
	/*// 2) Копируем значения в буферный массив.
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp[i][j] = arr[i][j];
		}
	}*/
	// 3) Удаляем исходный массив указателей.
	/*for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}*/
	delete[] arr;
	// 4) Создаем последнюю строку массива.
	temp[m] = new int[n] {};
	// 5) Увеличиваем количество строк.
	++m;
	// 5) Возвращаем адрес нового массива на место вызова.
	return temp;
}

int** PushRowFront(int** arr, int& m, const int n)
{
	// 1) Создаем буферный массив указателей нужного размера.
	int** buffer = new int* [m + 1];
	// 2) Копируем адреса строк в новый массив.
	for (int i = 0; i < m; i++)
		buffer[i + 1] = arr[i];
	// 3) Удаляем исходный массив указателей.
	delete[] arr;
	// 4) Создаем нулевую строку массива.
	buffer[0] = new int[n] {};
	// 5) Увеличиваем количество строк.
	m++;
	// 6) Возвращаем новый массив.
	return buffer;
}

void PushColBack(int** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		// 1) Создаем буферную строку.
		int* buffer = new int[n + 1]{};
		// 2) Копируем исходную строку массива в буферную.
		for (int j = 0; j < n; j++)
		{
			buffer[j] = arr[i][j];
		}
		// 3) Удаляем исходную строку.
		delete[] arr[i];
		// 4) Подменяем адрес в массиве указателей на адрес новой строки.
		arr[i] = buffer;
	}
	n++;
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