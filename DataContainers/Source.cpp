#include<iostream>
using namespace std;

#define tab "\t"

class Element
{
	int Data;//Значение элемента
	Element* pNext;//Адрес следующего элемента
	public:

		Element(int Data, Element* pNext = nullptr) : Data(Data), pNext(pNext)
		{
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t" << this << endl;
		}
		friend class ForwardList;

};
class ForwardList
{
	Element* Head;//Указывает на начальный элемент.Является точкой входа в список
public:
	ForwardList()
	{
		this->Head = nullptr;//Если голова указывает на 0, значит список пуст
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}

	//Adding elements
	void push_front(int Data)
	{
		//1)Создаем элемент
		Element* New = new Element(Data);
		//2)Присоединяем новый элемент к списку
		New->pNext = Head;
		//3)Переносим голову на новый элемент
		Head = New;

	}
	void print()const
	{
		Element* Temp = Head;//Temp-итератор,с пом кот можно получить доступ 
		//к элементам структуры данных
		while (Temp != nullptr)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext<< endl;
			Temp = Temp->pNext;//Переход на след элемент
		}
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n;//Размер списка
	cout << "Ведите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	list.print();
}
