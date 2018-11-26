//
//  DVD.cpp
//  LibraryManager
//
//  Created by MagicLetur on 12/04/2018.
//  Copyright © 2018 Cesare-Herriau. All rights reserved.
//

#include "DVD.hpp"
#include <stdio.h>
#include <string>

using namespace std;

					////////////////////
					// Initialization //
					////////////////////

					/////////////////
					// Constructor //
					/////////////////

DVD::DVD(){
	chapters = 0;
}

DVD::DVD(int _chapters){
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
