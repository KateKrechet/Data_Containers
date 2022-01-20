#include<iostream>
using namespace std;
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<forward_list>

#define tab "\t"
//#define STL_ARRAY
//#define VECTOR
//#define VECTOR_HW
//#define STL_DEQUE
//#define STL_LIST
#define FORWARD_LIST

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

	if (index < vec.size())vec.insert(vec.begin() + index, count, value);
	else cout << "Error: out of range " << endl;
	print(vec);

	std::vector<int>powers = { 1024,2048,4096,8192,16384 };

	vec.insert(vec.begin() + 4, powers.begin(), powers.end());
	for (int i : vec) cout << i << tab; cout << endl;

	vec.insert(vec.begin() + 8, { 256,384,512,768 });
	for (int i : vec) cout << i << tab; cout << endl;

	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	cout << "Введите количество удалений: "; cin >> count;
	vec.erase(vec.begin() + index, vec.begin() + index + count);
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

#ifdef STL_DEQUE
	//deque(Double-ended queue - двунаправленная очередь - это контейнер
	//который хранит данные в виде списка динамических массивов(векторов)
	//что увеличивает производительность при добавлении/удалении элементов
	//но немного снижает производительность при доступе к элементам
	//В отличие от вектора deque позволяет добавлять элементы не только с конца, но и с начала очереди
	std::deque<int> deque = { 3,5,8,13,21 };
	deque.push_back(34);
	deque.push_back(55);
	deque.push_back(89);
	deque.push_front(2);
	deque.push_front(1);
	deque.push_front(1);
	deque.push_front(0);
	for (int i = 0; i < deque.size(); i++)
	{
		cout << deque[i] << tab;
	}
	cout << endl;

	std::deque<int> d_powers = { 256,512,768 };
	//deque.push_back(std::move(d_powers.begin()+ 1));
	for (int i : deque) cout << i << tab; cout << endl;
	for (int i : d_powers) cout << i << tab; cout << endl;

#endif // !STL_DEQUE

#ifdef STL_LIST

	std::list<int> cont_list = { 3,5,8,13,21,34,55,89,144,233 };
	for (int i : cont_list) cout << i << tab; cout << endl;

	int index;
	int value;
	int count;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите количество добавлений: "; cin >> count;
	cout << "Введите значение добавляемого элемента: "; cin >> value;

	list<int>::iterator it = cont_list.begin();
	if (index < int(cont_list.size()))
	{
		advance(it, index);
		cont_list.insert(it, count, value);
	}
	else cout << "Error: out of range " << endl;
	for (int i : cont_list) cout << i << tab; cout << endl;

	do
	{
		cout << "Введите индекс удаляемого элемента: "; cin >> index;
	} while (index >= cont_list.size());

	list<int>::iterator it1 = cont_list.begin();
	advance(it1, index);
	cont_list.erase(it1);
	for (int i : cont_list) cout << i << tab; cout << endl;

	int first_index;
	int last_index;
	cout << "Введите индекс начала удаления: "; cin >> first_index;
	cout << "Введите индекс конца удаления: "; cin >> last_index;
	list<int>::iterator it2 = cont_list.begin();
	list<int>::iterator it3 = cont_list.begin();
	advance(it2, first_index);
	advance(it3, last_index + 1);

	if (first_index < cont_list.size() && last_index < cont_list.size())cont_list.erase(it2, it3);
	else cout << "Error: out of range " << endl;
	for (int i : cont_list) cout << i << tab; cout << endl;

#endif // STL_LIST
#ifdef FORWARD_LIST
	std::forward_list<int>list = { 3,5,8,13,21 };
	list.push_front(123);
	/*std::forward_list<int>::iterator it = list.begin();
	list.insert_after(list.end(), 1024);*/
	for (std::forward_list<int>::iterator it = list.begin(); it != list.end(); it++)
	{
		cout << *it<<tab;
	}
	cout << endl;
	list.reverse();
	list.push_front(1024);
	list.reverse();
	for (int i : list)cout << i << tab; cout << endl;

	std::list<int> list2;
	cout << "ForwardList max size: \t" << list.max_size() << endl;
	cout << "ForwardList max size: \t" << list2.max_size() << endl;
#endif // FORWARD_LIST


}

void PrintVector(vector<int> vec)
{
	for (vector<int>::iterator i_iterator = vec.begin(); i_iterator != vec.end(); i_iterator++)

	{
		cout << *(i_iterator) << '\t';
	}
	cout << endl;
}
