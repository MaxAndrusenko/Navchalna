#include "Library.h" 
#include <iostream> 
using namespace std;

Library::Library(string book, string genre, int year, string author, string value)
{
	this->book = book;
	this->genre = genre;
	this->year = year;
	this->author = author;
	this->value = value;
}

void Library::Write()
{
	cout << "Available books: " << book << " / " << genre << " / " << year << " / " << author << " / "<< value << endl;


}
string Library::GetBook() {
	return book;

}
string Library::GetGenre()
{
	return genre;
}
int Library::GetYear()
{
	return year;
}
string Library::GetAuthor()
{
	return author;
}
string Library::GetValue()
{
	return value;
}