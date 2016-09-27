#include "GenericEntity.h"

GenericEntity::GenericEntity()
{
    name_ = "";
    for (size_t num = 0; num < MAX_NUM_COMPONENTS; ++num)
        ComponentsItHeld[num] = nullptr;
}

GenericEntity::~GenericEntity()
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