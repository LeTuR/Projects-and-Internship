//
//  Book.cpp
//  LibraryManager
//
//  Created by MagicLetur on 12/04/2018.
//  Copyright © 2018 Cesare-Herriau. All rights reserved.
//

#include "Book.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

					////////////////////
					// Initialization //
					////////////////////

					/////////////////
					// Constructor //
					/////////////////

Book::Book(){
	title = "Unknown";
	author = "Unknown";
	free = true;
	pages = 0;
	publication = "Unknown";
	collection = "Unknown";
	summary = "Unknown";
}

Book::Book(string _title, string _author, int _pages, string _publication, string _collection, string _summary){
	title = _title;
	author = _author;
	free = true;
	pages = _pages;
	publication = _publication;
	collection = _collection;
	summary = _summary;
}

					////////////////
					// Destructor //
					////////////////

Book::~Book(){
	
}

					//////////////
					// Accessor //
					//////////////

int Book::getPages(){
	return pages;
}
string Book::getPublication(){
	return publication;
}
string Book::getCollection(){
	return collection;
}
string Book::getSummary(){
	return summary;
}

					/////////////
					// Mutator //
					/////////////

					//////////
					// Else //
					//////////

void Book::save(ofstream &saving){
    saving<<"Book"<<"\n";
    Ressource::save(saving);
    saving<<pages<<"\n"<<publication<<"\n"<<collection<<"\n"<<summary;
}

void Book::display(){
	Ressource::display();
	cout<<pages<<" "<<publication<<" "<<collection<<" "<<summary;
}

string Book::qDisplay(){
    return ("BOOK\n"+Ressource::qDisplay()+"Pages: "+to_string(pages)+"\n"+"Publication: "+publication+"\n"+"Summary: "+summary);
}

bool Book::search(string searched) {
    if (Ressource::search(searched)==true) return true;
    else if (publication.find(searched)!=std::string::npos || collection.find(searched)!=std::string::npos
             || to_string(pages).find(searched)!=std::string::npos|| summary.find(searched)!=std::string::npos) return true;
    else return false;
}
