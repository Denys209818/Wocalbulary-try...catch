#pragma once
#include "libs.h"

class Slownik
{
	struct Node
	{
		char eng[255];
		char ukr[255];

		Node* left;
		Node* right;
	};

	Node* slowo;

	void AddToSlownik(Node* temp, Node* snew, char* engl, char* ukr);

	void ShowFromSlownik(Node* temp);

	void Del(Node*& root, char* key);

	Node*& FindMin(Node*& root);

	void ReturnSlownik(Node* temp, ofstream& fs);

public:
	Slownik();


	void AddSlowo(char* engl, char* ukr);

	char* GetForEng(char* word);

	void Show();

	void DelElement(char* el);

	Node* GetMin();

	void ReturnFromSlownik(ofstream& fs);

	~Slownik();
};
