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

std::ostream& operator<<(std::ostream& os, const Human& obj) {
	return obj.print(os);
}
void Print(Human* group[], int n) {
	for (int i = 0; i < n; i++) {
		cout << *group[i] << endl;
		cout << delimiter << endl;
	}
}
void Clear(Human* group[], int n) {
	for (int i = 0; i < n; i++) {
		delete group[i];
	}
}
void fPrint(Human* group[], int n) {
	std::ofstream fout;
	fout.open("File.txt");
	for (int i = 0; i < n; i++) {
		fout << *group[i] << endl;
		fout << delimiter << endl;
	}
	fout.close();
	system("notepad File.txt");
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