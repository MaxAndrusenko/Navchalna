#ifndef COMMAND_H  
#define COMMAND_H  

#include<iostream>  
#include"Library.h"  
#include "Collection.h"
#include "Used.h"
#include "New.h"

using namespace std;
class Command
{
	Library* libraries;
	int lastLibraryIndex;
	string book;

public:
	Command();
	~Command();

	void AddLibrary(Library&);
	void AddCollection(Collection&);
	void AddUsed(Used&);
	void AddNew(New&);
	void WriteLibraries();
	string GetMostPopularLib();
	void Open();
};

#endif // !COMMAND_H
