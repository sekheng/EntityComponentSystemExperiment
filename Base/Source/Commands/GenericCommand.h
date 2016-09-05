#ifndef GENERIC_COMMAND_H
#define GENERIC_COMMAND_H

#include "../GenericECS/GenericEntity.h"

class GenericCommand : protected GenericEntity
{
public:
    virtual ~GenericCommand() {}

protected:
};

#endif