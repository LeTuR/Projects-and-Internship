//
//  VHS.cpp
//  LibraryManager
//
//  Created by MagicLetur on 12/04/2018.
//  Copyright © 2018 Cesare-Herriau. All rights reserved.
//

#include "VHS.hpp"
#include <stdio.h>
#include <string>

using namespace std;

					////////////////////
					// Initialization //
					////////////////////

					/////////////////
					// Constructor //
					/////////////////

VHS::VHS(){
	duration = 0;
	studio = "Unknown";
}

VHS::VHS(int _duration, string _studio){
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

int VHS::getDuration(){
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
