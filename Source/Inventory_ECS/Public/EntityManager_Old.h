#pragma once

#include <queue>
#include <array>
#include "Inventory_ECS/EcsMinimal_Old.h"

class EntityManager_Old
{
public:
	EntityManager_Old();

	Entity CreateEntity();

	void DestroyEntity(Entity entity);

	void SetSignature(Entity entity, Signature signature);

	Signature GetSignature(Entity entity);


private:
	std::queue<Entity> AvailableEntities;

	std::array<Signature, MAX_ENTITIES> Signatures;

	uint32_t LivingEntityCount;
};
