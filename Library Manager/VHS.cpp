//
//  VHS.cpp
//  LibraryManager
//
//  Created by MagicLetur on 12/04/2018.
//  Copyright © 2018 Cesare-Herriau. All rights reserved.
//

#include "VHS.hpp"
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

VHS::VHS(){
	title = "Unknown";
	author = "Unknown";
	free = true;
    duration = "00:00";
	studio = "Unknown";
}

VHS::VHS(string _title, string _author, string _duration, string _studio){
	title = _title;
	author = _author;
	free = true;
	duration = _duration;
	studio = _studio;
}

					////////////////
					// Destructor //
					////////////////

VHS::~VHS(){
	
}

					//////////////
					// Accessor //
					//////////////

string VHS::getDuration(){
	return duration;
}

string VHS::getStudio(){
	return studio;
}

					/////////////
					// Mutator //
					/////////////

					//////////
					// Else //
					//////////

void VHS::save(ofstream &saving){
    saving<<"VHS"<<"\n";
    Ressource::save(saving);
    saving<<duration<<"\n"<<studio;
}

void VHS::display(){
	Ressource::display();
	cout<<duration<<" "<<studio;
}

string VHS::qDisplay(){
    return ("VHS\n"+ Ressource::qDisplay() + "Duration: "+duration+"\n"+"Studio: "+studio+"\n");
}

bool VHS::search(string searched) {
    if (Ressource::search(searched)==true) return true;
    else if (duration.find(searched)!=std::string::npos || studio.find(searched)!=std::string::npos) return true;
    else return false;
}
