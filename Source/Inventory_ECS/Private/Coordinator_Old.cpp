#include "Coordinator_Old.h"

void Coordinator_Old::Init()
{
	ComponentManager = std::make_unique<class ComponentManager_Old>();
	EntityManager = std::make_unique<class EntityManager_Old>();
	SystemManager = std::make_unique<class SystemManager_Old>();
}

Entity Coordinator_Old::CreateEntity()
{
	return EntityManager->CreateEntity();
}

void Coordinator_Old::DestroyEntity(Entity entity)
{
	EntityManager->DestroyEntity(entity);

	ComponentManager->EntityDestroyed(entity);

	SystemManager->EntityDestroyed(entity);
}

template <typename T>
void Coordinator_Old::RegisterComponent()
{
	ComponentManager->RegisterComponent<T>();
}

template <typename T>
void Coordinator_Old::AddComponent(Entity entity, T component)
{
	ComponentManager->AddComponent<T>(entity, component);

	Signature signature = EntityManager->GetSignature(entity);
	signature.set(ComponentManager->GetComponentType<T>(), true);
	EntityManager->SetSignature(entity, signature);

	SystemManager->EntitySignatureChanged(entity, signature);
}

template <typename T>
void Coordinator_Old::RemoveComponent(Entity entity)
{
	ComponentManager->RemoveComponent<T>(entity);

	Signature signature = EntityManager->GetSignature(entity);
	signature.set(ComponentManager->GetComponentType<T>(), false);
	EntityManager->SetSignature(entity, signature);

	SystemManager->EntitySignatureChanged(entity, signature);
}

template <typename T>
T &Coordinator_Old::GetComponent(Entity entity)
{
	return ComponentManager->GetComponentType<T>(entity);
}

template <typename T>
ComponentType Coordinator_Old::GetComponentType()
{
	return ComponentManager->GetComponentType<T>();
}

template <typename T>
std::shared_ptr<T> Coordinator_Old::RegisterSystem()
{
	return SystemManager->SetSignature<T>();
}

template <typename T>
void Coordinator_Old::SetSystemSignature(Signature Signature)
{
	SystemManager->SetSignature<T>(Signature);
}