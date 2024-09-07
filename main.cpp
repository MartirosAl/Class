/* Задание 1: поиск в массиве объектов
В текстовом файле хратится база данных отдела кадров. На предприянии 100 сотруднике (макс 100). Одна строка - один сотрудник.
Формат записи: 1. Фамилия и инициалы (Карлов Б.Н.)(char) 2. Год рождения (int) 3. Размер оклада (float) 4. Дата поступления на работу (01.01.2000)(char11)
Выдаем список тех у кого стаж работы более 25 лет и их средний оклад
Описать класс с именем Сотрудник содержащий выше указанные поля. 
Класс содержит следующие методы: конструктор, деструктор, доступ к отдельным полям, ввод данных с клавиатуры, вывод данных на экран, сравнение по первому полю
В программе использовать: Чтение данных из файла .txt и запись их в массив элементы данных которых являются объекты типа Сотрудник.
Получаем на вход массив объектов, выдаем требуемый список сотрудников и их оклад или сообщение если таких нет
*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Employee
{
[private:]//[private:] - квадратные скобки означают возможность упущения
   //<Описание скрытых элементов>
	char* name;
	int year;
	float salary;
	char date[11];
	
public:
   //<Описание открытых элементов>
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
	// Методы
	
	void Set_Name(char* name_) // Установление имени
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

	char* Get_Name() //Вывод имени
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

	void Print_Info() //Вывод всего
	{
		printf("%s %d %f %s", name, year, salary, date);
	}

	void Input_Info() //Ввод всего
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

int Create_F(char* file_name, int& size, Employee* arr) //size - реальная размерности массива
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