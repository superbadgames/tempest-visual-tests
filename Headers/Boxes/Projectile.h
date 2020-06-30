/*=========================================================================
A model for ballistic missiles that will be fired by the cannon in the 
Ballistics level. Most of these models started as examples from game 
physics development. 

This will follow the decorator pattern. That is, when a Projectiles is 
fired, it will be created based of what is being fired, and that will change
all of its properties. Each Projectile will be in charge of destroying itself
based on how far it has traveled since it was fired. 

This is not free to use, and cannot be used without the express permission
of KillerWave.

Written by Maxwell Miller
=========================================================================*/
#pragma once

//=====Killer2D includes=====
#include "stdafx.h"
#include <Engine/Atom.h>
#include <Engine/ErrorManager.h>
#include <Engine/GameObject2D.h>
#include <Engine/RigidBody2D.h>
#include <Engine/Timer.h>
#include <Engine/TextureManager.h>
#include <Engine/PhysicsFactory.h>
#include <Engine/Point2.h>

namespace TE = Tempest;
namespace TM = TempestMath;
namespace TP = TempestPhysics;

namespace Boxes
{
    enum ProjectileType
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
//==========================================================================================================================
//
//Constructors
//
//==========================================================================================================================		
        Projectile(void);

        ~Projectile(void);

//==========================================================================================================================
//
//Virtual GameObject2D Functions
//
//==========================================================================================================================
        void v_Update(void);

//==========================================================================================================================
//
//Accessors
//
//==========================================================================================================================
        void SetMaxDistance(F32 dist);

        F32 GetMaxDistance(void);

        void SetSpeedScale(F32 scale);

        F32 GetSpeedScale(void);

        void SetType(ProjectileType type);

        ProjectileType GetType(void);

        inline void AddScaledVelocity(const TM::Vector2& vec, F32 scale)
        {
            p_rigidBody->SetVelocity(vec * scale);
        }

        inline TP::p_RigidBody2D GetRigidBody(void)
        {
            return p_rigidBody;
        }

    private:
        F32  		   			   _maxDistance;
        F32  		   			   _sqrDistance;
        F32			   			   _speedScale;
        TM::Point2 				   _startingLocation;
        ProjectileType 			   _type;
        TP::p_RigidBody2D 		   p_rigidBody;

    };//end class Projectile

    typedef shared_ptr<Projectile> p_Projectile;
}//end namespace
