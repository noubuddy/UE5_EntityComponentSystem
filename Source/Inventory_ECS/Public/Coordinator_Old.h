#pragma once
#include "ComponentManager_Old.h"
#include "EntityManager_Old.h"
#include "SystemManager_Old.h"
#include "Inventory_ECS/EcsMinimal_Old.h"

class Coordinator_Old
{
public:
	void Init();

	Entity CreateEntity();

	void DestroyEntity(Entity entity);

	template <typename T>
	void RegisterComponent();

	template <typename T>
	void AddComponent(Entity entity, T component);

	template <typename T>
	void RemoveComponent(Entity entity);

	template <typename T>
	T &GetComponent(Entity entity);

	template <typename T>
	ComponentType GetComponentType();

	template <typename T>
	std::shared_ptr<T> RegisterSystem();

	template <typename T>
	void SetSystemSignature(Signature Signature);

private:
	std::unique_ptr<ComponentManager_Old> ComponentManager;
	std::unique_ptr<EntityManager_Old> EntityManager;
	std::unique_ptr<SystemManager_Old> SystemManager;
};
