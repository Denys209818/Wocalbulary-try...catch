#include "libs.h"
#include "Slownik.h"

void RemoveElement(Slownik& sl);

void DeleteElement(Slownik& sl);

void main() 
{
	setlocale(LC_CTYPE, "ukr");
	Slownik sl;
	char * test = new char[255];
	char * s1 = new char[255];
	char * s2 = new char[255];
	ifstream fs("baza.txt");
	if (fs.is_open()) 
	{
	while (!fs.eof()) 
	{
		fs.getline(s1,255);
	
		//cout << s1 << endl;
		char * s = strpbrk(s1, ".");
		if (s != '\0') 
		{
		//cout << s+1 << endl;
		for (int i = 0; i < strlen(s1)+1; i++) 
		{
			if (s1[i] == '.') 
			{
				s1[i] = '\0';
				break;
			}
		}
		strcpy_s(s2, strlen(s + 1) + 1, s + 1);
		sl.AddSlowo(s1, s2);
	 
		}
		}
		
	
	fs.close();
	}

	char * e = new char[255];
	char ch = ' ';

	while (true) 
	{

		if (ch == 'r') 
		{
			RemoveElement(sl);
		}

		if (ch == 'd')
		{
			DeleteElement(sl);
		}

	system("cls");
	

	cout << "Введiть слово для пошуку - ";
	
	  do
	  {
	  cin.getline(e, 255);
	  } while (e[0] == '\0');
	

	
	if (sl.GetForEng(e) != nullptr)
	{
	SetConsoleCP(1251);
	

	cout  << "Pereklad: " << sl.GetForEng(e) << endl;
	SetConsoleCP(866);
	}
	else 
	{
		char pereklad[255];
		cout << "Введiть переклад i слово запишеться в словник - ";
		cin.getline(pereklad, 255);
		
		sl.AddSlowo(e, pereklad);
		ofstream fs("baza.txt", ios_base::app);
		fs << "\n" << e << "." << pereklad;
		fs.close();
	    
	}
	_getch();
	system("cls");
	cout << "Продовжити жмiть Enter & Редагувати жмiть r & Видалити елемент жмiть d" << endl;
	ch = _getch();
	}


}