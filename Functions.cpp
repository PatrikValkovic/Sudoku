#include "Functions.h"

class ToUse
{
public:
    vector<vector<Options*>> opts;
    int RowCoord;
    int ColumnRow;
    int val;
    vector<Group*> groups;
    Manager* man;

    ~ToUse()
    {
        ClearValues(opts, man, groups);
    }
};

bool SolveMoreResults(vector<vector<Options*>>& opts, vector<Group*>& groups, Manager*& man)
{
    bool repeat = true;
    stack<ToUse*> tries;

    //check if is full fill
    for (int i = 0; i < 9 && repeat; i++)
        for (int j = 0; j < 9 && repeat; j++)
            if (opts[i][j]->HaveMoreWays())
                repeat = false;
    if (repeat)
        return true;

    //find first field, that could be splited
    //WriteResult(opts);
    repeat = true;
    for (int i = 0; i < 9 && repeat; i++)
        for (int j = 0; j < 9 && repeat; j++)
            if (opts[i][j]->HaveMoreWays())
            {
                repeat = false;
                for (int wayVal : opts[i][j]->GenerateWays())
                {
                    ToUse* temp = new ToUse;
                    temp->RowCoord = i;
                    temp->ColumnRow = j;
                    temp->val = wayVal;
                    temp->opts = CopyField(opts, temp->man, temp->groups);
                    tries.push(temp);
                }
            }

    //try ways
    while (!tries.empty())
    {
        ToUse* currentTry = tries.top();
        tries.pop();

        try
        {
            currentTry->opts[currentTry->RowCoord][currentTry->ColumnRow]
                    ->SetValue(currentTry->val);

            //check if is full fill
            repeat = true;
            for (int i = 0; i < 9 && repeat; i++)
                for (int j = 0; j < 9 && repeat; j++)
                    if (currentTry->opts[i][j]->HaveMoreWays())
                        repeat = false;
            if (repeat)
            {
                ClearValues(opts, man, groups);
                //final solution
                opts = currentTry->opts;
                man = currentTry->man;
                groups = currentTry->groups;

                currentTry->groups.clear();
                currentTry->opts.clear();
                currentTry->man = nullptr;
                delete currentTry;
                for (; !tries.empty(); tries.pop())
                    delete tries.top();
                return true;
            }

            //find first field, that could be splited
            //WriteResult(currentTry->opts);
            repeat = true;
            for (int i = 0; i < 9 && repeat; i++)
                for (int j = 0; j < 9 && repeat; j++)
                    if (currentTry->opts[i][j]->HaveMoreWays())
                    {
                        repeat = false;
                        for (int wayVal : currentTry->opts[i][j]->GenerateWays())
                        {
                            ToUse* temp = new ToUse;
                            temp->RowCoord = i;
                            temp->ColumnRow = j;
                            temp->val = wayVal;
                            temp->opts = CopyField(currentTry->opts, temp->man, temp->groups);
                            tries.push(temp);
                        }
                    }
            delete currentTry;
        }
        catch (exception* e)
        {
            delete e;
            delete currentTry;
        }
    }
    return false;
}

void ClearValues(vector<vector<Options*>> opts, Manager* man, vector<Group*> groups)
{
    for (auto x : opts)
        for (auto y : x)
            delete y;
    for (auto x : groups)
        delete x;
    if (man != nullptr)
        delete man;
}

void WriteResult(vector<vector<Options*>> opts)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << opts[i][j]->Write() << (j == 8 ? '\n' : ' ');
    }
    cout << endl;
}

void WriteFinal(vector<vector<Options*>> opts)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << opts[i][j]->GetValue() << (j == 8 ? '\n' : ' ');
    }
}


void Parse(vector<vector<Options*>> opts)
{
    string x;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            cin >> x;
            if (x == "_")
                continue;
            opts[i][j]->SetValue(stoi(x));
        }
}

vector<Group*> createGroups(vector<vector<Options*>> opts)
{
    vector<Group*> groups;
    for (int i = 0; i < 9; i++)
    {
        Group* newOne = new Group;
        for (int j = 0; j < 9; j++)
            newOne->AddOption(opts[i][j]);
        groups.push_back(newOne);
    }

    for (int i = 0; i < 9; i++)
    {
        Group* newOne = new Group;
        for (int j = 0; j < 9; j++)
            newOne->AddOption(opts[j][i]);
        groups.push_back(newOne);
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            Group* newOne = new Group;
            for (int k = i * 3; k < i * 3 + 3; k++)
                for (int l = j * 3; l < j * 3 + 3; l++)
                    newOne->AddOption(opts[k][l]);
            groups.push_back(newOne);
        }


    return groups;
}

vector<vector<Options*>> CreateContainer(Manager* manager)
{
    vector<vector<Options*>> toReturn;
    for (int i = 0; i < 9; i++)
    {
        vector<Options*> created;
        for (int j = 0; j < 9; j++)
        {
            Options* opt = new Options;
            opt->AddManager(manager);
            created.push_back(opt);
        }
        toReturn.push_back(created);
    }
    return toReturn;
}

vector<vector<Options*>> CopyField(vector<vector<Options*>> original,
                                   Manager*& man,
                                   vector<Group*>& groups)
{
    vector<vector<Options*>> copy;
    man = new Manager;
    for (int i = 0; i < 9; i++)
    {
        vector<Options*> created;
        for (int j = 0; j < 9; j++)
        {
            Options* opt = new Options(*original[i][j]);
            opt->AddManager(man);
            created.push_back(opt);
        }
        copy.push_back(created);
    }

    groups = createGroups(copy);

    return copy;
}
