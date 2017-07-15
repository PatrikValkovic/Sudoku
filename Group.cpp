#include "Group.h"

void Group::AddOption(Options* opt)
{
    options.insert(opt);
    opt->AddGroup(this);
}

void Group::SetOptionAsResolved(Options* opt)
{
    for(Options* working : options)
        if(working != opt)
            working->RemoveOptions(opt->GetValue());
}
