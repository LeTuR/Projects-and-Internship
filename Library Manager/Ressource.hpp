//
//  Ressource.hpp
//  LibraryManager
//
//  Created by MagicLetur on 12/04/2018.
//  Copyright © 2018 Cesare-Herriau. All rights reserved.
//

#ifndef Ressource_hpp
#define Ressource_hpp

#include <iostream>
#include <string>
#include <stack>

class Ressource{

public:
	static int id_counter;
	static std::stack<int> ids;
protected:
	std::string title;
	std::string author;
	int id;
    bool free;
    bool visible;

public:
	Ressource();
	Ressource(std::string _title, std::string _author);
	~Ressource();

	virtual void save(std::ofstream &saving);
	virtual void display();
    virtual std::string qDisplay();
    virtual bool search(std::string searched);
	int idSelect();
    void saveID();

	
	std::string getTitle();
	std::string getAuthor();
	bool getDisponibility();
    bool getVisbility();
	int getId();

    void setDisponibility(bool a);
    void setVisbility(bool a);
};

#endif /* Ressource_hpp */
