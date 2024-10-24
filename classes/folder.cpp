#include "folder.h"
#include "message.h"  // Include Message to access the class

void Folder::addMsg(Message* m) {
    msgs.insert(m);
}

void Folder::remMsg(Message* m) {
    msgs.erase(m);
}
