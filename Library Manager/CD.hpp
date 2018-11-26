//
//  CD.hpp
//  LibraryManager
//
//  Created by MagicLetur on 12/04/2018.
//  Copyright © 2018 Cesare-Herriau. All rights reserved.
//

#ifndef CD_hpp
#define CD_hpp

#include <iostream>
#include <string>
#include "Ressource.hpp"


class CD : public Ressource{

private:
    std::string duration;
	int chapters;
	std::string studio;
	
public:
	CD();
    CD(std::string _title, std::string _author, std::string _duration, std::string _studio, int _chapters);
    CD(int _duration, std::string _studio, int _chapters);
	~CD();

    virtual void save(std::ofstream &saving);
    virtual void display();
    virtual std::string qDisplay();
    virtual bool search(std::string searched);

    std::string getDuration();
	int getChapters();
	std::string getStudio();
	

};

#endif /* CD_hpp */
