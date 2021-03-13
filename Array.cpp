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
		// 1) ������� �������� ������.
		T* buffer = new T[n + 1]{};
		// 2) �������� �������� ������ ������� � ��������.
		for (int j = 0; j < n; j++)
		{
			buffer[j] = arr[i][j];
		}
		// 3) ������� �������� ������.
		delete[] arr[i];
		// 4) ��������� ����� � ������� ���������� �� ����� ����� ������.
		arr[i] = buffer;
	}
	n++;
}
template <typename T> T** PushRowBack(T** arr, int& m, const int n)
{
	// 1) ������� �������� ������.
	T** temp = new T * [m + 1];
	// 2) �������� ������ ������������ ����� � ����� ������ ����������.
	for (int i = 0; i < m; i++)
		temp[i] = arr[i];
	/*for (int i = 0; i < m + 1; i++)
	{
		temp[i] = new int[n] {};
	}*/
	/*// 2) �������� �������� � �������� ������.
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp[i][j] = arr[i][j];
		}
	}*/
	// 3) ������� �������� ������ ����������.
	/*for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}*/
	delete[] arr;
	// 4) ������� ��������� ������ �������.
	temp[m] = new int[n] {};
	// 5) ����������� ���������� �����.
	++m;
	// 5) ���������� ����� ������ ������� �� ����� ������.
	return temp;
}
template <typename T> T** PushRowFront(T** arr, int& m, const int n)
{
	// 1) ������� �������� ������ ���������� ������� �������.
	T** buffer = new T * [m + 1];
	// 2) �������� ������ ����� � ����� ������.
	for (int i = 0; i < m; i++)
		buffer[i + 1] = arr[i];
	// 3) ������� �������� ������ ����������.
	delete[] arr;
	// 4) ������� ������� ������ �������.
	buffer[0] = new int[n] {};
	// 5) ����������� ���������� �����.
	m++;
	// 6) ���������� ����� ������.
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
