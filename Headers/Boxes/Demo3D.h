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

namespace TE = Tempest;
namespace TM = TempestMath;

#include <Boxes/DataBases.h>
#include <Boxes/BoxesFactory.h>

namespace Boxes
{

    class Demo3D : public TE::Level
    {
    public:
        Demo3D(void);

        ~Demo3D(void);

        void v_Init(string path) final {}

        void v_Update(void) final {}

    private:
        bool _useOrbit;
        TE::p_StaticGameObject3D _crate1;
        TE::p_StaticGameObject3D _crate2;
        TE::p_StaticGameObject3D _floor;
        TE::p_StaticGameObject3D _robot;
        TE::p_StaticGameObject3D _bowlingPin;
        TE::p_StaticGameObject3D _bunny;
        TE::p_StaticGameObject3D _light;
        F32 _lightMovAngle;
        TE::OrbitCamera _orbitCamera;
        TE::FPSCamera _fpsCamera;
        
    };//end Class
    typedef shared_ptr<Demo3D> p_Demo3D;
}//end Namespace
