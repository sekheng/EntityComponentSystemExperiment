#ifndef COMMAND_SYSTEM_H
#define COMMAND_SYSTEM_H

#include "../GenericECS/GenericSystem.h"
#include "../Classes/singletontemplate.h"
#include <vector>
#include "GenericCommand.h"

class CommandSystem : public GenericSystem, public SingletonTemplate<CommandSystem>
{
public:
    virtual void Init();
    virtual void Update(double dt);
    virtual void Exit();

private:
    std::vector<GenericCommand*> allTheCommands_;
};

#endif