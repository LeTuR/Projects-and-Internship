//
//  Commands.cpp
//  LibraryManager
//
//  Created by MagicLetur on 25/04/2018.
//  Copyright © 2018 Cesare-Herriau. All rights reserved.
//

#include "Commands.hpp"
#include "Ressource.hpp"
#include "Book.hpp"
#include "CD.hpp"
#include "Digital_Ressource.hpp"
#include "VHS.hpp"
#include "Magazine.hpp"
#include "DVD.hpp"
#include "Library.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*---------------------qSearch-----------------------------*/

void qSearch(Library *l, string searched){
    for(vector<Ressource*>::iterator it=l->listRessources.begin(); it!=l->listRessources.end(); it++){
        if ((*it)->search(searched)==false){
            (*it)->setVisbility(false);
        }
    }
}

/*---------------------qRent-----------------------------*/
string qRent(Library *l, int id){
    if ((l->listRessources)[id]->getId()==id){
        if ((l->listRessources)[id]->getDisponibility()==true){
            ((l->listRessources)[id])->setDisponibility(false);
            return "You rented the ressource!";
        }
        else
            return "You can't rent the Ressource!";
    }
    else{
        for(vector<Ressource*>::iterator it=l->listRessources.begin(); it!=l->listRessources.end(); it++){
            if (((*it)->getId())==id){
                if ((*it)->getDisponibility()==true){
                    ((l->listRessources)[id])->setDisponibility(false);
                    return "You rented the ressource!";
                }
                else
                    return "You can't rent the Ressource!";
            }
         }
    }
    return ("This ID doesn't exist.");
}

/*---------------------qGiveBack-----------------------------*/
string qGiveBack(Library *l, int id){
    if ((l->listRessources)[id]->getId()==id){
        if ((l->listRessources)[id]->getDisponibility()==false){
            ((l->listRessources)[id])->setDisponibility(true);
            return "You gave back the ressource!";
        }
        else
            return "You already gave back the Ressource!";
    }
    else{
        for(vector<Ressource*>::iterator it=l->listRessources.begin(); it!=l->listRessources.end(); it++){
            if (((*it)->getId())==id){
                if ((*it)->getDisponibility()==true){
                    ((l->listRessources)[id])->setDisponibility(false);
                    return "You gave back the ressource!";
                }
                else
                    return "You already gave back the Ressource!";
            }
         }
    }
    return ("This ID doesn't exist.");
}

/*---------------------qShow-----------------------------*/

string qShow(Library *l, int id){
    if ((l->listRessources)[id]->getId()==id){
        return((l->listRessources)[id])->qDisplay();
    }
    else{
        for(vector<Ressource*>::iterator it=l->listRessources.begin(); it!=l->listRessources.end(); it++){
            if (((*it)->getId())==id) return (*it)->qDisplay();
        }
    }
    return ("This ID doesn't exist.");
}

/*--------------------------------qload-----------------------------*/

int qLoad(Library *l, string path){
    string const loadfile(path);
    ifstream loading(loadfile.c_str());
    if (loading){
        l->clearID();
        l->listRessources.clear();
        string type;
        string title;
        string author;
        //Book and Magazine
        int pages;
        string publication;
        string collection;
        string summary;
        string editor;
        int articles;
        //CD
        string duration;
        int chapters;
        string studio;
        //Digital_ressource
        string doc_type;
        int size;
        string path;
        string line;
        bool free;
        //VHS and DVD
        while(getline(loading, line)){
            //RESSOURCE
            type=line;
            getline(loading, line);title=line;
            getline(loading, line);author=line;
            getline(loading, line);
            if (std::strcmp(line.c_str(),"Available")==0) free=true;
            else free=false;
            //BOOK
            if (type == "Book" or type == "Magazine"){
                getline(loading, line);pages=stoi(line);
                getline(loading, line);publication=line;
                getline(loading, line);collection=line;
                getline(loading, line);summary=line;
                //MAGAZINE
                if(type == "Magazine"){
                    getline(loading, line);editor=line;
                    getline(loading, line);articles=stoi(line);
                    Magazine *r = new Magazine(title, author, pages, publication, collection, summary, editor, articles);
                    r->setDisponibility(free);
                    l->addRessource(r);
                }
                else{
                    Book *r = new Book(title, author, pages, publication, collection, summary);
                    r->setDisponibility(free);
                    l->addRessource(r);
                }
            }

            //DIGITAL RESSOURCE
            else if (type == "Digital_Ressource"){
                getline(loading, line);doc_type=line;
                getline(loading, line);size=stoi(line);
                getline(loading, line);path=line;
                Digital_Ressource *r = new Digital_Ressource(title, author, doc_type, size, path);
                r->setDisponibility(free);
                l->addRessource(r);
            }

            else if ((type == "VHS") or (type == "DVD")){
                getline(loading, line);duration=line;
                getline(loading, line);studio=line;
                if (type == "DVD"){
                    getline(loading, line);chapters=stoi(line);
                    DVD *r = new DVD(title, author, duration, studio, chapters);
                    r->setDisponibility(free);
                    l->addRessource(r);
                }
                VHS *r = new VHS(title, author, duration, studio);
                r->setDisponibility(free);
                l->addRessource(r);
            }
            else if (type == "CD"){
                getline(loading, line);duration=line;
                getline(loading, line);studio=line;
                getline(loading, line);chapters=stoi(line);
                CD *r = new CD(title, author, duration, studio, chapters);
                r->setDisponibility(free);
                l->addRessource(r);
            }
        }
        return 0;
    }
    else{
        return 1;
    }
    loading.close();
}

/*-------------------------------------qSave---------------------------------*/

int qSave(Library *l, string filename){

    ofstream saving(filename, ios::out | ios::trunc);
    if(saving)
    {
        for(vector<Ressource*>::iterator it=l->listRessources.begin(); it!=l->listRessources.end(); it++){
            (*it)->save(saving);
            saving<<"\n";
        }
        saving.close();
        return 0;
    }

    else
        return 1;
}

/*--------------------------------------qList-------------------------------------*/

string qList(Library *l){
    string buff;
    for(vector<Ressource*>::iterator it=l->listRessources.begin(); it!=l->listRessources.end(); it++){
        if(((*it)->getVisbility())==true){
            buff = buff + (*it)->qDisplay() + "\n" + "--------------------------\n";
        }
    }
    return buff;
}
/*---------------------------------reset-----------------------------------------*/

void resetLib(Library *l){
    for(vector<Ressource*>::iterator it=l->listRessources.begin(); it!=l->listRessources.end(); it++){
        (*it)->setVisbility(true);
    }
}
/*---------------------------------qDelete-----------------------------------------*/
string qDelete(Library *l, int id){
    for(vector<Ressource*>::iterator it=l->listRessources.begin(); it!=l->listRessources.end(); it++){
        if (((*it)->getId())==id){
            if (it==l->listRessources.end()){
                (*it)->saveID();
                (l->listRessources).pop_back();
                return "ID erased";
            }
            else{
                (*it)->saveID();
                (l->listRessources).erase(it);
                return "ID erased";
            }
        }
    }
return ("This ID doesn't exist.");
}
