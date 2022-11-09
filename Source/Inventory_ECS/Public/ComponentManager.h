#pragma once
#include "ComponentArray.h"
#include "Inventory_ECS/EcsMinimal.h"

class ComponentManager
{
public:
	
	template <typename T>
	void RegisterComponent();

	template <typename T>
	ComponentType GetComponentType();

	template <typename T>
	void AddComponent(Entity entity, T component);

	template <typename T>
	void RemoveComponent(Entity entity);

	template <typename T>
	T &GetComponent(Entity entity);

	void EntityDestroyed(Entity entity);

private:
	std::unordered_map<const char *, ComponentType> ComponentTypes;

	std::unordered_map<const char *, std::shared_ptr<IComponentArray>> ComponentArrays;

	ComponentType NextComponentType;

	template <typename T>
	std::shared_ptr<ComponentArray<T>> GetComponentArray();
};
