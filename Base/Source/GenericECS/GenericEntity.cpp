#include "GenericEntity.h"

GenericEntity::GenericEntity()
{
    Init();
}

GenericEntity::~GenericEntity()
{
    Exit();
}

bool GenericEntity::addComponent(const size_t &zeCompID, GenericComponent *zeComponent)
{
#ifdef _DEBUG
    assert(!ComponentsItHeld[zeCompID]);
#endif
    if (!ComponentsItHeld[zeCompID])
    {
        ComponentsItHeld[zeCompID] = zeComponent;
        zeComponent->setEntityOwner(this);
        zeComponent->Init();
        return true;
    }
    return false;
}

GenericComponent &GenericEntity::getComponent(const size_t &zeNum)
{
#ifdef _DEBUG
    assert(zeNum < MAX_NUM_COMPONENTS);
#endif
    return *ComponentsItHeld[zeNum];
}

void GenericEntity::Init()
{
    name_ = "";
    for (size_t num = 0; num < MAX_NUM_COMPONENTS; ++num)
        ComponentsItHeld[num] = nullptr;
}

void GenericEntity::Update(double dt)
{
    for (size_t num = 0; num < MAX_NUM_COMPONENTS; ++num)
    {
        if (ComponentsItHeld[num])
            ComponentsItHeld[num]->Update(dt);
    }
}

void GenericEntity::Exit()
{
    for (size_t num = 0; num < MAX_NUM_COMPONENTS; ++num)
    {
        if (ComponentsItHeld[num])
        {
            delete ComponentsItHeld[num];
            ComponentsItHeld[num] = nullptr;
        }
    }
}