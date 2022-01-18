#include<iostream>
using namespace std;
#include<array>
#include<vector>

#define tab "\t"
//#define STL_ARRAY
#define VECTOR
//#define VECTOR_HW

void PrintVector(vector<int> vec);
template<typename T> void print(const vector<T>& vec)
{
	for (typename vector<T>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}

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
	
	//vector<vector<int> >vec2;
	//cout << "Size:  " << vec2.size() << endl;
	//cout << "Capacity:  " << vec2.capacity() << endl;//есть только у вектора
	//cout << "MaxSize:  " << vec2.max_size() << endl;
	//cout << sizeof(vec2) << endl;

	int index;
	int value;
	int count;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите количество добавлений: "; cin >> count;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	
	if (index < vec.size())vec.insert(vec.begin() + index,count, value);
	else cout << "Error: out of range " << endl;
	print(vec);

	std::vector<int>powers = { 1024,2048,4096,8192,16384 };

	vec.insert(vec.begin() +4 , powers.begin(), powers.end());
	for (int i : vec) cout << i << tab; cout << endl;

	vec.insert(vec.begin() + 8, { 256,384,512,768 });
	for (int i : vec) cout << i << tab; cout << endl;

	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	cout << "Введите количество удалений: "; cin >> count;
	vec.erase(vec.begin() + index, vec.begin() + index+count);
	print(vec);
	cout << "\n----------------------------------------------------------\n";
	vec.swap(powers);
	print(vec);
	print(powers);

#endif // VECTOR
#ifdef VECTOR_HW
	vector<int> vec = { 0,1,1,2,3,5,8,13,21,34,55,89,144,232 };
	cout << "Size:  " << vec.size() << endl;
	cout << "Capacity:  " << vec.capacity() << endl;//есть только у вектора
	cout << "MaxSize:  " << vec.max_size() << endl;
	cout << sizeof(vec) << endl;
	int* data = vec.data();
	vector<int>::iterator i_iterator = vec.begin();
	PrintVector(vec);
	int value;
	int index;
	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите позицию: "; cin >> index;
	if (index > vec.size())return;
	//вставка заданного элемента в заданную позицию
	vec.insert(vec.begin() + index, value);
	cout << "Вектор с добавленным значением: " << endl;
	PrintVector(vec);
	cout << "Введите позицию для удаления: "; cin >> index;
	if (index > vec.size())return;
	//удаление заданного элемента по заданной позиции
	i_iterator = vec.end();
	vec.erase(vec.begin() + index);
	cout << "Вектор с удаленным значением: " << endl;
	PrintVector(vec);

#endif // VECTOR_HW
}

void PrintVector(vector<int> vec)
{
	for (vector<int>::iterator i_iterator = vec.begin(); i_iterator != vec.end(); i_iterator++)

	{
		cout << *(i_iterator) << '\t';
	}
	cout << endl;
}