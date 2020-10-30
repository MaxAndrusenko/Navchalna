#ifndef LIBRARY_H 
#define LIBRARY_H 

#include<string> 
using namespace std;

class Library
{ protected:
	string book;
	string genre;
	int year;
	string author;
	string value;

public:
	Library(string = "", string = "", int = 2020, string = "", string = "");

	void Write();


	string GetBook();
	string GetGenre();
	int GetYear();
	string GetAuthor();
	string GetValue();
};

#endif // !LIBRARY_H
