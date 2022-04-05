#pragma once

#include <sdk.hpp>
#include <Server/Components/Timers/timers.hpp>

static const UID FixesData_UID = UID(0x672d5d6fbb094ef7);
struct IPlayerFixesData : public IExtension
{
    PROVIDE_EXT_UID(FixesData_UID);

    /// Has the player seen this library?
    virtual bool seenAnimationLibrary(StringView animationLibrary) = 0;
	virtual bool markAnimationLibrary(StringView name, ITimer * timer) = 0;

	virtual int getLastCash() const = 0;
	virtual void setLastCash(int cash) = 0;
};

static const UID FixesComponent_UID = UID(0xb5c615eff0329ff7);
struct IFixesComponent : public IComponent
{
    PROVIDE_UID(FixesComponent_UID);

	virtual void applyAnimation(IPlayer & player, AnimationData const & anim, PlayerAnimationSyncType syncType) = 0;
	virtual void clearAnimations(IPlayer & player, PlayerAnimationSyncType syncType) = 0;
};

