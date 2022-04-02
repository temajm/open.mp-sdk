#pragma once

#include <sdk.hpp>

static const UID FixesData_UID = UID(0x672d5d6fbb094ef7);
struct IPlayerFixesData : public IExtension
{
    PROVIDE_EXT_UID(FixesData_UID);

    /// Has the player seen this library?
    virtual bool seenLibrary(StringView animationLibrary) = 0;
};

static const UID FixesComponent_UID = UID(0xb5c615eff0329ff7);
struct IFixesComponent : public IComponent
{
    PROVIDE_UID(FixesComponent_UID);

	virtual void fixApplyAnimation2(IPlayer& player, StringView const animlib, StringView const animname, float delta, bool loop, bool lockX, bool lockY, bool freeze, uint32_t time, int sync) = 0;
};

