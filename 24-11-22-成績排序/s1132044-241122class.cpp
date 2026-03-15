#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
#define N 34
struct Student
{
	int id = { 0 };
	string name = { 0 };
	int eng = { 0 };
	int math = { 0 };
	int program = { 0 };
	int sum = { 0 };
};
void read_data(Student s[N], string title[6])
{
	int i;
	ifstream file;
	file.open("test.txt");
	//------- read title  ------
	for (i = 0; i < 6; i++)
		file >> title[i];
	//------- read individual data -----
	for (i = 0; i < N; i++)
	{
		file >> s[i].id;
		file >> s[i].name;
		file >> s[i].eng;
		file >> s[i].math;
		file >> s[i].program;
	}
	file.close();
}
void caculator(Student s[N])
{
	for (int i = 0; i < N; i++)
	{
		s[i].sum = 0;
		s[i].sum += s[i].eng;
		s[i].sum += s[i].math;
		s[i].sum += s[i].program;
	}
}
void sort(Student s[N])
{
	int tmp_num;
	string tmp_name;
	for (int i = 0; i < N - 1; i++)
		for (int j = N - 2; j >= i; j--)
		{
			if (s[j].sum < s[j + 1].sum)
			{
				tmp_num = s[j].id; s[j].id = s[j + 1].id; s[j + 1].id = tmp_num;
				tmp_num = s[j].eng; s[j].eng = s[j + 1].eng; s[j + 1].eng = tmp_num;
				tmp_num = s[j].math; s[j].math = s[j + 1].math; s[j + 1].math = tmp_num;
				tmp_num = s[j].program; s[j].program = s[j + 1].program; s[j + 1].program = tmp_num;
				tmp_num = s[j].sum; s[j].sum = s[j + 1].sum; s[j + 1].sum = tmp_num;
				tmp_name = s[j].name; s[j].name = s[j + 1].name; s[j + 1].name = tmp_name;
			}
		}
}
void Separator(int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << "-";
	cout << endl;
}
void show_data(Student s[N], string title[6])
{
	for (int i = 0; i < 6; i++)
		cout << title[i] << "\t";
	cout << endl;
	Separator(45);
	for (int i = 0; i < 19; i++)
	{
		cout << setw(3) << s[i].id << "\t";
		cout << s[i].name << "\t";
		cout << setw(3) << s[i].eng << "\t";
		cout << setw(3) << s[i].math << "\t";
		cout << setw(3) << s[i].program << "\t";
		cout << setw(3) << s[i].sum << "\t";
		cout << endl;
	}
}

int main()
{
	string title[6];
	struct Student s[N];

	//--- read data from file -----
	read_data(s, title);
	
	//---- caculator -----
	caculator(s);

	//--- show data ------
	show_data(s, title);
	cout << endl;

	//---- sort -------
	sort(s);

	//--- show after sort data ------
	show_data(s, title);
}