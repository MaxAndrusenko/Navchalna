#ifndef COLLECTION_H 
#define COLLECTION_H 

#include<string> 
#include<iostream> 
#include"Library.h" 
using namespace std;

class Collection : public Library
{
	
public:
	Collection(string = "", string = " ", int = 1920, string = "", string = "");
	void Write()
	{
		cout << "This is a collection book " << endl;
	}
	Collection(string book, string genre, int year, string author, string value);
};

#endif // !COLLECTION_H
