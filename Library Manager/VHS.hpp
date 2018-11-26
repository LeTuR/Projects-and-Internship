//
//  VHS.hpp
//  LibraryManager
//
//  Created by MagicLetur on 12/04/2018.
//  Copyright © 2018 Cesare-Herriau. All rights reserved.
//

#ifndef VHS_hpp
#define VHS_hpp

#include <iostream>
#include <string>
#include "Ressource.hpp"

class VHS : public Ressource{

protected:
    std::string duration;
	std::string studio;
	
public:
	VHS();
    VHS(std::string _title, std::string _author, std::string _duration, std::string _studio);
    VHS(std::string _duration, std::string _studio);
	~VHS();

	virtual void save(std::ofstream &saving);
	virtual void display();
    virtual std::string qDisplay();
    virtual bool search(std::string searched);

    std::string getDuration();
	std::string getStudio();
};

#endif /* VHS_hpp */
