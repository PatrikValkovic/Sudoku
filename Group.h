#ifndef SUDOKU_GROUP_H
#define SUDOKU_GROUP_H

#include <set>

using namespace std;

class Options;

class Group
{
private:
    set<Options*> options;
public:
    void AddOption(Options* opt);
    void SetOptionAsResolved(Options* opt);
};

#include "Options.h"

#endif //SUDOKU_GROUP_H
