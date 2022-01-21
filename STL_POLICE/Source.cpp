#include<iostream>
#include<map>
#include<string>
#include<list>
#include<windows.h>
using std::cin;
using std::cout;
using std::endl;

const std::map<int, std::string>& crimes =
{
	std::pair<int,std::string>(1,"превышение скорости"),
	std::pair<int,std::string>(2,"проезд на красный"),
	std::pair<int,std::string>(3,"парковка в неположенном месте"),
	std::pair<int,std::string>(4,"оскорбление офицера"),
	std::pair<int,std::string>(5,"пересечение сплошной линии"),
};

class Crime
{
	int crime_id;
	std::string place;
public:
	int get_crime()const
	{
		return crime_id;
	}
	const std::string& get_place()const
	{
		return place;
	}
	Crime()
	{

	}
	Crime(int crime_id, const std::string& place)
	{
		this->crime_id = crime_id;
		this->place = place;
	}
	~Crime()
	{

	}
	std::ostream& print(std::ostream& os)const
	{
		return os << crimes.at(crime_id) << " , " << place;
	}
	std::istream& scan(std::istream& is)
	{
		is.ignore();//игнорирует 1 символ из буфера ввода(в данном случае '\n')
		cin >> crime_id;
		std::getline(is, place, '.');
		return is;
	}
};
std::ostream& operator<<(std::ostream& os, const Crime& obj)
{
	return obj.print(os);
}
std::istream& operator >> (std::istream& is, Crime& obj)
{
	return obj.scan(is);
}
void print(const std::map<std::string, std::list<Crime>>& base);


void main()
{
	//setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::map<std::string, std::list<Crime>>base =
	{
		std::pair<std::string,std::list<Crime>>("m777ko",std::list<Crime>{Crime(1,"ул.Ленина"),Crime(2,"ул.Октябрьская")}),
		std::pair<std::string,std::list<Crime>>("b510ma",std::list<Crime>{Crime(3,"ТЦ Экватор")}),
		std::pair<std::string,std::list<Crime>>("a213bb",std::list<Crime>{Crime(4,"Красная площадь")}),
	};
	std::string licence_plate;
	Crime crime;
	cout << "Введите номер автомобиля: "; cin >> licence_plate;
	cout << "Введите правонарушение: "; cin >> crime;
	base[licence_plate].push_back(crime);
	print(base);
	/*for (std::list<Crime>::iterator it = base["m777ko"].begin(); it != base["m777ko"].end(); ++it)
	{
		cout << *it<< endl;
	}*/
}
void print(const std::map<std::string, std::list<Crime>>& base)
{
	for (std::map<std::string, std::list<Crime>>::const_iterator it = base.begin(); it != base.end(); ++it)
	{
		cout << it->first << ":\n";
		for (std::list<Crime>::const_iterator l_it = it->second.begin(); l_it != it->second.end(); ++l_it)
		{
			cout << *l_it << endl;
		}
	}
}