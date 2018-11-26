//
//  CD.cpp
//  LibraryManager
//
//  Created by MagicLetur on 12/04/2018.
//  Copyright © 2018 Cesare-Herriau. All rights reserved.
//

#include "CD.hpp"
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

CD::CD(){
	title = "Unknown";
	author = "Unknown";
	free = true;
    duration = "00:00";
	chapters = 0;
	studio = "Unknown";
}

CD::CD(string _title, string _author, string _duration, string _studio, int _chapters){
	title = _title;
	author = _author;
	free = true;
	duration = _duration;
	chapters = _chapters;
	studio = _studio;
}

					////////////////
					// Destructor //
					////////////////
CD::~CD(){
	
}
					//////////////
					// Accessor //
					//////////////

string CD::getDuration(){
	return duration;
}
int CD::getChapters(){
	return chapters;
}
string CD::getStudio(){
	return studio;
}

					/////////////
					// Mutator //
					/////////////

					//////////
					// Else //
					//////////

void CD::save(ofstream &saving){
    saving<<"CD"<<"\n";
    Ressource::save(saving);
    saving<<duration<<"\n"<<studio<<"\n"<<chapters;
}

void CD::display(){
	Ressource::display();
	cout<<duration<<" "<<chapters<<" "<<studio;
}

string CD::qDisplay(){
    return ("CD\n"+Ressource::qDisplay() + "Duration: "+duration+"\n"+"Studio: "+studio+"\n"+"Chapters: "+to_string(chapters));
}

bool CD::search(string searched) {
    if (Ressource::search(searched)==true) return true;
    else if (duration.find(searched)!=std::string::npos || studio.find(searched)!=std::string::npos
             || to_string(chapters).find(searched)!=std::string::npos) return true;
    else return false;
}
