#pragma once

#include <array>
#include "Inventory_ECS/EcsMinimal.h"

class IComponentArray
{
public:
	virtual ~IComponentArray() = default;
	virtual void EntityDestroyed(Entity entity) = 0;
};

template <typename T>
class TComponentArray : public IComponentArray
{
public:
	void InsertData(Entity entity, T component);

	void RemoveData(Entity entity);

	T &GetData(Entity entity);

	virtual void EntityDestroyed(Entity entity) override;

private:
	std::array<T, MAX_ENTITIES> ComponentArray;

	std::unordered_map<Entity, size_t> EntityToIndexMap;

	std::unordered_map<size_t, Entity> IndexToEntityMap;

	size_t Size;
};
