#include<fstream>
#include<iostream> 
#include<time.h>

using namespace std;

struct student
{
	char name[100];
	unsigned age;
	unsigned course;
	bool pol;
	unsigned core;
	int id;
};

int idcnt = 1;

bool DeleteStud(int  Id);
bool FindStud(int Id, student& st);
void give_data(student* s);
void output(student* s);
void PrintAllStudents();
void PrintGoodStudents();
void FormGoodStudList(int n);
bool EditStudent(int Id);

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");

	ofstream outfile("file.bin", ios::binary);
	if (!outfile)
	{
		cout << "error2" << endl;
		return 1;
	}

	int n;
	cout << "Введите количество студентов: ";
	cin >> n;

	student s;
	for (int i = 0; i < n; i++)
	{
		give_data(&s);
		outfile.write((char*)&s, sizeof(s));
	}
	outfile.close();

	ifstream infile("file.bin", ios::binary);
	if (!infile)
	{
		cout << "error1" << endl;
		return 1;
	}

	FormGoodStudList(n);

	PrintAllStudents();
	/*EditStudent(2);
	PrintAllStudents();*/

	return 0;
}

void give_data(student* s)
{
	char mNames[10][74]
	= {
	"Владислав Владиславович Акулинкин",
	"Владимир Владимирович Каминский",
	"Василий Васильевич Санацкий",
	"Семен Семенович Муха",
	"Павел Павлович Троян",
	"Ярослав Ярославович Чирец",
	"Денис Денисович Тодадзе",
	"Дмитрий Дмитриевич Сулакадзе",
	"Александр Александрович Великий",
	"Петр Петрович Романов"
	};
	char fNames[10][74] =
	{
	 "Анна Владиславовна Клюцук",
	 "Елизавета Владимировна Каминская",
	 "Мария Васильевна Алешкевич",
	 "Юлия Евгеньевна Пироженко",
	 "Ирина Павловна Басацкая",
	 "Елена Ярославовна Зарецкая",
	 "Татьяна Денисовна Скрылева",
	 "Ольга Дмитриевна Дейко",
	 "Вероника Александровна Карелина",
	 "Виктория Петровна Коледа"
	};
	s->id = idcnt;
	idcnt++;
	s->pol = rand() % 2;
	if (s->pol)
	{
		strcpy_s(s->name, 74, mNames[rand() % 10]);
	}
	else
	{
		strcpy_s(s->name, 74, fNames[rand() % 10]);
	}
	s->course = rand() % 4 + 1;
	s->age = 17 + s->course;
	s->core = rand() % 10 + 1;
}

void output(student* s)
{
	cout << "ID: " << s->id << endl;
	cout << "ФИО: " << s->name << endl;
	if ((*s).pol) cout << "Пол: муж." << endl;
	else cout << "Пол: жен." << endl;
	cout << "Лет: " << s->age << endl;
	cout << "Курс: " << s->course << endl;
	cout << "Средний бал: " << s->core << endl;
	cout << endl;
}

void PrintAllStudents()
{
	ifstream out("file.bin", ios::binary);
	student s;

	out.read((char*)&s, sizeof(s));

	while (!out.eof())
	{
		output(&s);
		out.read((char*)&s, sizeof(s));
	}

	out.close();
}

void PrintGoodStudents()
{
	ifstream out("fileanswer.bin", ios::binary);
	student s;

	out.read((char*)&s, sizeof(s));

	while (!out.eof())
	{
		output(&s);
		out.read((char*)&s, sizeof(s));
	}

	out.close();
}

bool FindStud(int Id, student& st)
{
	ifstream readstud("file.bin", ios::binary);

	student stud;

	readstud.read((char*)&stud, sizeof(stud));

	while (!readstud.eof())
	{
		if (stud.id == Id)
		{
			st = stud;
			return 1;
		}

		readstud.read((char*)&stud, sizeof(stud));
	}


	return 0;
	readstud.close();
}

bool DeleteStud(int  Id)
{
	bool find = 0;
	ofstream studwthout("StudentsWithout.bin", ios::binary);
	ifstream studwth("file.bin", ios::binary);
	student stud;

	while (!studwth.eof())
	{
		studwth.read((char*)&stud, sizeof(stud));

		if (stud.id != Id)
		{
			studwthout.write((char*)&stud, sizeof(stud));
		}
		else
		{
			find = 1;
			studwth.read((char*)&stud, sizeof(stud));
		}
	}

	studwthout.close();
	studwth.close();

	ifstream studwthot("StudentsWithout.bin", ios::binary);
	ofstream studwthut("file.bin", ios::binary);

	studwthot.read((char*)&stud, sizeof(stud));

	while(!studwthot.eof())
	{
		studwthut.write((char*)&stud, sizeof(stud));
		studwthot.read((char*)&stud, sizeof(stud));
	}

	studwthout.close();
	studwth.close();

	ofstream stud1("StudentsWithout.bin", ios::binary);
	ifstream stud2("fileanswer.bin", ios::binary);

	while (!stud2.eof())
	{
		stud2.read((char*)&stud, sizeof(stud));

		if (stud.id != Id)
		{
			stud1.write((char*)&stud, sizeof(stud));
		}
		else
		{
			stud2.read((char*)&stud, sizeof(stud));
			find = 1;
		}
	}

	stud1.close();
	stud2.close();

	ifstream stud3("StudentsWithout.bin", ios::binary);
	ofstream stud4("fileanswer.bin", ios::binary);

	stud3.read((char*)&stud, sizeof(stud));

	while (!stud3.eof())
	{
		stud4.write((char*)&stud, sizeof(stud));
		stud3.read((char*)&stud, sizeof(stud));
	}

	stud3.close();
	stud4.close();

	remove("StudentsWithout.bin");

	return find;
}

void FormGoodStudList(int n)
{
	ifstream infile("file.bin", ios::binary);
	ofstream answ("fileanswer.bin", ios::binary);
	student s;

	int countansw = 0;
	for (int i = 0; i < n; i++) {

		infile.read((char*)&s, sizeof(s));
		if (s.core >= 9) {
			answ.write((char*)&s, sizeof(s));
			countansw++;
		}
	}

	answ.close();

	ifstream answ_read("fileanswer.bin", ios::binary);

	cout << endl << endl;
	for (int i = 0; i < countansw; i++) {
		answ_read.read((char*)&s, sizeof(s));
	}
}

bool EditStudent(int Id)
{
	bool find = 0;
	ofstream studwthout("StudentsWithout.bin", ios::binary);
	ifstream studwth("file.bin", ios::binary);
	student correctstud;

	cin >> correctstud.id;
	cin >> correctstud.name;
	cin >> correctstud.pol;
	cin >> correctstud.age;
	cin >> correctstud.course;
	cin >> correctstud.core;

	student stud;

	while (!studwth.eof())
	{
		studwth.read((char*)&stud, sizeof(stud));

		if (stud.id != Id)
		{
			studwthout.write((char*)&stud, sizeof(stud));
		}
		else
		{
			find = 1;
			studwthout.write((char*)&correctstud, sizeof(correctstud));
			studwth.read((char*)&stud, sizeof(stud));
		}
	}

	studwthout.close();
	studwth.close();

	ifstream studwthot("StudentsWithout.bin", ios::binary);
	ofstream studwthut("file.bin", ios::binary);

	studwthot.read((char*)&stud, sizeof(stud));

	while (!studwthot.eof())
	{
		studwthut.write((char*)&stud, sizeof(stud));
		studwthot.read((char*)&stud, sizeof(stud));
	}

	studwthout.close();
	studwth.close();

	ofstream stud1("StudentsWithout.bin", ios::binary);
	ifstream stud2("fileanswer.bin", ios::binary);

	while (!stud2.eof())
	{
		stud2.read((char*)&stud, sizeof(stud));

		if (stud.id != Id)
		{
			stud1.write((char*)&stud, sizeof(stud));
		}
		else
		{
			stud1.write((char*)&correctstud, sizeof(correctstud));
			stud2.read((char*)&stud, sizeof(stud));
			find = 1;
		}
	}

	stud1.close();
	stud2.close();

	ifstream stud3("StudentsWithout.bin", ios::binary);
	ofstream stud4("fileanswer.bin", ios::binary);

	stud3.read((char*)&stud, sizeof(stud));

	while (!stud3.eof())
	{
		stud4.write((char*)&stud, sizeof(stud));
		stud3.read((char*)&stud, sizeof(stud));
	}

	stud3.close();
	stud4.close();

	remove("StudentsWithout.bin");

	return find;
}