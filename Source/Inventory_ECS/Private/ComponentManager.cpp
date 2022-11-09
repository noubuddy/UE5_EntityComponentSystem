#include "ComponentManager.h"

template <typename T>
void ComponentManager::RegisterComponent()
{
	const char *TypeName = typeid(T).name();

	check(ComponentTypes.find(TypeName) == ComponentTypes.end());

	ComponentTypes.insert({TypeName, NextComponentType});

	ComponentArrays.insert({TypeName, std::make_shared<TComponentArray<T>>()});

	++NextComponentType;
}

template <typename T>
ComponentType ComponentManager::GetComponentType()
{
	const char *TypeName = typeid(T).name();

	check(ComponentTypes.find(TypeName) != ComponentTypes.end());

	return ComponentTypes[TypeName];
}

template <typename T>
void ComponentManager::AddComponent(Entity entity, T component)
{
	GetComponentArray<T>()->InsertData(entity, component);
}

template <typename T>
void ComponentManager::RemoveComponent(Entity entity)
{
	GetComponentArray<T>()->RemoveData(entity);
}

template <typename T>
T &ComponentManager::GetComponent(Entity entity)
{
	return GetComponentArray<T>()->GetData(entity);	
}

void ComponentManager::EntityDestroyed(Entity entity)
{
	for (auto const &pair : ComponentArrays)
	{
		auto const &component = pair.second;
		component->EntityDestroyed(entity);
	}
}

template <typename T>
std::shared_ptr<TComponentArray<T>> ComponentManager::GetComponentArray()
{
	const char *TypeName = typeid(T).name();

	check(ComponentTypes.find(TypeName) != ComponentTypes.end());

	return std::static_pointer_cast<TComponentArray<T>>(ComponentArrays[TypeName]);
}
