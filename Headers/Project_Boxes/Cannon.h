#pragma once

#include "stdafx.h"
#include <vector>
#include <Engine/Atom.h>
#include <Engine/GameObject2D.h>
#include <Engine/Input.h>
#include <Engine/Timer.h>
#include <Engine/Texture.h>
#include <Engine/Vector2.h>
#include <Engine/LevelManager.h>
#include <Engine/GravityForce.h>

namespace TE = Tempest;
namespace TM = TempestMath;
namespace TP = TempestPhysics;

#include "Boxes/Definitions.h"
#include "Boxes/Projectile.h"

namespace Boxes
{
    class Cannon : public TE::GameObject2D
    {
    public:
        Cannon(void);

        ~Cannon(void);

        BOXES_API void v_Update(void);

        BOXES_API void Fire(const TM::Vector2& heading, ProjectileType type);

        BOXES_API void AddToPool(p_Projectile p);

        BOXES_API void SetMovementSpeed(F32 speed);

        BOXES_API F32 GetMovementSpeed(void) const;

        BOXES_API void SetBottomBoundary(F32 boundary);

        BOXES_API F32 GetBottomBoundary(void) const;

        BOXES_API void SetTopBoundary(F32 boundary);

        BOXES_API F32 GetTopBoundary(void) const;

        BOXES_API void SetUpDirection(const TM::Vector2& direction);

        BOXES_API const TM::Vector2& GetUpDirection(void) const;

        BOXES_API void SetDownDirection(const TM::Vector2& direction);

        BOXES_API const TM::Vector2& GetDownDirection(void) const;

    private:
        F32 _movementSpeed;
        F32 _bottomBoundary;
        F32 _topBoundary;
        TM::Vector2 _upDirection;
        TM::Vector2 _downDirection;
        std::vector<p_Projectile> _projectilePool;
    };
    typedef shared_ptr<Cannon> p_Cannon;
}//end namespace