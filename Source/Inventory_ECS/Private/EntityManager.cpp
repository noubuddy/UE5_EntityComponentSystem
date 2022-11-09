#include "EntityManager.h"

EntityManager::EntityManager()
{
	for (Entity entity = 0; entity < MAX_ENTITIES; ++entity)
	{
		AvailableEntities.push(entity);
	}
}

Entity EntityManager::CreateEntity()
{
	check(LivingEntityCount < MAX_ENTITIES);
	
	Entity id = AvailableEntities.front();
	AvailableEntities.pop();
	++LivingEntityCount;

	return id;
}

void EntityManager::DestroyEntity(Entity entity)
{
	check(entity < MAX_ENTITIES);
	
	Signatures[entity].reset();

	AvailableEntities.push(entity);
	--LivingEntityCount;
}

void EntityManager::SetSignature(Entity entity, Signature signature)
{
	check(entity < MAX_ENTITIES);

	Signatures[entity] = signature;
}

Signature EntityManager::GetSignature(Entity entity)
{
	check(entity < MAX_ENTITIES);

	return Signatures[entity];
}
