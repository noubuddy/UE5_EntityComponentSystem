#include "ComponentManager_Old.h"

template <typename T>
void ComponentManager_Old::RegisterComponent()
{
	const char *TypeName = typeid(T).name();

	check(ComponentTypes.find(TypeName) == ComponentTypes.end());

	ComponentTypes.insert({TypeName, NextComponentType});

	ComponentArrays.insert({TypeName, std::make_shared<ComponentArray_Old<T>>()});

	++NextComponentType;
}

template <typename T>
ComponentType ComponentManager_Old::GetComponentType()
{
	const char *TypeName = typeid(T).name();

	check(ComponentTypes.find(TypeName) != ComponentTypes.end());

	return ComponentTypes[TypeName];
}

template <typename T>
void ComponentManager_Old::AddComponent(Entity entity, T component)
{
	GetComponentArray<T>()->InsertData(entity, component);
}

template <typename T>
void ComponentManager_Old::RemoveComponent(Entity entity)
{
	GetComponentArray<T>()->RemoveData(entity);
}

template <typename T>
T &ComponentManager_Old::GetComponent(Entity entity)
{
	return GetComponentArray<T>()->GetData(entity);	
}

void ComponentManager_Old::EntityDestroyed(Entity entity)
{
	for (auto const &pair : ComponentArrays)
	{
		auto const &component = pair.second;
		component->EntityDestroyed(entity);
	}
}

template <typename T>
std::shared_ptr<ComponentArray_Old<T>> ComponentManager_Old::GetComponentArray()
{
	const char *TypeName = typeid(T).name();

	check(ComponentTypes.find(TypeName) != ComponentTypes.end());

	return std::static_pointer_cast<ComponentArray_Old<T>>(ComponentArrays[TypeName]);
}
