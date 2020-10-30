#ifndef USED_H 
#define USED_H 

#include<string> 
#include<iostream> 
#include"Library.h" 
using namespace std;

class Used : public Library
{

public:
	Used(string = "", string = " ", int = 2010, string = "", string = "");
	void Write()
	{
		cout << "This is used book " << endl;
	}
	Used(string book, string genre, int year, string author, string value);
};
#endif // !USED_H