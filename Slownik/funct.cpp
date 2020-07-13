#include "libs.h"
#include "Slownik.h"
//try...catch()
void RemoveElement(Slownik& sl)
{
	char* l = new char[255];
	cout << "������� ����� (����) - ";
	do
	{
		cin.getline(l, 255);
	} while (l[0] == '\0');
	char* t = sl.GetForEng_(l);
	if (t != nullptr)
	{
		

		cout << "����i�� ����� �������� - ";
		do
		{
			cin.getline(t,255);
		} while (t == nullptr);

		try 
		{
				remove("baza.txt");
		}
		catch (...) 
		{
			cerr << "�� ����� �������� ����!"<< endl;
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
	cout << "������� ����� (����) - ";
	do
	{
		cin.getline(l, 255);
	} while (l[0] == '\0');

	sl.DelElement(l);
	
	try
	{
		remove("baza.txt");
	}
	catch (...)
	{
		cerr << "�� ����� �������� ����!" << endl;
	}
	

	ofstream fs("baza.txt", ios_base::app);
	sl.ReturnFromSlownik(fs);
	fs.close();
	delete l;
}