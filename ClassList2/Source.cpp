﻿#include<iostream>
using namespace std;

#define tab "\t"

class List
{
	class Element
	{
		int Data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr)
			:Data(Data), pNext(pNext), pPrev(pPrev)
		{
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t" << this << endl;
		}
		friend class List;
	}*Head,*Tail;//Объявляем 2 казателя сразу же после описания класса
	             //эти указатели будут переменными членами класса List
	size_t size;//Размер списка
public:
	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp) :Temp(Temp)
		{
			cout << "IConstructor:\t" << this << endl;
		}
		~Iterator()
		{
			cout << "IDestructor:\t" << this << endl;
		}
		Iterator& operator++()
		{
			Temp = Temp->pNext;
			return *this;
		}
		Iterator operator++(int)
		{
			Iterator old = *this;
			Temp = Temp->pNext;
			return old;
		}
		Iterator& operator--()
		{
			Temp = Temp->pPrev;
			return *this;
		}
		Iterator& operator--(int)
		{
			Iterator old = *this;
			Temp = Temp->pPrev;
			return old;;
		}
		bool operator==(const Iterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const Iterator& other)const
		{
			return this->Temp != other.Temp;
		}
		const int& operator*()const
		{
			return Temp->Data;
		}
		int& operator*()
		{
			return Temp->Data;
		}

	};
	class ReverseIterator
	{
		Element* Temp;
	public:
		ReverseIterator(Element* Temp) :Temp(Temp)
		{
			cout << "RIConstructor:\t" << this << endl;
		}
		~ReverseIterator()
		{
			cout << "RIDestructor:\t" << this << endl;
		}
		ReverseIterator& operator++()
		{
			Temp = Temp->pPrev;
			return *this;
		}
		ReverseIterator operator++(int)
		{
			ReverseIterator old = *this;
			Temp = Temp->pPrev;
			return old;//возвращает старое значение
		}
		ReverseIterator& operator--()
		{
			Temp = Temp->pNext;
			return *this;
		}
		ReverseIterator operator--(int)
		{
			ReverseIterator old = *this;
			Temp = Temp->pNext;
			return old;
		}
		bool operator==(const ReverseIterator& other)
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const ReverseIterator& other)
		{
			return this->Temp != other.Temp;
		}
		const int& operator*()const
		{
			return Temp->Data;
		}
		int& operator*()
		{
			return Temp->Data;
		}

	};
	Iterator begin()
	{
		return Head;
	}
	Iterator end()
	{
		return nullptr;
	}
	ReverseIterator rbegin()
	{
		return Tail;
	}
	ReverseIterator rend()
	{
		return nullptr;
	}
	

	List()
	{
		Head = Tail = nullptr;//если список пуст, то голова и хвост указывают на 0
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	List(const std::initializer_list<int>& il) :List()
	{
		cout << typeid(il.begin()).name() << endl;
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}

	}
	List(const List& other)
	{
		/*for (Element* Temp = other.Head; Temp; Temp = Temp->pNext) this->push_back(Temp->Data);*/
		*this = other;//из КК вызываем оператор присваивания
		cout << "LCopyConstructor: " << this << endl;
		
	}
	~List()
	{
		while (Head) pop_front();
		cout << "LDestructor:\t" << this << endl;
		cout << "\n--------------------------------------------------------------\n";
	}
	//Operators
	List& operator=(const List& other)
	{
		if (this == &other) return *this;
		while (Head) pop_front();//затираем старые значения
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext) this->push_back(Temp->Data);
		cout << "LCopyAssignment: " << this << endl;
		return *this;
	}
	//Adding elements
	void push_front(int Data)
	{
		if (Head == nullptr && Tail==nullptr)
		{
			//когда в списке появляется первый элемент, он одновременно явяляется и головой, 
			//и хвостом
			Head = Tail = new Element(Data);
			size++;
			return;
		}
		Head = Head->pPrev = new Element(Data, Head);
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr && Tail == nullptr)return push_front(Data);
			Tail = Tail->pNext = new Element(Data, nullptr, Tail);
		size++;
	}
	void insert(int Data, int Index)
	{
		if (Index >=size)
		{
			cout << "Выход за пределы списка!" << endl;
			return;
		}
		Element* Temp;
		if (Index < size / 2)
		{
			Temp = Head;
			for (int i = 0; i < Index; i++) Temp = Temp->pNext;
		}
		else
		{
			Temp = Tail;
			for (int i = 0; i < size - Index - 1; i++)Temp = Temp->pPrev;
		}
		/*Element* New = new Element(Data);
		New->pNext = Temp;
		New->pPrev = Temp->pPrev;
		Temp->pPrev->pNext = New;
		Temp->pPrev = New;*/

		Temp->pPrev=Temp->pPrev ->pNext= new Element(Data,Temp, Temp->pPrev);//предшествующий для Temp   и следующий для ранее предшествующего=New,для которого Temp-след, а предшествующий - ранее предшествующий для Temp
		size++;
	}
	
	//Removing elements
	void pop_front()
	{
		if (Head == nullptr && Tail == nullptr)return;
		if (Head == Tail)
		{
			delete Head;
			Head = Tail = nullptr;
			size--;
			return;
		}
		Head = Head->pNext;
		delete Head->pPrev;
		Head->pPrev = nullptr;
		size--;

	}
	void pop_back()
	{
		if (Head==Tail) return pop_front();
		Tail = Tail->pPrev;
		delete Tail->pNext;
		Tail->pNext = nullptr;
		size--;
	}
	void erase(int Index)
	{
		//контрольные точки
		if (Index >=size)
		{
			cout << "Выход за пределы списка" << endl;
			return;
		}
		if (Index == 0) return pop_front();
		if (Index == size-1) return pop_back();
		Element* Temp;
		if (Index < size / 2)
		{
			Temp = Head;
			for (int i = 0; i < Index; i++) Temp = Temp->pNext;
		}
		else
		{
			Temp = Tail;
			for (int i = 0; i < size - Index - 1; i++)Temp = Temp->pPrev;
		}

		Element* Erased = Temp;
		Temp=Temp->pPrev;//становится предшествующим
		Temp->pNext = Temp->pNext->pNext;//следующий будет элемент через 1
		Temp->pNext->pPrev = Temp;//Temp становится предшествующим для ранее следующего
		delete Erased;
		size--;

	}
	//Methods
	void print()const
	{
		cout << "Head:\t" << Head << endl;
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << "Tail:\t" << Tail << endl;
		cout << "Количество элементов списка: " << size << endl;
	}
	void reverse_print()const
	{
		cout << "Tail:\t" << Tail << endl;
		for(Element*Temp=Tail;Temp;Temp=Temp->pPrev)
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << "Head:\t" << Head << endl;
		cout << "Количество элементов списка: " << size << endl;
	}
};
//#define BASE_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	int n;
	cout << "Введите размер списка: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list.print();
	list.reverse_print();
	cout << "\n-----------------------------------------------------------\n";
	/*list.pop_front();
	list.pop_back();*/
	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	list.erase(index);
	list.print();
	list.reverse_print();
#endif // BASE_CHECK

	List list= { 3,5,8,13,21 };
	/*list.print();

	List list1 = list;//CopyConstructor
	list1.print();

	List list2;
	list2 = list;
	list2.print();//CopyAssignment
	list2.print();*/

	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;
	
	for (List::ReverseIterator rit = list.rbegin(); rit != list.rend(); rit++)
	{
		cout << *rit << tab;
	}
	cout << endl;
	for (List::ReverseIterator rit = list.rbegin(); rit != list.rend(); ++rit)
	{
		cout << *rit << tab;
	}
	cout << endl;

}