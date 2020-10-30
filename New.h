#ifndef NEW_H  
#define NEW_H  

#include<string> 
#include<iostream> 
#include"Library.h" 
using namespace std;

class New : public Library
{
	
public:
	New(string = "", string = " ", int = 2020, string = "", string = "");
	void Write()
	{
		cout << "This is a new book " << endl;
	}
	New(string book, string genre, int year, string author, string value);
};

#endif // !NEW_H
