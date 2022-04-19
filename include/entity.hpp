/*
 *  This Source Code Form is subject to the terms of the Mozilla Public License,
 *  v. 2.0. If a copy of the MPL was not distributed with this file, You can
 *  obtain one at http://mozilla.org/MPL/2.0/.
 *  
 *  The original code is copyright (c) 2022, open.mp team and contributors.
 */

#pragma once

#include "component.hpp"
#include "events.hpp"
#include "gtaquat.hpp"
#include "types.hpp"
#include <set>

/// An interface for ID providers
struct IIDProvider {
    virtual int getID() const = 0;
};

/// A base entity interface
struct IEntity : public IIDProvider {
    /// Get the entity's position
    virtual Vector3 getPosition() const = 0;

    /// Set the entity's position
    virtual void setPosition(Vector3 position) = 0;

    /// Get the entity's rotation
    virtual GTAQuat getRotation() const = 0;

    /// Set the entity's rotation
    virtual void setRotation(GTAQuat rotation) = 0;

    /// Get the entity's virtual world
    virtual int getVirtualWorld() const = 0;

    /// Set the entity's virtual world
    virtual void setVirtualWorld(int vw) = 0;
};
