#ifndef SUDOKU_FUNCTIONS_H
#define SUDOKU_FUNCTIONS_H

#include <vector>
#include <iostream>
#include "Manager.h"

class Options;

class Group;

class Manager;

using namespace std;

void Parse(vector<vector<Options*>>);

void WriteResult(vector<vector<Options*>>);

void WriteFinal(vector<vector<Options*>>);

vector<Group*> createGroups(vector<vector<Options*>>);

vector<vector<Options*>> CreateContainer(Manager* manager);

bool SolveMoreResults(vector<vector<Options*>>& opts,
                      vector<Group*>& groups,
                      Manager*& man);

vector<vector<Options*>> CopyField(vector<vector<Options*>> original,
                                   Manager*& man,
                                   vector<Group*>& groups);

void ClearValues(vector<vector<Options*>> opts, Manager* man, vector<Group*> groups);

#include "Options.h"
#include "Group.h"
#include "Manager.h"

#endif //SUDOKU_FUNCTIONS_H
