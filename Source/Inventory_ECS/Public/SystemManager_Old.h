#pragma once
#include "System_Old.h"
#include "Inventory_ECS/EcsMinimal_Old.h"

class SystemManager_Old
{
public:

	template <typename T>
	std::shared_ptr<T> RegisterSystem();

	template <typename T>
	void SetSignature(Signature Signature);

	void EntityDestroyed(Entity entity);

	void EntitySignatureChanged(Entity entity, Signature entitySignature);

private:
	
	std::unordered_map<const char *, Signature> Signatures;

	std::unordered_map<const char *, std::shared_ptr<System_Old>> Systems;
};
