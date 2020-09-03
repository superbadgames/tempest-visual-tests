#pragma once

//=====Engine Includes=====
#include <Engine/Atom.h>
#include <Engine/Level.h>
#include <Engine/Input.h>
#include <Engine/Driver.h>
#include <Engine/Timer.h>
#include <Engine/Texture.h>
#include <Engine/OrbitCamera.h>
#include <Engine/FPSCamera.h>
#include <Engine/Font.h>
#include <Engine/ShaderManager.h>
#include <Engine/GameObjectManager.h>
#include <Engine/StaticGameObject3D.h>
#include <Engine/Light.h>

namespace TE = Tempest;
namespace TM = TempestMath;

#include "Boxes/Factory.h"
#include "Game/DataBases.h"


class Demo3D : public TE::Level
{
public:
    Demo3D(void);

    ~Demo3D(void);

    void v_Init(void) final;

    void v_Update(void) final;

private:
    bool _useOrbit;
    TE::OrbitCamera _orbitCamera;
    TE::FPSCamera _fpsCamera;
    TE::Light _directional;

};//end Class
typedef shared_ptr<Demo3D> p_Demo3D;
