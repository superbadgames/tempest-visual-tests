#include "stdafx.h"
#include "Game/Demo3D.h"

using namespace Boxes;

Demo3D::Demo3D(void)
    :
    _useOrbit(true),
    _orbitCamera(),
    _fpsCamera(),
    _directional()
{
    SetFactory(make_shared<BoxesFactory>());
}

Demo3D::~Demo3D(void)
{  }

void Demo3D::v_Init(void)
{
    SetID(DEMO3D_ID);
    //Level::SetBackgroundColor(TE::Color(0.2f, 0.3f, 0.4f));
    SetBackgroundColor(TE::Color(0.01f, 0.05f, 0.01f));

    _orbitCamera.SetPerspective();
    _orbitCamera.SetPosition(0.0f, 0.0f, 0.0f);

    _fpsCamera.SetPerspective();
    _fpsCamera.SetPosition(0.0f, 0.0f, 0.0f);
    _fpsCamera.SetMoveSpeed(10.0f);
    _fpsCamera.SetMouseSensitivity(0.1f);
    _fpsCamera.SetDeadZone(0.2f);

    TE::CameraController::Instance()->SetCamera(&_orbitCamera);

    TE::p_StaticGameObject3D cube1 {};
    cube1 = _factory->CreateStaticObject3D("./Assets/Models/Course/bunny.obj", 0, TM::Point3(0.0f), TM::Vector3(1.0f), TM::Vector3(1.0f), 500);
    cube1->SetColor(TE::Color(1.0f, 0.7f, 0.7f));
    TE::GameObjectManager::Instance()->AddStaticObject3D(cube1);

    _directional.SetAmbientColor(TE::Color(1.0f, 1.0f, 1.0f));
    _directional.SetPosition(TM::Vector3(25.0f, 10.0f, 10.0f));
    _directional.SetSpecularFactor(0.08f);
    _directional.SetSpecularShine(250.0f);
}

void Demo3D::v_Update(void)
{
    if(TE::Input::Instance()->GetKeyDown(TE::Keys::ESCAPE))
    {
        TE::Driver::Instance()->End();
        return;
    }
    else if(TE::Input::Instance()->GetKeyDown(TE::Keys::F11))
    {
        TE::Driver::Instance()->ToggleWireFrame();
    }
    else if(TE::Input::Instance()->GetKeyDown(TE::Keys::F1))
    {
        _useOrbit = !_useOrbit;

        if(!_useOrbit)
        {
            TE::CameraController::Instance()->SetCamera(&_fpsCamera);
            TE::Driver::Instance()->ToggleMouseCursor(false);
        }
        else
        {
            TE::CameraController::Instance()->SetCamera(&_orbitCamera);
            TE::Driver::Instance()->ToggleMouseCursor(true);
        }
    }

    TM::Point3 viewPos;

    if(_useOrbit)
    {
        viewPos = _orbitCamera.GetPosition();

        if(TE::Input::Instance()->GetKeyHeld(TE::LEFT_MOUSE))
        {
            _orbitCamera.Orbit();
        }

        if(TE::Input::Instance()->GetKeyHeld(TE::RIGHT_MOUSE))
        {
            _orbitCamera.Zoom();
        }
    }
    else
    {
        viewPos = _fpsCamera.GetPosition();

        if(TE::Input::Instance()->GetKeyHeld(TE::W))
        {
            _fpsCamera.v_Move(_fpsCamera.GetLookDirection()); //forward
        }
        else if(TE::Input::Instance()->GetKeyHeld(TE::S))
        {
            _fpsCamera.v_Move(_fpsCamera.GetLookDirection() * -1.0f); //back
        }
        
        if(TE::Input::Instance()->GetKeyHeld(TE::D))
        {
            _fpsCamera.v_Move(_fpsCamera.GetRightVector()); //right
        }
        else if(TE::Input::Instance()->GetKeyHeld(TE::A))
        {
            _fpsCamera.v_Move(_fpsCamera.GetRightVector() * -1.0f); //left
        }

        if(TE::Input::Instance()->GetKeyHeld(TE::SPACE))
        {
            _fpsCamera.v_Move(_fpsCamera.GetUpDirection()); //up
        }
        else if(TE::Input::Instance()->GetKeyHeld(TE::LSHIFT))
        {
            _fpsCamera.v_Move(_fpsCamera.GetUpDirection() * -1.0f); //down
        }
    }

    TE::ShaderManager::Instance()->SetAllUniforms("camera_position", viewPos);
}
