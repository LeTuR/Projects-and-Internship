//
//  DVD.cpp
//  LibraryManager
//
//  Created by MagicLetur on 12/04/2018.
//  Copyright © 2018 Cesare-Herriau. All rights reserved.
//

#include "DVD.hpp"
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

DVD::DVD(){
	title = "Unknown";
	author = "Unknown";
	free = true;
	chapters = 0;
}

DVD::	DVD(std::string _title, std::string _author, std::string _duration, std::string _studio, int _chapters){
	title = _title;
	author = _author;
	free = true;
	duration = _duration;
	studio = _studio;
	chapters = _chapters;
}

					////////////////
					// Destructor //
					////////////////

DVD::~DVD(){
	
}

					//////////////
					// Accessor //
					//////////////

int DVD::getChapters(){
	return chapters;
}

					/////////////
					// Mutator //
					/////////////

					//////////
					// Else //
					//////////

void DVD::save(ofstream &saving){
    saving<<"VHS"<<"\n";
    Ressource::save(saving);
    saving<<duration<<"\n"<<studio<<"\n"<<chapters;
}

void DVD::display(){
	VHS::display();
	cout<<" "<<chapters;
}

string DVD::qDisplay(){
    return ("DVD\n"+Ressource::qDisplay() + "Duration: "+duration+"\n"+"Studio: "+studio+"\n"+"Chapters: "+to_string(chapters));
}

bool DVD::search(string searched) {
    if (VHS::search(searched)==true) return true;
    else if (to_string(chapters).find(searched)!=std::string::npos) return true;
    else return false;
}
