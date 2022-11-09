#pragma once
#include "Inventory_ECS/EcsMinimal.h"
#include <set>

class System
{
public:
	std::set<Entity> Entities;
};
