#pragma once
using std::cin;
using std::cout;
using std::endl;
#define GRADUATE_TAKE_PARAMETERS const std::string& subject
#define GRADUATE_GIVE_PARAMETERS subject
class Graduate :public Student
{
	std::string subject;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}

	//			Constructors:
	Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, GRADUATE_TAKE_PARAMETERS) : Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS){
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	Graduate(const Student& student, const std::string& subject) :Student(student)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}

	//					Methods:
	std::ostream& print(std::ostream& os)const override
	{
		return Student::print(os)<< " " << "Subject of diploma is '" << subject << "'";
	}

	std::ofstream& print(std::ofstream& ofs)const override
	{
		Student::print(ofs) << subject;
		return ofs;
	}

	std::ifstream& read(std::ifstream& ifs) override
	{
		Student::read(ifs);
		std::getline(ifs, subject);
		return ifs;
	}
};
