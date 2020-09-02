/*==========================================================================================================================
Physics demo using the Killer Physics Engine. This will test various types of Ballistics, and will eventually turn into a 
king of mini game that lets you shoot down various types of missiles with the correct type of ballistic ammo. 

This is not free to use, and cannot be used without the express permission
of KillerWave.

Written by Maxwell Miller
==========================================================================================================================*/
#pragma once

//=====Engine includes=====
#include "stdafx.h"
#include <Engine/Atom.h>
#include <Engine/Engine.h>
#include <Engine/LevelManager.h>
#include <Engine/OpenGLGameWindow.h>
#include <Engine/Level.h>
#include <Engine/Controller.h>
#include <Engine/TextureManager.h>
#include <Engine/FontManager.h>
#include <Engine/Text.h>
#include <Engine/Vector4.h>
#include <Engine/Color.h>
#include <Engine/PhysicsFactory.h>

namespace TE = Tempest;
namespace TM = TempestMath;

//=====Box includes=====
#include <Boxes/DataBases.h>
#include <Boxes/Cannon.h>
#include <Boxes/Projectile.h>
#include <Boxes/DataBases.h>
#include <Boxes/ProjectFactory.h>

namespace Boxes
{
    class Ballistics : public TE::Level
    {
    public:
//==========================================================================================================================
//
//Constructors
//
//==========================================================================================================================
        Ballistics(void);
        ~Ballistics(void);		

//==========================================================================================================================
//
//Virtual Functions 
//
//==========================================================================================================================		
        void v_Init(void) final;

        void v_Update(void) final;

    private:
        void _InitPool(void);

//==========================================================================================================================
//
//Data
//
//==========================================================================================================================		
        U32									_poolSize;
        ProjectileType			  			_activeProjectileType;
        TE::Text 							_levelTitle;
        p_Cannon							_cannon;
        TP::p_GravityForce					p_gravityForce;
    };
    typedef shared_ptr<Ballistics> p_Ballistics;
}//end namespace