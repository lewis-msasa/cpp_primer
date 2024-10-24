#ifndef _FOLDER_H
#define _FOLDER_H


#include <iostream>
#include <string>
#include <set>
#include "message.h"

class Folder {
    friend class Message;
public:

private:
    std::set<Message*> msgs;

    void add_to_msgs(const Folder&);
    void remove_from_msgs();

    void addMsg(Message *m) { msgs.insert(m); }
    void remMsg(Message *m) { msgs.erase(m); }
};

#endif


