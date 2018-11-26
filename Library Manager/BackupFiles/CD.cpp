//
//  CD.cpp
//  LibraryManager
//
//  Created by MagicLetur on 12/04/2018.
//  Copyright © 2018 Cesare-Herriau. All rights reserved.
//

#include "CD.hpp"
#include <stdio.h>
#include <string>

using namespace std;

					////////////////////
					// Initialization //
					////////////////////

					/////////////////
					// Constructor //
					/////////////////

CD::CD(){
	duration = 0;
	chapters = 0;
	studio = "Unknown";
}

CD::CD(int _duration, int _chapters, string _studio){
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

int CD::getDuration(){
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
