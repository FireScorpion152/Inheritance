#pragma once
using std::cin;
using std::cout;
using std::endl;
#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age
class Human
{
	static const int TYPE_WIDTH = 12;
	static const int LAST_NAME_WIDTH = 15;
	static const int FIRST_NAME_WIDTH = 15;
	static const int AGE_WIDTH = 5;
	std::string last_name;
	std::string first_name;
	int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}

	//				Constructors:
	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//				Methods:
	virtual std::ostream& print(std::ostream& os)const {
		return os << last_name << " " << first_name << " " << age;
	}

	virtual std::ofstream& print(std::ofstream& ofs)const
	{
		ofs.width(TYPE_WIDTH);	//Метод width() задает ширину вывода.
		//При первом вызове метод width() включает выравнивание по правому краю.
		ofs << std::left;	//Возвращаем выравнивание по левому краю.
		//Один вызов width() влияет только на одно выводимое значение
		ofs << std::string(strchr(typeid(*this).name(), ' ') + 1) + ":";	//Оператор typeid(type | value) определяет тип значения на этапе выполнения программы.
		//Метод name() возвращает C-string содержащую имя типа.
		ofs.width(LAST_NAME_WIDTH);
		ofs << last_name;
		ofs.width(FIRST_NAME_WIDTH);
		ofs << first_name;
		ofs.width(AGE_WIDTH);
		ofs << age;
		return ofs;
	}
	virtual std::ifstream& read(std::ifstream& ifs)
	{
		ifs >> last_name >> first_name >> age;
		return ifs;
	}
};