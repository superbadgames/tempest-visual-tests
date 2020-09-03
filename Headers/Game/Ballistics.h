#pragma once

#include "stdafx.h"
#include <Engine/Atom.h>
#include <Engine/Driver.h>
#include <Engine/LevelManager.h>
#include <Engine/OpenGLGameWindow.h>
#include <Engine/Level.h>
#include <Engine/Input.h>
#include <Engine/TextureManager.h>
#include <Engine/FontManager.h>
#include <Engine/Text.h>
#include <Engine/Vector4.h>
#include <Engine/Color.h>
#include <Engine/PhysicsFactory.h>

namespace TE = Tempest;
namespace TM = TempestMath;

#include "Boxes/Cannon.h"
#include "Boxes/Projectile.h"
#include "Boxes/Factory.h"
#include "Game/DataBases.h"

class Ballistics : public TE::Level
{
public:
    Ballistics(void);
    
    ~Ballistics(void);

    void v_Init(void) final;

    void v_Update(void) final;

private:
    U32 _poolSize;
    Boxes::ProjectileType _activeProjectileType;
    TE::Text _levelTitle;
    Boxes::p_Cannon _cannon;
    TP::p_GravityForce p_gravityForce;
};
typedef shared_ptr<Ballistics> p_Ballistics;
