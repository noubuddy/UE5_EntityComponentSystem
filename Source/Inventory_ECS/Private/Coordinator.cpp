#include "Coordinator.h"

void Coordinator::Init()
{
	ComponentManager = std::make_unique<class ComponentManager>();
	EntityManager = std::make_unique<class EntityManager>();
	SystemManager = std::make_unique<class SystemManager>();
}

Entity Coordinator::CreateEntity()
{
	return EntityManager->CreateEntity();
}

void Coordinator::DestroyEntity(Entity entity)
{
	EntityManager->DestroyEntity(entity);

	ComponentManager->EntityDestroyed(entity);

	SystemManager->EntityDestroyed(entity);
}

template <typename T>
void Coordinator::RegisterComponent()
{
	ComponentManager->RegisterComponent<T>();
}

template <typename T>
void Coordinator::AddComponent(Entity entity, T component)
{
	ComponentManager->AddComponent<T>(entity, component);

	Signature signature = EntityManager->GetSignature(entity);
	signature.set(ComponentManager->GetComponentType<T>(), true);
	EntityManager->SetSignature(entity, signature);

	SystemManager->EntitySignatureChanged(entity, signature);
}

template <typename T>
void Coordinator::RemoveComponent(Entity entity)
{
	ComponentManager->RemoveComponent<T>(entity);

	Signature signature = EntityManager->GetSignature(entity);
	signature.set(ComponentManager->GetComponentType<T>(), false);
	EntityManager->SetSignature(entity, signature);

	SystemManager->EntitySignatureChanged(entity, signature);
}

template <typename T>
T &Coordinator::GetComponent(Entity entity)
{
	return ComponentManager->GetComponentType<T>(entity);
}

template <typename T>
ComponentType Coordinator::GetComponentType()
{
	return ComponentManager->GetComponentType<T>();
}

template <typename T>
std::shared_ptr<T> Coordinator::RegisterSystem()
{
	return SystemManager->SetSignature<T>();
}

template <typename T>
void Coordinator::SetSystemSignature(Signature Signature)
{
	SystemManager->SetSignature<T>(Signature);
}