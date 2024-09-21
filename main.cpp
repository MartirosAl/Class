#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

const int maxn = 100;

class Employee
{
private:
	char* name;
	int year;
	float salary;
	char date[11];

public:
	
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

	void Set_Name(const char* name_)
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

	void Set_Date(const char* date_)
	{
		strcpy(date, date_);
	}

	char* Get_Name()
	{
		return name;
	}

	int Get_Year()
	{
		return year;
	}

	float Get_Salary()
	{
		return salary;
	}

	char* Get_Date()
	{
		return date;
	}

	void Print_Info() 
	{
		printf("%s %d %0.2f %s", name, year, salary, date);
	}

	void Input_Info() 
	{
		char initials[5];

		scanf_s("%s %s %d %f %s", name, initials, &year, &salary, date);

		
		strcat(name, " ");
		strcat(name, initials);
	}

	bool Sif(char* str_)
	{
		return (strcmp(name, str_) == 0) ? true : false;
	}


};

class Base
{
private:
	Employee* arr;
	int size;

public:
	
	Base()
	{
		arr = new Employee[maxn];
		size = 0;
	}

	Base(int size_)
	{
		arr = new Employee[size_];
		size = size_;
	}

	~Base()
	{
		delete[] arr;
	}

	Employee Get_Employee(int i_)
	{
		return arr[i_];
	}
	void Set_Size(int size_)
	{
		size = size_;
	}

	int Get_Size()
	{
		return size;
	}

	int Create_Base_F(const char* file_name_)
	{
		FILE* file;
		fopen_s(&file, file_name_, "r");
		if (!file)
			return -1;


		char surname[31];
		char initials[5];
		int year = 0;
		float salary = 0.0;
		char date[11];
		size = 0;

		while (fscanf(file, "%s %s %d %f %s", surname, initials, &year, &salary, date) != EOF)
		{
			strcat(surname, " ");
			strcat(surname, initials);
			arr[size].Set_Name(surname);
			arr[size].Set_Year(year);
			arr[size].Set_Salary(salary);
			arr[size].Set_Date(date);

			size++;
		}

		if (size > maxn)
			return -2;

		return 0;
	}

	void Print_Base()
	{
		for (int i = 0; i < size; i++)
		{
			arr[i].Print_Info();
			printf("\n");
		}
	}

	int Add_from_class(Employee employee_)
	{
		arr[size].Set_Name(employee_.Get_Name());
		arr[size].Set_Date(employee_.Get_Date());
		arr[size].Set_Salary(employee_.Get_Salary());
		arr[size].Set_Year(employee_.Get_Year());
		size++;

		return 0;
	}

	int Add_from_class(Employee* employee_, int& size_)
	{
		for (int i = 0; i < size_; i++)
		{
			arr[size].Set_Name(employee_[i].Get_Name());
			arr[size].Set_Date(employee_[i].Get_Date());
			arr[size].Set_Salary(employee_[i].Get_Salary());
			arr[size].Set_Year(employee_[i].Get_Year());
			size++;
		}

		return 0;
	}

	//int Add_from_base(Base base_)
	//{
	//	int size_base_ = base_.Get_Size();
	//	for (int i = 0; i < size_base_; i++)
	//	{
	//		arr[size].Set_Name((base_.Get_Employee(i)).Get_Name());
	//		arr[size].Set_Date((base_.Get_Employee(i)).Get_Date());
	//		arr[size].Set_Salary((base_.Get_Employee(i)).Get_Salary());
	//		arr[size].Set_Year((base_.Get_Employee(i)).Get_Year());
	//	}

	//	return 0;
	//}

	int Add(const char* name_, int year_, float salary_, const char date_[11])
	{
		Employee employee;
		arr[size].Set_Date(date_);
		arr[size].Set_Name(name_);
		arr[size].Set_Salary(salary_);
		arr[size].Set_Year(year_);

		size++;

		return 0;
	}
	
	void delete_note(const char* name_)
	{
		
	}
};

int Create_F(const char* file_name_, int& size, Employee* arr) 
{
	FILE* file;
	fopen_s(&file, file_name_, "r");
	if (!file)
		return -1;

	char surname[31];
	char initials[5];
	int year = 0;
	float salary = 0.0;
	char date[11];
	size = 0;

	while (fscanf(file, "%s %s %d %f %s", surname, initials, &year, &salary, date) != EOF)
	{
		strcat(surname, " ");
		strcat(surname, initials);
		arr[size].Set_Name(surname);
		arr[size].Set_Year(year);
		arr[size].Set_Salary(salary);
		arr[size].Set_Date(date);

		size++;
	}

	if (size > maxn)
		return -2;

	return 0;
}

float Request_1(Employee* arr_, int size_, int current_year_, int& k, char** FIO_25years)
{
	k = 0;
	float average_salary = 0;
	char* date_employee = new char[11];
	int year_employee = 0;

	for (int i = 0; i < size_; ++i)
	{
		date_employee = arr_[i].Get_Date();

		year_employee = (date_employee[6] - '0') * 1000 + (date_employee[7] - '0') * 100 + (date_employee[8] - '0') * 10 + (date_employee[9] - '0');

		if (current_year_ - year_employee > 25)
		{
			strcpy(FIO_25years[k], arr_[i].Get_Name());
			++k;
			average_salary += arr_[i].Get_Salary();
		}
	}

	if (k != 0)
		average_salary /= k;

	return average_salary;
}



int main()
{
	/*
	int size;

	Employee arr[maxn];

	int error = 0;

	error = Create_F("test.txt", size, arr);
	switch (error)
	{
	case -1:
		printf("File opening error");
		exit(-1);
	case -2:
		printf("There is too much incoming data");
		exit(-2);
	}

	int size_employee = 0;

	char** FIO_25years = new char* [maxn];
	for (int i = 0; i < maxn; i++)
		FIO_25years[i] = new char[31];

	printf("Average salary: %0.2f\n", Request_1(arr, size, 2024, size_employee, FIO_25years));

	for (int i = 0; i < size_employee; i++)
	{
		printf("%s\n", FIO_25years[i]);
	}
	*/

	Base base;

	base.Create_Base_F("test.txt");

	base.Print_Base();
	printf("----\n");

	base.Add("Maaaa A.E.", 2000, 1111.1, "01.02.3008");

	base.Print_Base();
	printf("----\n");

	Employee emp[maxn];
	int size;

	Create_F("test2.txt", size, emp);

	base.Add_from_class(emp, size);

	base.Print_Base();
	printf("----\n");

	//Base base2;

	//base2.Create_Base_F("test2.txt");

	//base.Add_from_base(base2);

	//base.Print_Base();
	//printf("----\n");



	return 0;
}
