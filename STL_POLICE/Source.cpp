#include<iostream>
#include<conio.h>
#include<map>
#include<string>
#include<list>
#include<windows.h>
#include<fstream>
#include<iomanip>

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
	std::string& get_place()
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
	std::ofstream& print(std::ofstream& os)const
	{
		os << crime_id <</* " " <<*/place;
		return os;
	}
	std::istream& scan(std::istream& is)
	{
		is.ignore();//игнорирует 1 символ из буфера ввода(в данном случае '\n')
		cin >> crime_id;
		std::getline(is, place, '.');
		return is;
	}
	std::ifstream& scan(std::ifstream& is)
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
std::ofstream& operator<<(std::ofstream& os, const Crime& obj)
{
	return obj.print(os);
}
std::istream& operator >> (std::istream& is, Crime& obj)
{
	return obj.scan(is);
}
void print(const std::map<std::string, std::list<Crime>>& base);
void save(const std::map<std::string, std::list<Crime>>& base);
void load(std::map<std::string, std::list<Crime>>& base);

void main()
{
	//setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::map<std::string, std::list<Crime>>base /*=
	{
		std::pair<std::string,std::list<Crime>>("m777ko",std::list<Crime>{Crime(1,"ул.Ленина"),Crime(2,"ул.Октябрьская")}),
		std::pair<std::string,std::list<Crime>>("b510ma",std::list<Crime>{Crime(3,"ТЦ Экватор")}),
		std::pair<std::string,std::list<Crime>>("a213bb",std::list<Crime>{Crime(4,"Красная площадь")}),
	}*/;
	//load(base);
	/*std::string licence_plate;
	Crime crime;
	cout << "Введите номер автомобиля: "; cin >> licence_plate;
	cout << "Введите правонарушение: "; cin >> crime;
	base[licence_plate].push_back(crime);*/
	//print(base);
	//save(base);
	/*for (std::list<Crime>::iterator it = base["m777ko"].begin(); it != base["m777ko"].end(); ++it)
	{
		cout << *it<< endl;
	}*/

	int action;
	do 
	{
		system("CLS");
		cout << "Выберите действие: " << endl;
		cout << "1.Загрузить базу: " << endl;
		cout << "2.Сохранить базу: " << endl;
		cout << "3.Вывести базу: " << endl;
		cout << "4.Добавить базу: " << endl;
		action = _getch();
		switch (action)
		{
		case '1':load(base); break;
		case '2':save(base); break;
		case '3':print(base); break;
		case '4':
		{
			std::string licence_plate;
			Crime crime;
			cout << "Введите номер автомобиля: "; cin >> licence_plate;
			cout << "Введите правонарушение: "; cin >> crime;
			base[licence_plate].push_back(crime);
		} 
		break;
		}
		//_getch();
		system("PAUSE");
	} while (action != 27);
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
void save(const std::map<std::string, std::list<Crime>>& base)
{
	std::ofstream fout("base.txt");
	for (std::map<std::string, std::list<Crime>>::const_iterator it = base.begin(); it != base.end(); ++it)
	{
		fout << it->first << ":";
		for (std::list<Crime>::const_iterator l_it = it->second.begin(); l_it != it->second.end(); ++l_it)
		{
			fout << *l_it << " ,";
		}
		fout.seekp(-2, std::ios_base::cur);//сдвигаем курсор на 2 позиции на 2 символа влево относительно текущей позиции
		fout << ";\n";
	}
	fout.close();
	system("start notepad base.txt");
}
void load(std::map<std::string, std::list<Crime>>& base)
{
	std::ifstream fin("base.txt");
	if (fin.is_open())
	{
		std::string key;
		std::string value;
		while (!fin.eof())
		{
			std::getline(fin, key, ':');
			base[key];
			std::getline(fin, value);
			value.erase(value.find_last_not_of(';'));
			if (value.find(',') == std::string::npos)

			{
				base[key].push_back(Crime(std::stoi(value), value));
				base[key].back().get_place().erase(0, 1);

			}
			else
			{
				char* all_crimes = new char[value.size() + 1];
				strcpy(all_crimes, value.c_str());
				for (char* pch = strtok(all_crimes, ",:"); pch; pch = strtok(NULL, ",;"))
				{
					int crime_id = atoi(pch);
					while (*pch == ' ')pch++;
					base[key].push_back(Crime(crime_id, pch + 1));
				}
			}
				/*for (size_t start = -1, end = 0; value.find(';', start) != std::string::npos; start = end)
			{
				end = value.find(',', start + 1);
				std::string buffer = value.substr(start+1, end - start);
				if (buffer.find_first_not_of(' ') != std::string::npos)
					buffer.erase(0, buffer.find_first_not_of(' '));
				int crime_id = std::stoi(buffer);
				buffer.erase(0, 1);
				base[key].push_back(Crime(crime_id, buffer));
			}*/
		}
		fin.close();
		base.erase("");
	}
	else
	{
		std::cerr << "Error:file not found" << endl;
	}
}
