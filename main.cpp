/* Çàäàíèå 1: ïîèñê â ìàññèâå îáúåêòîâ
Â òåêñòîâîì ôàéëå õðàòèòñÿ áàçà äàííûõ îòäåëà êàäðîâ. Íà ïðåäïðèÿíèè 100 ñîòðóäíèêå (ìàêñ 100). Îäíà ñòðîêà - îäèí ñîòðóäíèê.
Ôîðìàò çàïèñè: 1. Ôàìèëèÿ è èíèöèàëû (Êàðëîâ Á.Í.)(char) 2. Ãîä ðîæäåíèÿ (int) 3. Ðàçìåð îêëàäà (float) 4. Äàòà ïîñòóïëåíèÿ íà ðàáîòó (01.01.2000)(char11)
Âûäàåì ñïèñîê òåõ ó êîãî ñòàæ ðàáîòû áîëåå 25 ëåò è èõ ñðåäíèé îêëàä
Îïèñàòü êëàññ ñ èìåíåì Ñîòðóäíèê ñîäåðæàùèé âûøå óêàçàííûå ïîëÿ.
Êëàññ ñîäåðæèò ñëåäóþùèå ìåòîäû: êîíñòðóêòîð, äåñòðóêòîð, äîñòóï ê îòäåëüíûì ïîëÿì, ââîä äàííûõ ñ êëàâèàòóðû, âûâîä äàííûõ íà ýêðàí, ñðàâíåíèå ïî ïåðâîìó ïîëþ
Â ïðîãðàììå èñïîëüçîâàòü: ×òåíèå äàííûõ èç ôàéëà .txt è çàïèñü èõ â ìàññèâ ýëåìåíòû äàííûõ êîòîðûõ ÿâëÿþòñÿ îáúåêòû òèïà Ñîòðóäíèê.
Ïîëó÷àåì íà âõîä ìàññèâ îáúåêòîâ, âûäàåì òðåáóåìûé ñïèñîê ñîòðóäíèêîâ è èõ îêëàä èëè ñîîáùåíèå åñëè òàêèõ íåò
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

const int maxn = 100;

class Employee
{
private://[private:] - êâàäðàòíûå ñêîáêè îçíà÷àþò âîçìîæíîñòü óïóùåíèÿ
	//<Îïèñàíèå ñêðûòûõ ýëåìåíòîâ>
		char* name;
		int year;
		float salary;
		char date[11];

public:
	//<Îïèñàíèå îòêðûòûõ ýëåìåíòîâ>
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
	// Ìåòîäû

	void Set_Name(char* name_) // Óñòàíîâëåíèå èìåíè
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

	char* Get_Name() //Âûâîä èìåíè
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

	void Print_Info() //Print âñåãî
	{
		printf("%s %d %f %s", name, year, salary, date);
	}

	void Input_Info() //Ââîä âñåãî
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

int Create_F(const char* file_name_, int& size, Employee* arr) //size - ðåàëüíàÿ ðàçìåðíîñòè ìàññèâà
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

	printf("Average salary: %f\n", Request_1(arr, size, 2024, size_employee, FIO_25years));

	for (int i = 0; i < size_employee; i++)
	{
		printf("%s\n", FIO_25years[i]);
	}



	return 0;
