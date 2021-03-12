#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

template <typename T> T** Allocate(const int m, const int n);
template <typename T> void Clear(T** arr, const int m);

template <typename T> void Random(T & value);

template <typename T> void FillRand(T* arr, const int n);
template <typename T> void FillRand(T ** arr, const int m, const int n);
template <typename T> void Print(T* arr, const int n);
template <typename T> void Print(T ** arr, const int m, const int n);
/*--------------------------------------------------------
int* Push_Back(int* arr, const int n, int push_back);
int* Push_Front(int* arr, const int n, int push_front);
int* Insert(int* arr, const int n, int insert, const int insert_index);
int* Pop_Back(int* arr, const int n);
int* Pop_Front(int* arr, const int n);
int* Erase(int* arr, const int n, const int erase_index);
-----------------------------------------------------------*/
template <typename T> void PushBack(T** arr, int* n, int value);
template <typename T> void PushFront(T** arr, int* n, int value);
template <typename T> void Insert(T** arr, int* n, int value, int index);
template <typename T> void PopBack(T** arr, int* n);
template <typename T> void PopFront(T** arr, int* n);
template <typename T> void Erase(T** arr, int* n, int index);
template <typename T> void PushColBack(T** arr, const int m, int& n);

template <typename T> T** PushRowBack(T** arr, int &m, const int n);
template <typename T> T** PushRowFront(T** arr, int& m, const int n);
// Домашнее задание
template <typename T> T** InsertRow(T** arr, int &m, const int n, const int index);
template <typename T> T** PopRowBack(T** arr, int &m, const int n);
template <typename T> T** PopRowFront(T** arr, int &m, const int n);
template <typename T> T** EraseRow(T** arr, int &m, const int n, const int index);

template <typename T> void PushColFront(T** arr, const int m, int &n);
template <typename T> void InsertCol(T** arr, const int m, int &n, const int index);
template <typename T> void PopColBack(T** arr, const int m, int &n);
template <typename T> void PopColFront(T** arr, const int m, int &n);
template <typename T> void EraseCol(T** arr, const int m, int &n, const int index);

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
	/*// 1) Создаем массив указателей.
	int** arr = new int* [m];
	// 2) Выделяем память под строки.
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n] {};
	}*/
	//int** arr = Allocate<int>(m, n);
	//double** arr = Allocate<double>(m, n);
	//char** arr = Allocate<char>(m, n);
	typedef int DataType;
	DataType** arr = Allocate<DataType>(m, n);
	cout << "Memory allocated" << endl;
	FillRand(arr, m, n);
	Print(arr, m, n);
	
	/*cout << "Memory allocated" << endl;
	FillRand(arr, m, n);*/
	// Обращение к элементам массива.
	/*for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}*/
	//Print(arr, m, n);
	/*cout << "Добавляем строку в конец массива: " << endl;
	arr = PushRowBack(arr, m, n);
	Print(arr, m, n);
	cout << "Добавляем строку в начало массива: " << endl;
	arr = PushRowFront(arr, m, n);
	Print(arr, m, n);
	cout << "Добавляем столбец в конец массива: " << endl;
	PushColBack(arr, m, n);
	cout << "Добавляем строку по индексу " << (m - 2 > 0 ? m - 2 : m) << ":\n";
	arr = InsertRow(arr, m, n, m - 2 > 0 ? m - 2 : m);
	Print(arr, m, n);
	cout << "Удаляем последнюю строку массива: " << endl;
	arr = PopRowBack(arr, m, n);
	Print(arr, m, n);
	cout << "Удаляем нулевую строку массива: " << endl;
	arr = PopRowFront(arr, m, n);
	Print(arr, m, n);
	cout << "Удаляем строку массива по индексу " << (m - 2 > 0 ? m - 2 : m - 1) << ":\n";
	arr = EraseRow(arr, m, n, m - 2 > 0 ? m - 2 : m - 1);*/
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
	
	// Удаление массива.
	// 1) Удаляем строки массива.
	/*for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	// 2) Удаляем массив указателей.
	delete[] arr;*/
	Clear(arr, m);

#endif
}

template <typename T> T** Allocate(const int m, const int n)
{
	T** arr = new T* [m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new T[n] {};
	}
	return arr;
}

template <typename T> void Clear(T** arr, const int m)
{
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

template <typename T> void Random(T & value)
{
	//cout << typeid(value).name() << endl;
	if (typeid(value) == typeid(float) || typeid(value) == typeid(double))
		value = double(rand() % 10000) / 100;
	else if (typeid(value) == typeid(char))
		value = (char)rand();
	else
		value = rand() % 100;
}

template <typename T> void FillRand(T* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		//*(arr + i) = rand() % 100;
		Random(arr[i]);
	}
}
template <typename T> void FillRand(T** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//arr[i][j] = rand() % 100;
			Random(arr[i][j]);
		}
	}
}
template <typename T> void Print(T* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
template <typename T> void Print(T** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

template <typename T> void PushBack(T** arr, int* n, T value)
{
	T* temp = new T[*n + 1];
	for (int i = 0; i < *n; i++)
	{
		temp[i] = (*arr)[i];
	}
	temp[*n] = value;
	++(*n);
	delete[] * arr;
	*arr = temp;
}
template <typename T> void PushFront(T** arr, int* n, T value)
{
	T* temp = new T[*n + 1];
	temp[0] = value;
	for (int i = 1; i < *n + 1; i++)
	{
		temp[i] = (*arr)[i - 1];
	}
	++(*n);
	delete[] * arr;
	*arr = temp;
}
template <typename T> void Insert(T** arr, int* n, T value, int index)
{
	//if (index >= 0 && index < *n)
	//{
		if (index >= *n)return;
		T* temp = new T[*n + 1];
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
template <typename T> void PopBack(T** arr, int* n)
{
	T* temp = new T[*n - 1];
	for (int i = 0; i < *n - 1; i++)
	{
		temp[i] = (*arr)[i];
	}
	--(*n);
	delete[] * arr;
	*arr = temp;
}
template <typename T> void PopFront(T** arr, int* n)
{
	T* temp = new T[*n - 1];
	for (int i = 0; i < *n - 1; i++)
	{
		temp[i] = (*arr)[i + 1];
	}
	--(*n);
	delete[] * arr;
	*arr = temp;
}
template <typename T> void Erase(T** arr, int* n, int index)
{
	if (index >= 0 && index < *n)
	{
		T* temp = new T[*n - 1];
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
template <typename T> void PushColBack(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		// 1) Создаем буферную строку.
		T* buffer = new T[n + 1]{};
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
template <typename T> T** PushRowBack(T** arr, int &m, const int n)
{
	// 1) Создаем буферный массив.
	T** temp = new T* [m + 1];
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
template <typename T> T** PushRowFront(T** arr, int& m, const int n)
{
	// 1) Создаем буферный массив указателей нужного размера.
	T** buffer = new T* [m + 1];
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


// Домашнее задание
template <typename T> T** InsertRow(T** arr, int& m, const int n, const int index)
{
	T** buffer = new T* [m + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[index] = new T[n] {};
	for (int i = index + 1; i < m + 1; i++)
	{
		buffer[i] = arr[i - 1];
	}
	delete[] arr;
	m++;
	return buffer;
}

template <typename T> T** PopRowBack(T** arr, int& m, const int n)
{
	T** buffer = new T* [m - 1];
	for (int i = 0; i < m - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	m--;
	return buffer;
}

template <typename T> T** PopRowFront(T** arr, int& m, const int n)
{
	T** buffer = new T* [m - 1];
	for (int i = 1; i < m; i++)
	{
		buffer[i - 1] = arr[i];
	}
	delete[] arr;
	m--;
	return buffer;
}

template <typename T> T** EraseRow(T** arr, int& m, const int n, const int index)
{
	T** buffer = new T* [m - 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index + 1; i < m; i++)
	{
		buffer[i - 1] = arr[i];
	}
	delete[] arr;
	m--;
	return buffer;
}

template <typename T> void PushColFront(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n + 1]{};
		for (int j = 1; j < n + 1; j++)
		{
			buffer[j] = arr[i][j - 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}

template <typename T> void InsertCol(T** arr, const int m, int& n, const int index)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n + 1]{};
		for (int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = index; j < n; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}

template <typename T> void PopColBack(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n - 1]{};
		for (int j = 0; j < n - 1; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n--;
}

template <typename T> void PopColFront(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n - 1]{};
		for (int j = 1; j < n; j++)
		{
			buffer[j - 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n--;
}

template <typename T> void EraseCol(T** arr, const int m, int& n, const int index)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n - 1]{};
		for (int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = index + 1; j < n; j++)
		{
			buffer[j - 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n--;
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