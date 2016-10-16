#ifndef FORWARD_COMMAND_H
#define FORWARD_COMMAND_H

#include "../GenericECS/GenericComponent.h"

class ForwardCommand : public GenericComponent
{
public:
    virtual ~ForwardCommand();
    static unsigned char theKey;

private:
    ForwardCommand();
    static ForwardCommand *zeCommand;
};

#endif