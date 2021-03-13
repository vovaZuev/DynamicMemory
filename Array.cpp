#include <iostream>
using std::cin;
using std::cout;
using std::endl;

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
template <typename T> T** PushRowBack(T** arr, int& m, const int n)
{
	// 1) Создаем буферный массив.
	T** temp = new T * [m + 1];
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
	T** buffer = new T * [m + 1];
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
template <typename T> T** InsertRow(T** arr, int& m, const int n, const int index)
{
	T** buffer = new T * [m + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[index] = new T[n]{};
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
	T** buffer = new T * [m - 1];
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
	T** buffer = new T * [m - 1];
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
	T** buffer = new T * [m - 1];
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
