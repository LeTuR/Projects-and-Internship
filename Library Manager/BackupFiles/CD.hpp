//
//  CD.hpp
//  LibraryManager
//
//  Created by MagicLetur on 12/04/2018.
//  Copyright © 2018 Cesare-Herriau. All rights reserved.
//

#ifndef CD_hpp
#define CD_hpp

#include <stdio.h>
#include <string>
#include "Ressource.hpp"


class CD : public Ressource{

private:
	int duration;
	int chapters;
	std::string studio;
	
public:
	CD();
	CD(int _duration, int _chapters, std::string _studio);
	~CD();
	int getDuration();
	int getChapters();
	std::string getStudio();
	

};

#endif /* CD_hpp */
