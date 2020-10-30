#include"Command.h"  
#include<iostream>  
#include <fstream>  

using namespace std;

string book;

Command::Command() {
    libraries = new Library[100];
    lastLibraryIndex = -1;

    ifstream fin("Library.txt");

    int maxLen = 50;
    char* book = new char[maxLen],
        * genre = new char[maxLen],
        * year = new char[maxLen],
        * author = new char[maxLen],
        * value = new char[maxLen];

    char delim = ',';
    while (!fin.eof())
    {
        fin.get(book, maxLen, delim);
        fin.get(); //reads delim  
        fin.get(genre, maxLen, delim);
        fin.get();
        fin.get(year, maxLen, delim);
        fin.get();
        fin.getline(author, maxLen);
        fin.get();
        fin.getline(value, maxLen);

        Library library(book, genre, atoi(year), author, value);
        AddLibrary(library);

    }

    fin.close();

    delete[] book;
    delete[] genre;
    delete[] year;
    delete[] author;
    delete[] value;

}


Command::~Command()
{
    ofstream fout("Library.txt");

    for (int i = 0; i <= lastLibraryIndex; i++)
    {
        fout << libraries[i].GetBook() << ","
            << libraries[i].GetGenre() << ","
            << libraries[i].GetYear() << ","
            << libraries[i].GetAuthor() << ","
            << libraries[i].GetValue();

        if (i < lastLibraryIndex)
            fout << endl;
    }

    fout.close();

    delete[] libraries;
}
void Command::AddCollection(Collection& collection)
{
    AddLibrary(collection);
}
void Command::AddUsed(Used& used)
{
    AddLibrary(used);
}
void Command::AddNew(New& news)
{
    AddLibrary(news);
}

void Command::AddLibrary(Library& library) {
    if (lastLibraryIndex >= 100)
    {
        throw "there is no free memory";

    }
    else cout << "Added successfully" << endl;

    libraries[++lastLibraryIndex] = library;
}

void Command::WriteLibraries() {
    cout << "Added books:" << endl;
    for (int i = 0; i <= lastLibraryIndex; i++)
    {
        libraries[i].Write();
    }
}

string Command::GetMostPopularLib()
{
    int maxNrLib = -1;
    string maxLib = "";

    for (int i = 0; i <= lastLibraryIndex; i++)
    {
        int nrOfLibs = 0;
        for (int j = i + 1; j <= lastLibraryIndex; j++)
        {
            if (libraries[i].GetGenre() == libraries[j].GetGenre())
                nrOfLibs++;
        }
        if (nrOfLibs > maxNrLib)
        {
            maxNrLib = nrOfLibs;
            maxLib = libraries[i].GetGenre();
        }
    }

    return maxLib;
}

void Command::Open() {
    Command cmd;
    Library c;
    cout << " Library " << endl;

    while (true)
    {
        cout << "Menu:   " << endl;
        cout << "1.Show books." << endl;
        cout << "2.Add a new book." << endl;
        cout << "3.Get most popular book" << endl;
        cout << "4.Finish" << endl;

        char userInput;
        string book;
        string genre;
        int year;
        string author;
        string value;
        char userInput2;

        cin >> userInput;
        if (userInput == '1')
        {
            cmd.WriteLibraries();

        }
        else if (userInput == '2')
        {
            cout << "Input the name of a book :";
            cin >> book;
            cout << endl;
            cout << "Input the book genre:";
            cin >> genre;
            cout << endl;
            cout << "Input year of the book:";
            cin >> year;
            cout << endl;
            cout << "Input author of the book:";
            cin >> author;
            cout << "Input class of Medicine:" << endl;
            cout << "1.Collections" << endl;
            cout << "2.New" << endl;
            cout << "3.Used" << endl;
            cin >> userInput2;
            if (userInput2 == '1')
            {
                c = Library(book, genre, year, author, "collection");
            }
            else if (userInput2 == '2')
            {
                c = Library(book, genre, year, author, "new");
            }
            else if (userInput2 == '3')
            {
                c = Library(book, genre, year, author, "used");
            }
            else
            {
                cout << "We don't have this class";
            }
            try
            {
                cmd.AddLibrary(c);
            }
            catch (const char* err)
            {
                cout << err << endl;
            }

        }
        else if (userInput == '3')
        {
            cout << "The most popular book is " << cmd.GetMostPopularLib() << endl;
        }
        else if (userInput == '4')
        {
            break;
        }
        else
        {
            throw "No function !";
        }
    }
}