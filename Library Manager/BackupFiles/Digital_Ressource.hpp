//
//  Digital_Ressource.hpp
//  LibraryManager
//
//  Created by MagicLetur on 12/04/2018.
//  Copyright © 2018 Cesare-Herriau. All rights reserved.
//

#ifndef Digital_Ressource_hpp
#define Digital_Ressource_hpp

#include <stdio.h>
#include <string>
#include "Ressource.hpp"

enum doc_type {PDF,DOC,PPT};

class Digital_Ressource : public Ressource{
	
public:
	Digital_Ressource();
	~Digital_Ressource();
	
	doc_type getType();
	int getSize();
	std::string getPath();
	
private:
	doc_type type;
	int size;
	std::string path;
	
};

#endif /* Digital_Ressource_hpp */
