//
//  Commands.hpp
//  LibraryManager
//
//  Created by MagicLetur on 25/04/2018.
//  Copyright © 2018 Cesare-Herriau. All rights reserved.
//

#ifndef Commands_hpp
#define Commands_hpp


#include "Commands.hpp"
#include "Ressource.hpp"
#include "Book.hpp"
#include "CD.hpp"
#include "Digital_Ressource.hpp"
#include "VHS.hpp"
#include "Magazine.hpp"
#include "DVD.hpp"
#include "Library.hpp"

#include <stdio.h>
#include <string>

void add(Library *l, std::string type);
int qLoad(Library *l, std::string path);
void show(Library *l, int id);
std::string qShow(Library *l, int id);
std::string qRent(Library *l, int id);
std::string qGiveBack(Library *l, int id);
int qSave(Library *l, std::string filename);
std::string qList(Library *l);
void resetLib(Library *l);
std::string qDelete(Library *l, int id);
void qSearch(Library *l, std::string searched);

#endif /* Commands_hpp */
