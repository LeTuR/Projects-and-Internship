//
//  Magazine.hpp
//  LibraryManager
//
//  Created by MagicLetur on 12/04/2018.
//  Copyright © 2018 Cesare-Herriau. All rights reserved.
//

#ifndef Magazine_hpp
#define Magazine_hpp

#include <stdio.h>
#include <string>
#include "Book.hpp"

class Magazine : public Book{
	
public:
	
	Magazine();
	Magazine(std::string _editor, int _articles);
	~Magazine();
	
	std::string getEditors();
	int getArticles();
	
private:
	std::string editor;
	int articles;
	
};

#endif /* Magazine_hpp */
