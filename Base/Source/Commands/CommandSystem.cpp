#include "CommandSystem.h"

void CommandSystem::Init()
{

}

void CommandSystem::Update(double dt)
{

}

void CommandSystem::Exit()
{
    for (auto it : allTheCommands_)
        delete it;
    allTheCommands_.clear();
}