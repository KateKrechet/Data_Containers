//Search BinaryTree
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

class Tree
{
protected:
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr)
			:Data(Data), pLeft(pLeft), pRight(pRight)
		{
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestrcutor:\t" << this << endl;
		}
		bool is_leaf()const
		{
			return pLeft == pRight;
		}
		friend class Tree;
		friend class UniqueTree;
	}*Root;	//������ ������
public:
	Element* getRoot()const
	{
		return Root;
	}
	Tree()
	{
		Root = nullptr;
		cout << "TConstructor:\t" << this << endl;
	}
	Tree(const std::initializer_list<int>& il) :Tree()
	{
		for (int i : il)insert(i, Root);
	}
	Tree(const Tree& other)
	{
		*this = other;
		cout << "TCopyConstructor: " << this << endl;
	}

	~Tree()
	{
		Clear(Root);
		Root = nullptr;
		cout << "TDestructor:\t" << this << endl;
		cout << "\n---------------------------------\n";
	}

	Tree& operator=(const Tree& other)
	{
		if (this == &other) return *this;
		this->Clear();
		Element* Root = other.Root;
		CopyFunction(Root);
		cout << "TCopyAssignment:\t" << this << endl;

	}

	void CopyFunction(Element* Root)
	{
		if (Root == nullptr) return;
		this->insert(Root->Data);
		CopyFunction(Root->pLeft);
		CopyFunction(Root->pRight);
	}

	void insert(int Data)
	{
		insert(Data, this->Root);
	}
	
	void erase(int Data)
	{
		erase(Data, Root);
	}
	int minValue()const
	{
		return minValue(this->Root);
	}
	int maxValue()const
	{
		return maxValue(this->Root);
	}
	int Count()const
	{
		return Count(Root);
	}
	int Sum()const
	{
		return Sum(Root);
	}
	double Avg()const
	{
		return (double)Sum(Root) / Count(Root);
	}
	void Clear()
	{
		Clear(Root);
		Root = nullptr;
	}
	int depth()const
	{
		return depth(this->Root);
	}
	void print()const
	{
		print(this->Root);
		cout << endl;
	}
	void print(int depth)const
	{

		print(this->Root,depth);
		cout << endl;
	}
	void tree_print()
	{

		tree_print(0);
		cout << endl;
	}
private:

	void insert(int Data, Element* Root)
	{
		//Root - ������ ���������
		//this->Root - ������ ����� ������
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)//���� ���� ����� ��� ���������� ��������,
				Root->pLeft = new Element(Data);//��������� ������� ����� ����.
			else//� ��������� ������
				insert(Data, Root->pLeft);	//���� ������, � ���� �����, 
											//���� �������� �������.
		}
		else
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
	void erase(int Data, Element*& Root)
	{
		if (Root == nullptr) return;
		erase(Data, Root->pLeft);
		erase(Data, Root->pRight);
		if (Data == Root->Data)
		{
			if (Root->is_leaf())//������� ��������� �������
			{
				//�� ��� ����� �������
				delete Root;
				Root = nullptr;
			}
			else
			{
				if (Count(Root->pLeft) > Count(Root->pRight))//���� � ����� ����� ������ ��-�, ��� � ������ �����
				{
					Root->Data = maxValue(Root->pLeft);// �� �������� �������� ���� ��-�� ���� ��-� � ����� �����
					erase(maxValue(Root->pLeft), Root->pLeft);
				}
				else//� ��������� ������
				{
					Root->Data = minValue(Root->pRight);//�������� �������� ���������� ������� ����������� ��������� � ������ �����
					erase(minValue(Root->pRight), Root->pRight);
				}
			}
		}
		
	}

	int minValue(Element* Root)const
	{
		if (Root->pLeft == nullptr)return Root->Data;
		return minValue(Root->pLeft);
	}
	int maxValue(Element* Root)const
	{
		/*if (Root->pRight == nullptr)return Root->Data;
		else return maxValue(Root->pRight);*/

		//return Root->pRight == nullptr ? Root->Data : maxValue(Root->pRight);
		return Root->pRight ? maxValue(Root->pRight) : Root->Data;
	}

	int Count(Element* Root)const
	{
		/*if (Root == nullptr)return 0;
		else return Count(Root->pLeft) + Count(Root->pRight) + 1;*/
		//return Root ? Count(Root->pLeft) + Count(Root->pRight) + 1 : 0;
		return !Root ? 0 : Count(Root->pLeft) + Count(Root->pRight) + 1;
	}
	int Sum(Element* Root)const
	{
		return Root ? Sum(Root->pLeft) + Sum(Root->pRight) + Root->Data : 0;
	}

	void Clear(Element* Root)
	{
		if (Root == nullptr)return;
		Clear(Root->pLeft);
		Clear(Root->pRight);
		delete Root;
	}


	int depth(Element* Root)const
	{
		if (Root == nullptr)return 0;
		else return
			depth(Root->pLeft) + 1 > depth(Root->pRight) + 1 ?
			depth(Root->pLeft) + 1 : depth(Root->pRight) + 1;
	}

	void print(Element* Root)const
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << tab;
		print(Root->pRight);
	}

	void print(Element* Root, int depth)const
	{
		if (Root == nullptr || depth == -1)return;
		
		if (depth == 1 && Root->pLeft == nullptr)cout << " " << tab;
		print(Root->pLeft, depth - 1);
		
		if (depth == 0) cout << Root->Data /*<< tab*/;
		int min_distance = 4;
		cout.width(min_distance * (this->depth() - depth));
		if (depth == 1 && Root->pRight == nullptr)cout << " " << tab;
		print(Root->pRight, depth - 1);
		//cout << tab;
	}
	void tree_print(int depth)
	{
		if (depth==this->depth())return;
		int min_distance =4;
		cout.width(min_distance * (this->depth() - depth));
		//for (int i = 0; i < (this->depth() - depth)*2; i++)	cout << tab;//����� ��������� ��������� ��� 0 �������
		print(depth);
		//for (int i = 0; i < (this->depth() - depth)*4; i++)	cout << tab;
		cout << endl;
		tree_print(depth + 1);
	}
};

class UniqueTree : public Tree
{
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)//���� ���� ����� ��� ���������� ��������,
				Root->pLeft = new Element(Data);//��������� ������� ����� ����.
			else//� ��������� ������
				insert(Data, Root->pLeft);	//���� ������, � ���� �����, 
											//���� �������� �������.
		}
		else if (Data > Root->Data)
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
public:
	void insert(int Data)
	{
		insert(Data, Root);
	}
};
//#define BASE_CHECK
//#define ERASE_METHODS
#define COPY_METHODS
void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	int n;
	cout << "������� ���������� ���������: "; cin >> n;
	Tree tree;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);
	}
	tree.print();
	cout << endl;
	cout << "����������� �������� � ������:  " << tree.minValue() << endl;
	cout << "������������ �������� � ������: " << tree.maxValue() << endl;
	cout << "���������� ��������� � ������:  " << tree.Count() << endl;
	cout << "����� ��������� ������:  " << tree.Sum() << endl;
	cout << "������� �������������� ��������� ������: " << tree.Avg() << endl;

	UniqueTree u_tree;
	for (int i = 0; i < n; i++)
	{
		u_tree.insert(rand() % 100);
	}
	u_tree.print();
	cout << endl;
	cout << "����������� �������� � ������:  " << u_tree.minValue() << endl;
	cout << "������������ �������� � ������: " << u_tree.maxValue() << endl;
	cout << "���������� ��������� � ������:  " << u_tree.Count() << endl;
	cout << "����� ��������� ������:  " << u_tree.Sum() << endl;
	cout << "������� �������������� ��������� ������: " << u_tree.Avg() << endl;

	u_tree.Clear();
	u_tree.print();
#endif // BASE_CHECK
#ifdef ERASE_METHODS
	Tree tree = { 50, 25, 75, 16, 32, 64, 80, 8, 11, 48, 77, 85 };
	tree.print();
	int value;
	cout << "������� ��������� �������� "; cin >> value;
	tree.erase(value);
	tree.print();
#endif // ERASE_METHODS

#ifdef COPY_METHODS
	Tree tree = { 50, 25, 75, 16, 32, 64, 80, 8, 18, 48, 77, 85 };
	tree.print();

	Tree tree2;
	tree2 = tree;
	tree2.print();//CopyAssignment

	Tree tree3 = tree;
	tree3.print();//CopyConstructor

#endif // COPY_METHODS
	/*Tree tree = { 50, 25, 75, 16, 32, 64, 80, 8, 18, 48, 77, 85 };
	tree.print();
	cout << "������� ������: " << tree.depth()<<endl;
	//tree.print(3);
	tree.tree_print();*/
}