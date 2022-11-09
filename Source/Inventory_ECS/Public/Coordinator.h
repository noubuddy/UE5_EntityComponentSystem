#pragma once
#include "ComponentManager.h"
#include "EntityManager.h"
#include "SystemManager.h"
#include "Inventory_ECS/EcsMinimal.h"

class Coordinator
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
	std::unique_ptr<ComponentManager> ComponentManager;
	std::unique_ptr<EntityManager> EntityManager;
	std::unique_ptr<SystemManager> SystemManager;
};
