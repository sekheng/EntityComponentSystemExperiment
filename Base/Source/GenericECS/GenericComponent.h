#ifndef GENERIC_COMPONENT_H
#define GENERIC_COMPONENT_H

#include <string>
#include "GenericEntity.h"
#include "../Systems/ComponentSystem.h"
#ifdef _DEBUG
#include <assert.h>
#endif
class GenericEntity;


class GenericComponent
{
public:
    GenericComponent();
    GenericComponent(const std::string &zeName, GenericEntity *zeOwner);
    virtual ~GenericComponent();

    void setName(const std::string zeName);
    void setEntityOwner(GenericEntity *zeOwner);

    virtual bool onNotify(const std::string &zeEvent) { return false; };
    virtual bool onNotify(const int &zeEvent) { return false; };
    virtual bool onNotify(const float &zeEvent) { return false; };
    virtual bool onNotify(const double &zeEvent) { return false; };
    virtual bool onNotify(const GenericComponent &zeEvent) { return false; };

    std::string getName();
    GenericEntity &getOwner();

protected:
    std::string name_;
    GenericEntity *owner_of_component;
};

#endif