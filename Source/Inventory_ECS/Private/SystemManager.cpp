#include "SystemManager.h"

template <typename T>
std::shared_ptr<T> SystemManager::RegisterSystem()
{
	const char *TypeName = typeid(T).name();

	check(Systems.find(TypeName) == Systems.end());

	auto system = std::make_shared<T>();
	Systems.insert({TypeName, system});
	return system;
}

template <typename T>
void SystemManager::SetSignature(Signature signature)
{
	const char *TypeName = typeid(T).name();

	check(Systems.find(TypeName) != Systems.end());

	Signatures.insert({TypeName, signature});
}

void SystemManager::EntityDestroyed(Entity entity)
{
	for (auto const &pair : Systems)
	{
		auto const &system = pair.second;

		system->Entities.erase(entity);
	}
}

void SystemManager::EntitySignatureChanged(Entity entity, Signature entitySignature)
{
	for (auto const &pair : Systems)
	{
		auto const &type = pair.first;
		auto const &system = pair.second;
		auto const &systemSignature = Signatures[type];

		if ((entitySignature & systemSignature) == systemSignature)
		{
			system->Entities.insert(entity);
		}

		else
		{
			system->Entities.erase(entity);
		}
	}
}