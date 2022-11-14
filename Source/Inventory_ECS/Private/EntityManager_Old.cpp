#include "EntityManager_Old.h"

EntityManager_Old::EntityManager_Old()
{
	for (Entity entity = 0; entity < MAX_ENTITIES; ++entity)
	{
		AvailableEntities.push(entity);
	}
}

Entity EntityManager_Old::CreateEntity()
{
	check(LivingEntityCount < MAX_ENTITIES);
	
	Entity id = AvailableEntities.front();
	AvailableEntities.pop();
	++LivingEntityCount;

	return id;
}

void EntityManager_Old::DestroyEntity(Entity entity)
{
	check(entity < MAX_ENTITIES);
	
	Signatures[entity].reset();

	AvailableEntities.push(entity);
	--LivingEntityCount;
}

void EntityManager_Old::SetSignature(Entity entity, Signature signature)
{
	check(entity < MAX_ENTITIES);

	Signatures[entity] = signature;
}

Signature EntityManager_Old::GetSignature(Entity entity)
{
	check(entity < MAX_ENTITIES);

	return Signatures[entity];
}
