#pragma once

#include <sdk.hpp>

static const UID FixesData_UID = UID(0x672d5d6fbb094ef7);
struct IPlayerFixesData : public IExtension
{
    PROVIDE_EXT_UID(FixesData_UID);

    /// Has the player seen this library?
    virtual bool seenLibrary(StringView animationLibrary) = 0;
};

static const UID FixessComponent_UID = UID(0xb5c615eff0329ff7);
struct IFixessComponent : public IComponent
{
    PROVIDE_UID(FixessComponent_UID);
};

