//
//  Magazine.cpp
//  LibraryManager
//
//  Created by MagicLetur on 12/04/2018.
//  Copyright © 2018 Cesare-Herriau. All rights reserved.
//

#include "Magazine.hpp"
#include <stdio.h>
#include <string>

using namespace std;

					////////////////////
					// Initialization //
					////////////////////

					/////////////////
					// Constructor //
					/////////////////

Magazine::Magazine(){
	editor = "Unknown";
	articles = 0;
}

Magazine::Magazine(string _editor, int _articles){
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
