#include<iostream>
using namespace std;
#include<array>
#include<vector>

#define tab "\t"
//#define STL_ARRAY
//#define VECTOR
#define VECTOR_HW

void PrintVector(vector<int> vec, vector<int>::iterator i_iterator);

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef STL_ARRAY
	array<int, 5>arr = { 5,5,8,13,21 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
#endif // STL_ARRAY

#ifdef VECTOR
	vector<int> vec = { 0,1,1,2,3,5,8,13,21,34,55,89,144,232 };
	cout << "Size:  " << vec.size() << endl;
	cout << "Capacity:  " << vec.capacity() << endl;//есть только у вектора
	cout << "MaxSize:  " << vec.max_size() << endl;
	cout << sizeof(vec) << endl;
	int* data = vec.data();
	vec.push_back(55);
	try
	{
		for (int i = 0; i < vec.capacity(); i++)
		{
			//cout << vec[i] << tab;
			cout << vec.at(i) << tab;
		}
		cout << endl;
		//subscript - индексирование
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	cout << "Size:  " << vec.size() << endl;
	cout << "Capacity:  " << vec.capacity() << endl;//есть только у вектора
	cout << "MaxSize:  " << vec.max_size() << endl;
	cout << sizeof(vec) << endl;


	vector<vector<int> >vec2;
	cout << "Size:  " << vec2.size() << endl;
	cout << "Capacity:  " << vec2.capacity() << endl;//есть только у вектора
	cout << "MaxSize:  " << vec2.max_size() << endl;
	cout << sizeof(vec2) << endl;
#endif // VECTOR
#ifdef VECTOR_HW
	vector<int> vec = { 0,1,1,2,3,5,8,13,21,34,55,89,144,232 };
	cout << "Size:  " << vec.size() << endl;
	cout << "Capacity:  " << vec.capacity() << endl;//есть только у вектора
	cout << "MaxSize:  " << vec.max_size() << endl;
	cout << sizeof(vec) << endl;
	int* data = vec.data();
	vector<int>::iterator i_iterator;
	for (i_iterator = vec.begin();
		i_iterator != vec.end(); i_iterator++)
	{
		cout << *(i_iterator) << '\t';
	}
	cout << endl;
	int value;
	int index;
	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите позицию: "; cin >> index;
	if (index > vec.size())return;
	//вставка заданного элемента в заданную позицию
	vec.insert(i_iterator - vec.size() + index, value);
	cout << "Вектор с добавленным значением: " << endl;
	for (i_iterator = vec.begin(); i_iterator != vec.end(); i_iterator++)

	{
		cout << *(i_iterator) << '\t';
	}
	cout << endl;
	cout << "Введите позицию для удаления: "; cin >> index;
	if (index > vec.size())return;
	//удаление заданного элемента по заданной позиции
	vec.erase(i_iterator - vec.size() + index);
	cout << "Вектор с удаленным значением: " << endl;
	PrintVector(vec, i_iterator);

#endif // VECTOR_HW
}

void PrintVector(vector<int> vec, vector<int>::iterator i_iterator)
{
	for (i_iterator = vec.begin(); i_iterator != vec.end(); i_iterator++)

	{
		cout << *(i_iterator) << '\t';
	}
	cout << endl;
}