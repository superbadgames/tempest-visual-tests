#pragma once

#include "stdafx.h"
#include <Engine/Atom.h>
#include <Engine/ErrorManager.h>
#include <Engine/GameObject2D.h>
#include <Engine/RigidBody2D.h>
#include <Engine/Timer.h>
#include <Engine/TextureManager.h>
#include <Engine/PhysicsFactory.h>
#include <Engine/Vector2.h>

namespace TE = Tempest;
namespace TM = TempestMath;
namespace TP = TempestPhysics;

#include "Boxes/Definitions.h"

namespace Boxes
{

    enum class ProjectileType
    {
        BULLET,
        ARTILLERY,
        MISSILE,
        FIRE_BALL,
        LAZER,
        GRENADE
    };

    class Projectile : public TE::GameObject2D
    {
    public:
        
        
        BOXES_API Projectile(void);

        BOXES_API ~Projectile(void);

        BOXES_API void v_Update(void);

        BOXES_API void SetMaxDistance(F32 dist);

        BOXES_API F32 GetMaxDistance(void);

        BOXES_API void SetSpeedScale(F32 scale);

        BOXES_API F32 GetSpeedScale(void);

        BOXES_API void SetType(ProjectileType type);

        BOXES_API ProjectileType GetType(void);

        BOXES_API void AddScaledVelocity(const TM::Vector2& vec, F32 scale);

        BOXES_API TP::p_RigidBody2D GetRigidBody(void);

    private:
        F32 _maxDistance;
        F32 _sqrDistance;
        F32 _speedScale;
        TM::Point2 _startingLocation;
        ProjectileType _type;
        TP::p_RigidBody2D p_rigidBody;

    };//end class Projectile

    typedef shared_ptr<Projectile> p_Projectile;
}//end namespace
