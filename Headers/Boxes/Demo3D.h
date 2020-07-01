#pragma once

//=====Engine Includes=====
#include <Engine/Atom.h>
#include <Engine/Level.h>
#include <Engine/Input.h>
#include <Engine/Engine.h>
#include <Engine/Timer.h>
#include <Engine/Texture.h>
#include <Engine/OrbitCamera.h>
#include <Engine/FPSCamera.h>
#include <Engine/Font.h>
#include <Engine/ShaderManager.h>

namespace TE = Tempest;
namespace TM = TempestMath;

#include <Boxes/Cube.h>
#include <Boxes/DataBases.h>
#include <Boxes/BoxesFactory.h>

namespace Boxes
{

    class Demo3D : public TE::Level
    {
    public:
        Demo3D(void);

        ~Demo3D(void);

        void v_Init(string path) final;

        void v_Update(void) final;

    private:
        bool _useOrbit;
        p_Cube _crate1;
        p_Cube _crate2;
        p_Cube _floor;
        p_Cube _robot;
        p_Cube _bowlingPin;
        p_Cube _bunny;
        p_Cube _light;
        F32 _lightMovAngle;
        TE::OrbitCamera _orbitCamera;
        TE::FPSCamera _fpsCamera;
        
    };//end Class
    typedef shared_ptr<Demo3D> p_Demo3D;
}//end Namespace
