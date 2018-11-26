//
//  Book.hpp
//  LibraryManager
//
//  Created by MagicLetur on 12/04/2018.
//  Copyright © 2018 Cesare-Herriau. All rights reserved.
//

#ifndef Book_hpp
#define Book_hpp

#include <stdio.h>
#include <string>
#include "Ressource.hpp"

class Book : public Ressource{

protected:
	int pages;
	std::string publication;
	std::string collection;
	std::string summary;
	
public:
	
	Book();
	Book(int _pages, std::string _publication, std::string _collection, std::string _summary);
	~Book();
	
	int getPages();
	std::string getPublication();
	std::string getCollection();
	std::string getSummary();
	

};

#endif /* Book_hpp */
