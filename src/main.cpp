#include <SKSE/SKSE.h>
#include <SKSE/API.h>
#include <RE/Skyrim.h>


namespace AutoMove
{
	// SKSE::RegistrationSet<int> onCustomMarkerChange("OnCustomMarkerChange");
	// SKSE::RegistrationSet<RE::Actor, bool> onPlayerDialogue("OnPlayerDialogue");
	// SKSE::RegistrationSet<void> onFastTravelConfirm("OnFastTravelConfirm");
	// REL::ID id_obj2(24523);


	bool GetPtrByRefHandle(RE::ObjectRefHandle* a, uintptr_t* out)
	{
		REL::Relocation<decltype(GetPtrByRefHandle)> fn(19700);
		return fn(a, out);
	}


	bool ForceRefToAlias(RE::TESQuest* script, unsigned int aliasID, uintptr_t ref)
	{
		REL::Relocation<decltype(ForceRefToAlias)> fn(25052);
		return fn(script, aliasID, ref);
	}


	void ForceDestinationMarkerIntoAliasID(RE::TESQuest* script, unsigned int aliasID)
	{
		auto player = RE::PlayerCharacter::GetSingleton();
		uintptr_t handleptr = 0;
		bool result = GetPtrByRefHandle((RE::ObjectRefHandle*)&player->unk924, &handleptr);
		if (handleptr)
		{
			result = ForceRefToAlias(script, aliasID, handleptr);
		}
	}

	bool IsCustomDestinationActive(RE::StaticFunctionTag*)
	{
		return (bool)(*(RE::ObjectRefHandle*)&RE::PlayerCharacter::GetSingleton()->unk924);
	}

	void RegisterForCustomMarkerChange(RE::TESQuest*)
	{
		//onCustomMarkerChange.Register();
	}
	void UnregisterForCustomMarkerChange(RE::TESQuest*)
	{
	}

	void RegisterForPlayerDialogue(RE::TESQuest*)
	{
		//onCustomMarkerChange.Register();
	}
	void UnregisterForPlayerDialogue(RE::TESQuest*)
	{
	}

	RE::Actor* GetCurrentMount(RE::StaticFunctionTag*, RE::Actor* a)
	{
		return a;
	}
}

bool RegisterFuncs(RE::BSScript::IVirtualMachine* a_vm)
{
	a_vm->RegisterFunction("ForceDestinationMarkerIntoAliasID", "AutoMove", AutoMove::ForceDestinationMarkerIntoAliasID);
	a_vm->RegisterFunction("IsCustomDestinationActive", "AutoMove", AutoMove::IsCustomDestinationActive);
	//a_vm->RegisterFunction("GetCurrentMount", "AutoMove", AutoMove::GetCurrentMount);
	//a_vm->RegisterFunction("RegisterForCustomMarkerChange", "AutoMove", AutoMove::RegisterForCustomMarkerChange);
	//a_vm->RegisterFunction("UnregisterForCustomMarkerChange", "AutoMove", AutoMove::UnregisterForCustomMarkerChange);
	//a_vm->RegisterFunction("RegisterForPlayerDialogue", "AutoMove", AutoMove::RegisterForPlayerDialogue);
	//a_vm->RegisterFunction("UnregisterForPlayerDialogue", "AutoMove", AutoMove::UnregisterForPlayerDialogue);
	return true;
}


SKSEPluginLoad(const LoadInterface* a_skse)
{
	SKSE::Init(a_skse);
	SKSE::AllocTrampoline(1 << 9);

	SKSE::GetPapyrusInterface()->Register(RegisterFuncs);

	return true;
}
