#ifndef SUDOKU_MANAGER_H
#define SUDOKU_MANAGER_H

#include <stack>
#include <vector>

class Group;
class Options;

using namespace std;

class Manager
{
private:
    stack<Options*> options;
    bool inProgress = false;
    void Proccess();
public:
    void operator()(Options* opt);
};

#include "Options.h"
#include "Group.h"

#endif //SUDOKU_MANAGER_H
