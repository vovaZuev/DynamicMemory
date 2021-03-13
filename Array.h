#pragma once
template <typename T> void PushBack(T** arr, int* n, int value);
template <typename T> void PushFront(T** arr, int* n, int value);
template <typename T> void Insert(T** arr, int* n, int value, int index);
template <typename T> void PopBack(T** arr, int* n);
template <typename T> void PopFront(T** arr, int* n);
template <typename T> void Erase(T** arr, int* n, int index);
template <typename T> void PushColBack(T** arr, const int m, int& n);
template <typename T> T** PushRowBack(T** arr, int& m, const int n);
template <typename T> T** PushRowFront(T** arr, int& m, const int n);
template <typename T> T** InsertRow(T** arr, int& m, const int n, const int index);
template <typename T> T** PopRowBack(T** arr, int& m, const int n);
template <typename T> T** PopRowFront(T** arr, int& m, const int n);
template <typename T> T** EraseRow(T** arr, int& m, const int n, const int index);
template <typename T> void PushColFront(T** arr, const int m, int& n);
template <typename T> void InsertCol(T** arr, const int m, int& n, const int index);
template <typename T> void PopColBack(T** arr, const int m, int& n);
template <typename T> void PopColFront(T** arr, const int m, int& n);
template <typename T> void EraseCol(T** arr, const int m, int& n, const int index);