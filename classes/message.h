#ifndef _MESSAGE_H
#define _MESSAGE_H

#include <iostream>
#include <string>
#include<set>
#include "folder.h"




using namespace std;

class Folder; //forward declaration

class Message {

    friend class Folder;
    friend void swap(Message&, Message&);
    public:
       
       explicit Message(const std::string &str = ""): contents(str) {}
       Message(const Message&);
       Message& operator=(const Message&);
       ~Message();

       void save(Folder&);
       void remove(Folder&);

    private:
       string contents;
       std::set<Folder*> folders;
       void add_to_folders(const Message&);
       void remove_from_folders();

};
void swap(Message&, Message&); 

#endif //_FOLDER_H