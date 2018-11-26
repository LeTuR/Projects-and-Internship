//
//  Digital_Ressource.cpp
//  LibraryManager
//
//  Created by MagicLetur on 12/04/2018.
//  Copyright © 2018 Cesare-Herriau. All rights reserved.
//

#include "Digital_Ressource.hpp"
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


Digital_Ressource::Digital_Ressource(){
	title = "Unknown";
	author = "Unknown";
	free = true;
	title = "Unknown";
	author = "Unknown";
	free = true;
    type = "";
	size = 0;
	path = "Unknown";
}

Digital_Ressource::Digital_Ressource(string _title, string _author, string _type, int _size, string _path){
	title = _title;
	author = _author;
	free = true;
	type = _type;
	size = _size;
	path = _path;
}

					////////////////
					// Destructor //
					////////////////

Digital_Ressource::~Digital_Ressource(){
	
}


					//////////////
					// Accessor //
					//////////////


string Digital_Ressource::getType(){
	return type;
}

int Digital_Ressource::getSize(){
	return size;
}

string Digital_Ressource::getPath(){
	return path;
}

					/////////////
					// Mutator //
					/////////////

					//////////
					// Else //
					//////////

void Digital_Ressource::save(ofstream &saving){
    saving<<"Digital_Ressource"<<"\n";
    Ressource::save(saving);
    saving<<type<<"\n"<<size<<"\n"<<path;
}

void Digital_Ressource::display(){
	Ressource::display();
    cout<<type<<" "<<size<<" "<<path;
}

string Digital_Ressource::qDisplay(){
    return ("DIGITAL RESSOURCE\n"+Ressource::qDisplay() + "Extention: "+type+"\n"+"Size: "+to_string(size)+"\n"+"Path: "+path+"\n");
}

bool Digital_Ressource::search(string searched) {
    if (Ressource::search(searched)==true) return true;
    if (type.find(searched)!=std::string::npos || to_string(size).find(searched)!=std::string::npos
             || path.find(searched)!=std::string::npos) return true;
    else return false;
}
