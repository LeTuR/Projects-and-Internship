//
//  Ressource.hpp
//  LibraryManager
//
//  Created by MagicLetur on 12/04/2018.
//  Copyright © 2018 Cesare-Herriau. All rights reserved.
//

#ifndef Ressource_hpp
#define Ressource_hpp

#include <stdio.h>
#include <string>

class Ressource{

private:
	static int id_counter;
public:
	std::string title;
	std::string author;
	int id;
	bool free;	
	
	Ressource();
	Ressource(std::string _title, std::string _author);
	~Ressource();
	
	std::string getTitle();
	std::string getAuthor();
	bool getDisponibility();
	int getId();
};

#endif /* Ressource_hpp */
