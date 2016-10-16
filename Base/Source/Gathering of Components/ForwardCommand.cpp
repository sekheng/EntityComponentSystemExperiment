#include "ForwardCommand.h"
#include "../Commands/CommandSystem.h"

unsigned char ForwardCommand::theKey = 'W';
ForwardCommand *ForwardCommand::zeCommand = new ForwardCommand();

ForwardCommand::ForwardCommand()
: GenericComponent()
{
    name_ = "Move Forward";
    CommandSystem::accessing().addCommands(*this);
}

ForwardCommand::~ForwardCommand()
{

}