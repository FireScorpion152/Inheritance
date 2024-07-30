#include<iostream>
#include<string>
#include<fstream>
#include "Human.h"
#include "Student.h"
#include "Teacher.h"
#include "Graduate.h"
using std::cin;
using std::cout;
using std::endl;
#define delimiter "\n---------------------------------------------\n"

void Print(Human* group[], const int n)
{
	cout << delimiter << endl;
	for (int i = 0; i < n; i++)
	{
		//group[i]->print();
		if (group[i])
		{
			cout << *group[i] << endl;
			cout << delimiter << endl;
		}
	}
	cout << "Колиество человек в группе: " << n << endl;
}
void Save(Human* group[], const int n, const std::string& filename)
{
	std::ofstream fout(filename);
	for (int i = 0; i < n; i++)
	{
		fout << *group[i] << endl;
	}
	fout.close();
	std::string cmd = "notepad " + filename;
	system(cmd.c_str());	//Функция system(const char*) выполняет любую досутпную коданду операционной системы
	//Метод c_str() возвращает C-string (NULL Terminated Line), обвернутый в объект класса std::string.
}
Human* HumanFactory(const std::string& type)
{
	Human* human = nullptr;
	if (type == "Human:")human = new Human("", "", 0);
	if (type == "Teacher:")human = new Teacher("", "", 0, "", 0);
	if (type == "Student:")human = new Student("", "", 0, "", "", 0, 0);
	if (type == "Graduate:")human = new Graduate("", "", 0, "", "", 0, 0, "");
	return human;
}
bool NotAppropriateType(const std::string& buffer)
{
	//Несоответствуюший тип:
	return buffer.find("Human:") == std::string::npos &&
		buffer.find("Student:") == std::string::npos &&
		buffer.find("Teacher:") == std::string::npos &&
		buffer.find("Graduate:") == std::string::npos;
}
Human** Load(const std::string& filename, int& n)
{
	Human** group = nullptr;
	std::ifstream fin(filename);
	if (fin.is_open())
	{
		//1) Выичсляем размер файла (количество записей в файле):
		n = 0;
		while (!fin.eof())
		{
			std::string buffer;
			//fin.getline();	//НЕ перегружен для объектов класса std::string
			std::getline(fin, buffer);	//читает все до конца строки
			//move DST, SRC;
			//strcat(DST, SRC);
			if (NotAppropriateType(buffer))continue;
			n++;
		}
		cout << "Количество записей в файле: " << n << endl;

		//2) Выделяем память для группы:
		group = new Human * [n] {};

		//3) Возвращаемся в начало файла, для того чтобы прочитать содержимое этого файла:
		cout << "Позиция курсора на чтение: " << fin.tellg() << endl;
		fin.clear();
		fin.seekg(0);
		cout << "Позиция курсора на чтение: " << fin.tellg() << endl;

		//4) Читаем файл:
		for (int i = 0; i < n; i++)
		{
			std::string type;
			fin >> type;
			if (NotAppropriateType(type))continue;
			group[i] = HumanFactory(type);
			if (group[i])
				fin >> *group[i];
		}

		fin.close();
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
	return group;
}
void Clear(Human* group[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		delete group[i];
	}
}


//#define INHERITANCE
//#define GROUP_ARRAY_CONSOLE
//#define WRITE_TO_FILE
#define READ_FROM_FILE
void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE
	cout << "HelloAcademy" << endl;
	Human human("Richter", "Jeffrey", 40);
	human.print();
	cout << delimiter << endl;
	Student student("Pinkman", "Jessie", 20, "Chemistry", "WW_220", 95, 90);
	student.print();
	cout << delimiter << endl;
	Teacher teacher("White", "Walter", 50, "Chemistry", 25);
	teacher.print();
	cout << delimiter << endl;
	Graduate graduate2("Shrader", "Hank", 53, "Criminalistic", "OBN", 70, 75, "How to catch Heisenberg");
	graduate2.print();
#endif // INHERITANCE
	Human* group[] = {

	new Student("Pinkman", "Jessie", 20, "Chemistry", "WW_220", 95, 90),
	new Teacher("White", "Walter", 50, "Chemistry", 25),
	new Graduate("Shrader", "Hank", 53, "Criminalistic", "OBN", 70, 75, "How to catch Heisenberg"),
	new Student("Vercetti", "Tom", 30, "Theft", "Vice", 97,98),
	new Teacher("Diaz", "Ricardo", 50, "Weapons Distribution",20)
	};
#ifdef GROUP_ARRAY_CONSOLE
	cout << delimiter << endl;
	Print(group, sizeof(group) / sizeof(group[0]));
	cout << delimiter << endl;
#endif // GROUP_ARRAY_CONSOLE
#ifdef WRITE_TO_FILE
	fPrint(group, sizeof(group));
#endif // WRITE_TO_FILE

	Clear(group, sizeof(group) / sizeof(group[0]));
	cout << delimiter << endl;
#ifdef READ_FROM_FILE
	std::ifstream fin("File.txt");
	if (fin.is_open()) {
		while (!fin.eof()) {
			const int SIZE = 1024;
			char buffer[SIZE]{};
			fin.getline(buffer, SIZE);
			cout << buffer << endl;
		}
		fin.close();
	}
	else {
		std::cerr << "Error: File not found" << endl;
	}
#endif // READ_FROM_FILE


}