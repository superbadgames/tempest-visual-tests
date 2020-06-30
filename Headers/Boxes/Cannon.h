#pragma once

//Killer1 Includes
#include "stdafx.h"
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

//=====std includes=====
#include <vector>

//=====Box inclues=====
#include <Boxes/Projectile.h>

namespace Boxes
{
    class Cannon;
    typedef shared_ptr<Cannon> p_Cannon;

    class Cannon : public TE::GameObject2D
    {
    public:
//==========================================================================================================================
//
//Constructors
//
//==========================================================================================================================
        Cannon(void);

        ~Cannon(void);

//==========================================================================================================================
//
//Functions
//
//==========================================================================================================================
        void v_Update(void);

        void Fire(const TM::Vector2& heading, ProjectileType type);

        void AddToPool(p_Projectile p)
        {
            _projectilePool.push_back(p);
        }

//==========================================================================================================================
//
//Accessors
//
//==========================================================================================================================
        inline void SetMovementSpeed(F32 speed)
        {
            _movementSpeed = speed;
        }

        inline F32 GetMovementSpeed(void) const
        {
            return _movementSpeed;
        }

        inline void SetBottomBoundary(F32 boundary) 
        {
            _bottomBoundary = boundary;
        }

        inline F32 GetBottomBoundary(void) const
        {
            return _bottomBoundary;
        }

        inline void SetTopBoundary(F32 boundary)
        {
            _topBoundary = boundary;
        }

        inline F32 GetTopBoundary(void) const
        {
            return _topBoundary;
        }

        inline void SetUpDirection(const TM::Vector2& direction)
        {
            _upDirection = direction;
        }

        inline const TM::Vector2& GetUpDirection(void) const
        {
            return _upDirection;
        }

        inline void SetDownDirection(const TM::Vector2& direction)
        {
            _downDirection = direction;
        }

        inline const TM::Vector2& GetDownDirection(void) const
        {
            return _downDirection;
        }

    private:
//==========================================================================================================================
//
//Members
//
//==========================================================================================================================		
        F32						  			 _movementSpeed;
        F32						  			 _bottomBoundary;
        F32						  			 _topBoundary;
        TM::Vector2							 _upDirection;
        TM::Vector2							 _downDirection;
        std::vector<p_Projectile> 			 _projectilePool;
    };
}//end namespace