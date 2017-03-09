#include "path.h"

path::path() :
    pth("/") { }

path::path(std::string path) :
    pth(path) {}

path::~path() { }

void path::addPart(std::string buffer) {
    if(buffer != "") {
        if(buffer == "..") {
            int j = pth.size() - 1;
            while(pth[j--] != '/' && j != -1) ;
                pth = (j != -1) ? pth.substr(0, j + 1) : "";
        }
        else
            pth += '/' + buffer;
    }
}

void path::add(std::string rel_path) {
    std::string buffer = "";
    int i = 0, j, buffer_length = 0, length = rel_path.size();
    while(length - i) {
        if(rel_path[i] != '/') {
            buffer += rel_path[i];
            ++buffer_length;
        }
        else {
            addPart(buffer);
            buffer = "";
            buffer_length = 0;
        }
        ++i;
    }
    addPart(buffer);
}
