#ifndef COMMAND_COMPONENT_H
#define COMMAND_COMPONENT_H

#include "../GenericECS/GenericComponent.h"

class CommandComponent : public GenericComponent
{
public:
    virtual ~CommandComponent() {}

    virtual unsigned char getKey() { return NULL; }

protected:
    CommandComponent() {}
};

#endif