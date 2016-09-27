#include "GenericComponent.h"

size_t GenericComponent::GenerateID()
{
    static size_t zeID = 0;
    assert(zeID < MAX_NUM_COMPONENTS);
    return zeID++;
}

GenericComponent::GenericComponent()
{
    GenericComponent("", nullptr);
}

GenericComponent::GenericComponent(const std::string &zeName, GenericEntity *zeOwner)
{
    setName(zeName);
    owner_of_component = zeOwner;
    id_ = GenerateID();
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

size_t GenericComponent::getID()
{
    return id_;
}

GenericEntity &GenericComponent::getOwner()
{
    return *owner_of_component;
}