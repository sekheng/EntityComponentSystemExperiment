/******************************************************************************/
/*!
\file           GenericEntity.h
\author      Lee Sek Heng
\par            email: 150629Z@mymail.nyp.edu.sg
\brief
A Generic Entity so that polymorphism will make life easier when all objects inheirits from it.
*/
/******************************************************************************/
#ifndef GENERIC_ENTITY_H
#define GENERIC_ENTITY_H

#include "..\\Misc\\DetectMemoryLeak.h"
#include "GenericComponent.h"
#include <string>

class GenericComponent;

/******************************************************************************/
/*!
Class GenericEntity:
\brief  Defines a GenericEntity and it's methods.
*/
/******************************************************************************/
class GenericEntity
{
public:
    GenericEntity();
    virtual ~GenericEntity();

    virtual bool onNotify(const std::string &zeEvent) { return false; };
    virtual bool onNotify(const int &zeEvent) { return false; };
    virtual bool onNotify(const float &zeEvent) { return false; };
    virtual bool onNotify(const double &zeEvent) { return false; };
    virtual bool onNotify(const GenericEntity &zeEvent) { return false; };

    std::string getName() { return name_; };
    void setName(const std::string &zeName) { name_ = zeName; };

protected:
    std::string name_;
    GenericComponent *ComponentsItHeld[GenericComponent::MAX_NUM_COMPONENTS];
};

#endif