//
//  Ressource.cpp
//  LibraryManager
//
//  Created by MagicLetur on 12/04/2018.
//  Copyright © 2018 Cesare-Herriau. All rights reserved.
//

#include "Ressource.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

					////////////////////
					// Initialization //
					////////////////////

int Ressource::id_counter = 0;
stack<int> Ressource::ids;

					/////////////////
					// Constructor //
					/////////////////

Ressource::Ressource(){
	title = "Unknown";
	author = "Unknown";
	free = true;
    visible = true;
	id = idSelect();
}

Ressource::Ressource(string _title, string _author){
	title = _title;
	author = _author;
	free = true;
}

					////////////////
					// Destructor //
					////////////////

Ressource::~Ressource(){
}

					//////////////
					// Accessor //
					//////////////

string Ressource::getTitle(){
	return title;
}

string Ressource::getAuthor(){
	return author;
}

int Ressource::getId(){
	return id;
}

bool Ressource::getDisponibility(){
	return free;
}

bool Ressource::getVisbility(){
    return visible;
}

					/////////////
					// Mutator //
					/////////////

void Ressource::setVisbility(bool a){
    visible = a;
}

void Ressource::setDisponibility(bool a){
    free = a;
}


					//////////
					// Else //
					//////////

int Ressource::idSelect(){
	int buff;
	if (ids.empty()){
		return (id_counter++);
	}
	else{
		buff = ids.top();
		ids.pop();
		return buff;
	}
	return 0;
}

void Ressource::save(ofstream &saving){
    if(free==true) saving<<title<<"\n"<<author<<"\n"<<"Available\n";
    else saving<<title<<"\n"<<author<<"\n"<<"Not Available\n";
}

void Ressource::display(){
	cout<<id<<" "<<title<<" "<<author<<" ";
}

string Ressource::qDisplay(){
    if(free==true){
    return "ID: "+to_string(id)+"\n"+"Title: "+title+"\n"+"Author: " +author+"\n"+"Available\n";
    }
    else{
        return "ID: "+to_string(id)+"\n"+"Title: "+title+"\n"+"Author: " +author+"\n"+"Not Available\n";
    }
}

bool Ressource::search(string searched) {
    if (title.find(searched)!=std::string::npos || author.find(searched)!=std::string::npos) return true;
    else return false;
}

void Ressource::saveID(){
    ids.push(id);
}
