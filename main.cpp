/* ������� 1: ����� � ������� ��������
� ��������� ����� �������� ���� ������ ������ ������. �� ����������� 100 ���������� (���� 100). ���� ������ - ���� ���������.
������ ������: 1. ������� � �������� (������ �.�.)(char) 2. ��� �������� (int) 3. ������ ������ (float) 4. ���� ����������� �� ������ (01.01.2000)(char11)
������ ������ ��� � ���� ���� ������ ����� 25 ��� � �� ������� �����
������� ����� � ������ ��������� ���������� ���� ��������� ����. 
����� �������� ��������� ������: �����������, ����������, ������ � ��������� �����, ���� ������ � ����������, ����� ������ �� �����, ��������� �� ������� ����
� ��������� ������������: ������ ������ �� ����� .txt � ������ �� � ������ �������� ������ ������� �������� ������� ���� ���������.
�������� �� ���� ������ ��������, ������ ��������� ������ ����������� � �� ����� ��� ��������� ���� ����� ���
*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Employee
{
[private:]//[private:] - ���������� ������ �������� ����������� ��������
   //<�������� ������� ���������>
	char* name;
	int year;
	float salary;
	char date[11];
	
public:
   //<�������� �������� ���������>
	Employee()
	{
		name = new char[20];
		year = 0;
		salary = 0.0;
		date[0] = '\0';
	}
	Employee(int n)
	{
		name = new char[n];
		year = 0;
		salary = 0.0;
		date[0] = '\0';
	}
	~Employee()
	{
		if (name)
			delete[] name;

	}
	// ������
	
	void Set_Name(char* name_) // ������������ �����
	{
		strcpy(name, name_);
	}

	void Set_Year(int year_)
	{
		year = year_;
	}

	void Set_Salary(float salary_)
	{
		salary = salary_;
	}

	void Set_Date(char* date_)
	{
		strcpy(date, date_);
	}

	char* Get_Name() //����� �����
	{
		return name;
	}

	int Get_Year()
	{
		return year;
	}
	
	int Get_Salary()
	{
		return salary;
	}

	char* Get_Date()
	{
		return date;
	}

	void Print_Info() //����� �����
	{
		printf("%s %d %f %s", name, year, salary, date);
	}

	void Input_Info() //���� �����
	{
		char initials[5];

		scanf_s("%s %s %d %f %s", name, initials, &year, &salary, date);

		strcat(name, " ");
		strcat(name, initials);
	}

	bool Sif(char* str_)
	{
		(strcmp(name, str_) == 0) ? true : false;
	}


};

int Create_F(char* file_name, int& size, Employee* arr) //size - �������� ����������� �������
{
	FILE* file;
	fopen_s(&file, file_name, "r");
	if (!file)
		return -1;

	char surname[30];
	char initials[5];
	int year;
	float salary;
	char* date[11];

	while (fscanf(file, "%s %s %d %f %s", surname, initials, year, salary, date))
	{
		strcat(surname, " ");
		strcat(surname, initials);
	}
}