#include "ForwardCommand.h"
#include "../Commands/CommandSystem.h"

unsigned char ForwardCommand::theKey = 'W';
ForwardCommand *ForwardCommand::zeCommand = new ForwardCommand();

ForwardCommand::ForwardCommand()
: CommandComponent()
{
    name_ = "Move Forward";
    CommandSystem::accessing().addCommands(*this);
}

ForwardCommand::~ForwardCommand()
{

}

unsigned char ForwardCommand::getKey()
{
    return theKey;
}