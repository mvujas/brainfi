#ifndef PATH_H
#define PATH_H
#include <bits/stdc++.h>

class path
{
    public:
        std::string pth;
        path();
        path(std::string path);
        virtual ~path();
        void add(std::string rel_path);
        void addPart(std::string buffer);

    protected:

    private:
};

#endif // PATH_H
