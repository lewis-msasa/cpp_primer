#ifndef _MESSAGE_H
#define _MESSAGE_H

#include <iostream>
#include <string>
#include<set>
#include "folder.h"




using namespace std;



class Message {

    friend class Folder;
    public:
       friend void swap(Message&, Message&);
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


#endif //_FOLDER_H