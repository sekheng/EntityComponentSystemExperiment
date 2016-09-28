#include "GenericComponent.h"


GenericComponent::GenericComponent()
{
    GenericComponent("", nullptr);
}

GenericComponent::GenericComponent(const std::string &zeName, GenericEntity *zeOwner)
{
    setName(zeName);
    owner_of_component = zeOwner;
}

GenericComponent::~GenericComponent()
{
    owner_of_component = nullptr;
}

void GenericComponent::setName(const std::string zeName) 
{ 
    name_ = zeName; 
}

void GenericComponent::setEntityOwner(GenericEntity *zeOwner) 
{ 
    owner_of_component = zeOwner; 
}


std::string GenericComponent::getName()
{
    return name_;
}

GenericEntity &GenericComponent::getOwner()
{
    return *owner_of_component;
}