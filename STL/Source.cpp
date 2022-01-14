#include<iostream>
using namespace std;
#include<array>
#include<vector>

#define tab "\t"
//#define STL_ARRAY
#define VECTOR

void main()
{
	setlocale(LC_ALL, " ");
#ifdef STL_ARRAY
	array<int, 5>arr = { 5,5,8,13,21 };
	for (int i = 0; i < arr. size(); i++)
	{
		cout << arr[i]<< tab;
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


}