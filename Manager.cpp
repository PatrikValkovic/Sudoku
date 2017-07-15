#include "Manager.h"

void Manager::operator()(Options* opt)
{
    if (!inProgress)
    {
        options.push(opt);
        Proccess();
    }
    else
    {
        options.push(opt);
    }
}

void Manager::Proccess()
{
    inProgress = true;
    while(!options.empty())
    {
        Options* opt = options.top();
        options.pop();
        if(!opt->HaveValue())
            continue;
        for(Group* g : opt->GetGroups())
                g->SetOptionAsResolved(opt);
    }
    inProgress = false;
}
