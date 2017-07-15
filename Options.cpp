#include "Options.h"


Options::Options()
{
    for (int i = 1; i <= 9; i++)
        options.insert(i);
}

bool Options::HaveValue()
{
    return options.size() == 1;
}

int Options::GetValue()
{
    if (!HaveValue())
        throw new std::exception();
    return *options.begin();
}

void Options::RemoveOptions(int op)
{
    if (HaveValue() && GetValue() == op)
        throw new exception();

    if (HaveValue())
        return;

    options.erase(op);
    if (HaveValue())
        SetValue(GetValue());
}

void Options::SetValue(int val)
{
    options.clear();
    options.insert(val);

    (*manager)(this);
}

void Options::AddManager(Manager* m)
{
    this->manager = m;
}

set<Group*> Options::GetGroups()
{
    return this->groups;
}

void Options::AddGroup(Group* g)
{
    groups.insert(g);
}

string Options::Write()
{
    string temp;
    if (options.size() == 1)
        temp = to_string(GetValue());
    else
    {
        temp = "{";
        for (int opt : options)
            temp += to_string(opt);
        temp += "}";
    }
    temp.resize(11, ' ');
    return temp;
}

Options::Options(const Options& second) : options(second.options)
{}

bool Options::HaveMoreWays()
{
    return options.size() > 1;
}

vector<int> Options::GenerateWays()
{
    vector<int> ways;
    for(int i : options)
    {
        ways.push_back(i);
    }
    return ways;
}
