#include "CommandSystem.h"
#include "../Systems/Scene_System.h"


void CommandSystem::Init()
{

}

void CommandSystem::Update(double dt)
{
    /*bool Application::IsKeyPressed(unsigned short key)
    {
        return ((GetAsyncKeyState(key) & 0x8001) != 0);
    }*/
}

void CommandSystem::Exit()
{
    for (auto it : allTheCommands_)
    {
        delete it;
        it = nullptr;
    }
    allTheCommands_.clear();
}

void CommandSystem::addCommands(GenericComponent &zeCommand)
{
    allTheCommands_.push_back(&zeCommand);
}

bool CommandSystem::isKeyPressed(unsigned short &key)
{
    //return ((GetAsyncKeyState(key) & 0x8001) != 0);
    return false;
}