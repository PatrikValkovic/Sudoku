#include <iostream>

#include "Group.h"
#include "Functions.h"

using namespace std;

int main()
{

    Manager* man = new Manager;

    vector<vector<Options*>> opts = CreateContainer(man);

    vector<Group*> groups = createGroups(opts);

    int endResult = 0;
    try
    {
        Parse(opts);

        if(!SolveMoreResults(opts,groups,man))
            throw new exception();

        WriteFinal(opts);
    }
    catch (std::exception* e)
    {
        cout << "Nema reseni";
        endResult = 1;
    }

    ClearValues(opts,man,groups);

    return endResult;
}

