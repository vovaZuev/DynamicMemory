#include <cstdlib>

template <typename T> void Random(T& value)
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
		Random(arr[i]);
	}
}
template <typename T> void FillRand(T** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Random(arr[i][j]);
		}
	}
}
