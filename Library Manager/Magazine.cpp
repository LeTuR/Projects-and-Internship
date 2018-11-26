//
//  Magazine.cpp
//  LibraryManager
//
//  Created by MagicLetur on 12/04/2018.
//  Copyright © 2018 Cesare-Herriau. All rights reserved.
//

#include "Magazine.hpp"
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

Magazine::Magazine(){
	title = "Unknown";
	author = "Unknown";
	free = true;
	editor = "Unknown";
	articles = 0;
}

Magazine::Magazine(string _title, string _author, int _pages, string _publication, string _collection, string _summary, string _editor, int _articles){
	title = _title;
	author = _author;
	free = true;
	pages = _pages;
	publication = _publication;
	collection = _collection;
	summary = _summary;
	editor = _editor;
	articles = _articles;
}

					////////////////
					// Destructor //
					////////////////

Magazine::~Magazine(){
	
}

					//////////////
					// Accessor //
					//////////////

string Magazine::getEditors(){
	return editor;
}

int Magazine::getArticles(){
	return articles;
}
					/////////////
					// Mutator //
					/////////////

					//////////
					// Else //
					//////////

void Magazine::save(ofstream &saving){
    saving<<"Magazine"<<"\n";
    Ressource::save(saving);
    saving<<pages<<"\n"<<publication<<"\n"<<collection<<"\n"<<summary<<"\n"<<editor<<"\n"<<articles;
}

void Magazine::display(){
	Book::display();
    cout<<" "<<editor<<" "<<articles;
}

string Magazine::qDisplay(){
    return("Magazine\n"+ Ressource::qDisplay()+"Pages: "+to_string(pages)+"\n"+"Publication: "+publication+"\n"+"Summary: "+summary+"\n"
           +"Editors: "+editor+"\n"+"Articles: "+to_string(articles));
}

bool Magazine::search(string searched) {
    if (Book::search(searched)==true) return true;
    else if (editor.find(searched)!=std::string::npos || to_string(articles).find(searched)!=std::string::npos) return true;
    else return false;
}
