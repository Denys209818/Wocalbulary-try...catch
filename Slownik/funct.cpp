#include "libs.h"
#include "Slownik.h"
//try...catch()
void RemoveElement(Slownik& sl)
{
	char* l = new char[255];
	cout << "Введить слово (англ) - ";
	do
	{
		cin.getline(l, 255);
	} while (l[0] == '\0');
	char* t = sl.GetForEng(l);
	if (t != nullptr)
	{
		t == nullptr;
		cout << "Введiть новий переклад - ";
		do
		{
			cin.getline(t,255);
		} while (t == nullptr);

		try 
		{
		if(!remove("baza.txt")) throw 1;
		}
		catch (int ex) 
		{
			if (ex == 1) cerr << "Не можна видалити файл!" << endl;
		}

		ofstream fs("baza.txt", ios_base::app);
		sl.ReturnFromSlownik(fs);
		fs.close();
	}
	else
	{
		_getch();
	}
	delete l;
}



//try...catch()
void DeleteElement(Slownik& sl)
{
	char* l = new char[255];
	cout << "Введить слово (англ) - ";
	do
	{
		cin.getline(l, 255);
	} while (l[0] == '\0');

	sl.DelElement(l);
	try 
	{
	if(!remove("baza.txt")) throw 1;
	}
	catch (int ex) 
	{
		if (ex == 1) cerr << "Не можна видалити файл!" << endl;
	}

	ofstream fs("baza.txt", ios_base::app);
	sl.ReturnFromSlownik(fs);
	fs.close();
	delete l;
}