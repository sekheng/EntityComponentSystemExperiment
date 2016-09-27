#include "MeshComponent.h"
#include "../Systems/ComponentSystem.h"

MeshComponent *MeshComponent::toRegisterItselfToComponentSystem = new MeshComponent();

MeshComponent::MeshComponent()
{
    if (toRegisterItselfToComponentSystem)
    {
        ComponentSystem::accessing().addingComponents(toRegisterItselfToComponentSystem);
    }
}

MeshComponent::~MeshComponent()
{

}
