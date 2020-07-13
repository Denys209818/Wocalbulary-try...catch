#include "libs.h"
#include "Slownik.h"

void Slownik::AddToSlownik(Node* temp, Node* snew, char* engl, char* ukr)
{
	if (this->slowo == nullptr)
	{
		this->slowo = snew;
		snew->left = nullptr;
		snew->right = nullptr;
			strcpy_s(snew->eng, strlen(engl) + 1, engl);
			strcpy_s(snew->ukr, strlen(ukr) + 1, ukr);
		
		return;
	}

	else if ((int)engl[strlen(engl) - 1] >= (int)temp->eng[strlen(temp->eng) - 1])
	{
		if (temp->right == nullptr)
		{
			temp->right = snew;
			strcpy_s(temp->right->eng, strlen(engl) + 1, engl);
			strcpy_s(temp->right->ukr, strlen(ukr) + 1, ukr);
			
			return;
		}
		AddToSlownik(temp->right, snew, engl, ukr);
	}
	else if ((int)engl[strlen(engl) - 1] < (int)temp->eng[strlen(temp->eng) - 1])
	{
		if (temp->left == nullptr)
		{
			temp->left = snew;
			strcpy_s(temp->left->eng, strlen(engl) + 1, engl);
			strcpy_s(temp->left->ukr, strlen(ukr) + 1, ukr);
			
			return;
		}
		AddToSlownik(temp->left, snew, engl, ukr);
	}

	else if ((int)temp->eng[strlen(temp->eng) - 1] == (int)engl[strlen(engl) - 1] && _stricmp(temp->eng, engl) != 0)
	{
		if (temp->right == nullptr)
		{
			temp->right = snew;
			strcpy_s(temp->right->eng, strlen(engl) + 1, engl);
			strcpy_s(temp->right->ukr, strlen(ukr) + 1, ukr);
			
		}
		AddToSlownik(temp->right, snew, engl, ukr);
	}

}

void Slownik::ShowFromSlownik(Node* temp)
{
	if (temp == nullptr) return;
	ShowFromSlownik(temp->left);
	if (strpbrk(temp->ukr, "?"))
	{
		char* t = strpbrk(temp->ukr, "?");
		*t = 'i';
	}
	cout << temp->eng << " ---- " << temp->ukr << endl;
	ShowFromSlownik(temp->right);
}
//try...catch()
void Slownik::Del(Node*& temp, char* el)
{
	try 
	{
	if (temp == nullptr) throw 1;
	}
	catch (int ex) 
	{
		if (ex == 1) return;
	}

	if ((int)el[strlen(el) - 1] < (int)temp->eng[strlen(temp->eng) - 1]) { Del(temp->left, el); }
	else if ((int)el[strlen(el) - 1] >= (int)temp->eng[strlen(temp->eng) - 1] && _strcmpi(temp->eng, el) != 0) { Del(temp->right, el); }
	else if (_strcmpi(temp->eng, el) == 0)
	{
		if (temp->left == nullptr && temp->right == nullptr)
		{
			delete temp;
			temp = nullptr;
			return;
		}
		else if (temp->left == nullptr && temp->right != nullptr)
		{
			Node* del = temp;
			temp = temp->right;
			delete del;
			del = nullptr;
		}
		else if (temp->right == nullptr && temp->left != nullptr)
		{
			Node* del = temp;
			temp = temp->left;
			delete del;
			del = nullptr;
		}
		else
		{
			Node* min = FindMin(temp->right);
			strcpy_s(temp->eng, strlen(min->eng) + 1, min->eng);
			 strcpy_s(temp->ukr, strlen(min->ukr) + 1, min->ukr);
			
			Del(temp->right, min->eng);
			return;
		}
	}
	else
	{
		cout << "Word not found!" << endl;
		return;
	}
}

Slownik::Node*& Slownik::FindMin(Node*& root)
{
	if (root == nullptr) return root;
	if (root->left == nullptr)
		return root;
	FindMin(root->left);
}
//try...catch()
void Slownik::ReturnSlownik(Node* temp, ofstream& fs)
{
	try
	{
		if (temp == nullptr) throw 1;
	}
	catch (int ex)
	{
		if (ex == 1) return;
	}

	if (strpbrk(temp->ukr, "?"))
	{
		char* t = strpbrk(temp->ukr, "?");
		*t = 'i';
	}
	string word;
	word += temp->eng;
	word += ".";
	word += temp->ukr;

	fs << "\n" << word;
	ReturnSlownik(temp->right, fs);
}

Slownik::Slownik()
{
	this->slowo = nullptr;
}


void Slownik::AddSlowo(char* engl, char* ukr)
{
	Node* snew = new Node();
	snew->left = nullptr;
	snew->right = nullptr;
	
	AddToSlownik(this->slowo, snew, engl, ukr);

}

char* Slownik::GetForEng(char* word)
{
	Node* temp = this->slowo;
	while (temp != nullptr && temp->eng != word)
	{
		if (_stricmp(temp->eng, word) == 0)
		{
			for (int i = 0; i < strlen(temp->ukr) + 1; i++)
			{
				if (temp->ukr[i] == '?')
				{
					temp->ukr[i] = 'i';
				}
			}
		
			char el[255];
			strcpy_s(el, strlen(temp->eng)+1,temp->eng);
			strcat_s(el, " == ");
			strcat_s(el, temp->ukr);
		
			char* el2 = new char[255];
			strcpy_s(el2, strlen(el)+1,el);
			return el2;
		}

		else if ((int)word[strlen(word) - 1] >= (int)temp->eng[strlen(temp->eng) - 1])
		{
			temp = temp->right;
		}

		else if ((int)word[strlen(word) - 1] < (int)temp->eng[strlen(temp->eng) - 1])
		{
			temp = temp->left;
		}

	}

	cout << "Не знайдено!" << endl;
	return nullptr;
}

char* Slownik::GetForEng_(char* word)
{
	Node* temp = this->slowo;
	while (temp != nullptr && temp->eng != word)
	{
		if (_stricmp(temp->eng, word) == 0)
		{
			for (int i = 0; i < strlen(temp->ukr) + 1; i++)
			{
				if (temp->ukr[i] == '?')
				{
					temp->ukr[i] = 'i';
				}
			}

			
			return temp->ukr;
		}

		else if ((int)word[strlen(word) - 1] >= (int)temp->eng[strlen(temp->eng) - 1])
		{
			temp = temp->right;
		}

		else if ((int)word[strlen(word) - 1] < (int)temp->eng[strlen(temp->eng) - 1])
		{
			temp = temp->left;
		}

	}

	cout << "Не знайдено!" << endl;
	return nullptr;
}

void Slownik::Show()
{
	this->ShowFromSlownik(this->slowo);
}

void Slownik::DelElement(char* el)
{
	this->Del(this->slowo, el);
}

Slownik::Node* Slownik::GetMin()
{
	Node* temp = this->slowo->right;
	while (temp->left != nullptr)
	{
		temp = temp->left;
	}

	return temp;
}

void Slownik::ReturnFromSlownik(ofstream& fs)
{
	ReturnSlownik(this->slowo, fs);
}

Slownik::~Slownik()
{
	delete this->slowo;
}