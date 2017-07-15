#ifndef SUDOKU_OPTIONS_H
#define SUDOKU_OPTIONS_H

#include <set>
#include <string>
#include <vector>
#include "Group.h"

using namespace std;

class Manager;

class Options
{
private:
    set<int> options;
    Manager* manager;
    set<Group*> groups;
public:
    Options();

    Options(const Options &second);

    Options& operator=(const Options &second) = delete;

    bool HaveValue();

    int GetValue();

    void RemoveOptions(int op);

    void SetValue(int val);

    bool HaveMoreWays();

    vector<int> GenerateWays();

    void AddManager(Manager* m);

    set<Group*> GetGroups();

    void AddGroup(Group* g);

    string Write();
};

#include "Manager.h"

#endif //SUDOKU_OPTIONS_H
