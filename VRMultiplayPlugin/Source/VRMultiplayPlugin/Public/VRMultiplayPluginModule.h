#pragma once

#include "ModuleManager.h"


class VRMultiplayPluginModuleImpl : public IModuleInterface
{
public:
	void StartupModule();
	void ShutdownModule();
};