#include<iostream>
using namespace std;

#define tab "\t"

class Element
{
	int Data;//Значение элемента
	Element* pNext;//Адрес следующего элемента
	static int count; //кол-во элементов
	public:

		Element(int Data, Element* pNext = nullptr) : Data(Data), pNext(pNext)
		{
			count++;
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			count--;
			cout << "EDestructor:\t" << this << endl;
		}
		friend class ForwardList;

};

int Element::count = 0;//Стат переменные могут быть проинициализированы только за классом
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

	void push_back(int Data)
	{
		if (Head == nullptr) return	push_front(Data);
		Element* Temp = Head;
		while (Temp->pNext) Temp = Temp->pNext;
		Temp->pNext = new Element(Data);
	}

	//Erasing elements

	void pop_front()
	{
		//1)Запоминаем адрем удаляемого элемента
		Element* Erased = Head;
		//2)Исключаем элемент из списка
		Head = Head->pNext;
		//3)Удаляем элемент из списка
		delete Erased;
	}
	void pop_back()
	{
		if (Head->pNext == nullptr) return pop_front();
		//1)Доходим до предпоследнего элемента
		Element* Temp = Head;
		while (Temp->pNext->pNext) Temp = Temp->pNext;
		//мы оказались в предпоследнем элементе
		//2)удаляем последний элемент из памяти
		delete Temp->pNext;
		//3)Забываем от удаленном элементе, то есть затираем его адрес нулем
		Temp->pNext = nullptr;
		//Теперь Temp явялется последним элементом списка
	}

	void insert(int Data, int Index)
	{
		if (Index > Head->count)
		{
			cout << "Выход за пределы списка" << endl;
			return;
		}
		if (Index == 0 || Head==nullptr)return push_front(Data);
		//0)Доходим до нужного элемента
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++) Temp = Temp->pNext;
		//1)Создаем новый элемент
		Element* New = new Element(Data);
		//Оcуществялем вставку нового элемента в список
		//2)Привязываем новый элемент к списку
		New->pNext = Temp->pNext;
		//3)Включаем элемент в список
		Temp->pNext = New;
	}

	void erase(int Index)
	{
		//контрольные точки
		if (Index > Head->count)
		{
			cout << "Выход за пределы списка" << endl;
			return;
		}
		if (Index == 0) return pop_front();
		if (Index == Head->count-1) return pop_back();
		
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++) Temp = Temp->pNext;
		delete Temp->pNext;
		Temp->pNext = Temp->pNext->pNext;
		
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
		cout << "Количество элементов списка: " << Head->count << endl;
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
		list.push_back(rand() % 100);
	}
	list.print();
	/*list.pop_back();
	list.print();*/
	int Index;
	int value;
	/*cout << "Введите индекс добавляемого элемента: "; cin >> Index;
	cout << "Введите значение добавляемого элмента: "; cin >> value;
	list.insert(value, Index);
	list.print();*/
	cout << "Введите индекс удаляемого элемента: "; cin >> Index;
	list.erase(Index);
	list.print();

}
