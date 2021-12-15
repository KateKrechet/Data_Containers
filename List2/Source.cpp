#include<iostream>
using namespace std;

#define tab "\t"

class Element

{
	int Data;
	Element* pNext;
	Element* pPrev;
	static int count;

public:

	Element(int Data, Element* pPrev = nullptr, Element* pNext = nullptr) :Data(Data), pPrev(pPrev), pNext(pNext)
	{
		count++;
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		count--;
		cout << "EDestructor:\t" << this << endl;
	}
	friend class List2;
};
int Element::count = 0;

class List2
{
	Element* Head;
	Element* Tail;
	size_t size;
public:

	List2()
	{
		this->Head = nullptr;
		this->Tail = nullptr;
		cout << "LConstructor:\t" << this << endl;
	}
	~List2()
	{
		cout << "LDestructor:\t" << this << endl;
	}

	//Operators

	//Adding elements
	void push_front(int Data)
	{
		if (Head != nullptr)
		{
			//1)Создаем элемент
			Element* New = new Element(Data, Head);
			//2)Присоединяем новый элемент к списку
			New->pNext = Head;
			//3)Переносим голову на новый элемент
			Head = New;
			//Head = new Element(Data, Head);
			//4)Предыдущего элемента нет
			New->pPrev = nullptr;
		}
		else Head = Tail = new Element(Data, Head);

		size++;

	}


	void print()const
	{
		for (Element* Temp = Head; Temp; Temp->pNext)
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << endl;
		/*for (Element* Temp = Tail; Temp; Temp->pPrev)
			cout << Temp << tab << Temp->Data << tab << Temp->pPrev << endl;
		cout << endl;*/
		cout << "Количество элементов в списке: " << size << endl;
		cout << "Общее количество элементов в списке: " << Head->count << endl;

	}
};

void main()
{
	setlocale(LC_ALL, "");
	List2 list1;
	list1.push_front(3);
	/*list1.push_front(5);
	list1.push_front(8);
	list1.push_front(13);
	list1.push_front(21);*/

	list1.print();
}