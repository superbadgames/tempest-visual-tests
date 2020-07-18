#include "stdafx.h"
#include <Boxes/Demo3D.h>

using namespace Boxes;

Demo3D::Demo3D(void)
    :
    _useOrbit(true),
    _lightMovAngle(0.0f),
    _orbitCamera(),
    _fpsCamera()
{
    SetFactory(make_shared<BoxesFactory>());
}

Demo3D::~Demo3D(void)
{  }

void Demo3D::v_Init(void)
{
    Level::SetID(DEMO3D_ID);
    //Level::SetWidth(TE::GameWindow::Instance()->GetWidth());
    //Level::SetHeight(TE::GameWindow::Instance()->GetHeight());
    Level::SetBackgroundColor(TE::Color(0.2f, 0.3f, 0.4f));

    //Set up Cameras
    F32 left = -25.0f;
    F32 right = 25.0f;
    F32 bottom = -25.0f;
    F32 top = 25.0f;

    //Load Light Shader
    //Light
    std::vector<TE::ShaderData> shaderData;
    TE::ShaderData vs;
    vs.filePath = "./Assets/Shaders/basic_model_vertex.glsl";
    vs.type = TE::ShaderType::VERTEX;
    shaderData.push_back(vs);

    TE::ShaderData fs;
    fs.filePath = "./Assets/Shaders/basic_model_fragment.glsl";
    fs.type = TE::ShaderType::FRAGMENT;
    shaderData.push_back(fs);

    U32 ligthShaderID = 102;

    TE::ShaderManager::Instance()->LoadShader(ligthShaderID, shaderData);

    _orbitCamera.SetPerspective(45.0f, static_cast<F32>(TE::Driver::Instance()->GetScreenWidth()) / static_cast<F32>(TE::Driver::Instance()->GetScreenHeight()), 0.1f, 100.0f);
    //_orbitCamera.SetOrthographic(left, right, bottom, top, 0.01f, 100.0f);
    _orbitCamera.SetPosition(0.0f, 0.0f, 0.0f);
    //Offset for robot to look right
    

    _fpsCamera.SetPerspective(45.0f, static_cast<F32>(TE::Driver::Instance()->GetScreenWidth()) / static_cast<F32>(TE::Driver::Instance()->GetScreenHeight()), 0.1f, 100.0f);
    //_fpsCamera.SetOrthographic(left, right, bottom, top, -100.0f, 100.0f);
    _fpsCamera.SetPosition(0.0f, 0.0f, 0.0f);
    _fpsCamera.SetMoveSpeed(10.0f);
    _fpsCamera.SetMouseSensitivity(0.1f);
    _fpsCamera.SetDeadZone(0.2f);

    TE::CameraController::Instance()->SetCamera(&_orbitCamera);

    // All of these calls have to happen somewhere. Figure it out. 
    //Crate1
    TE::p_StaticGameObject3D crate1 {};
    crate1 = _factory->CreateStaticObject3D("./Assets/Models/Course/crate.obj", TM::Point3(0.0f), TM::Vector3(1.0f), TM::Vector3(1.0f), 500);
    crate1->SetShader(TE::ShaderManager::Instance()->GetShader(102));
    crate1->SetColor(TE::Color(1.0f, 0.0f, 0.0f));
    TE::GameObjectManager::Instance()->AddStaticObject3D(crate1);

    /*TE::p_StaticGameObject2D box1 = _factory->CreateStaticObject2D(TM::Point2(0.0f, 0.0f), 1.0f, 25.0f, 0);
    TE::GameObjectManager::Instance()->AddDynamicObject2D(box1);*/

    ////Crate2
    //_crate2 = ProjectFactory::Instance()->MakeCube();
    //_crate2->InitCube("./Assets/Models/Course/crate.obj");
    //_crate2->SetPosition(5.0f, 0.0f, 0.0f);
    //_crate2->SetTexture(TE::TextureManager::Instance()->GetTexture(501));
    //_crate2->SetColor(0.0f, 1.0f, 0.0f);
    ////_crate2->SetActive(false);
    //Level::AddObjectToLevel(_crate2);

    ////Robot	
    //_robot = ProjectFactory::Instance()->MakeCube();
    //_robot->InitCube("./Assets/Models/Course/robot.obj");
    //_robot->SetPosition(0.0f, -1.0f, -2.0f);
    //_robot->SetTexture(TE::TextureManager::Instance()->GetTexture(502));
    //_robot->SetColor(0.5f, 0.5f, 0.5f);
    ////_robot->SetActive(false);
    //Level::AddObjectToLevel(_robot);

    ////Bowling Pin
    //_bowlingPin = ProjectFactory::Instance()->MakeCube();
    //_bowlingPin->InitCube("./Assets/Models/Course/bowling_pin.obj");
    //_bowlingPin->SetPosition(0.0f, 0.0f, 4.0f);
    //_bowlingPin->SetScale(0.1f, 0.1f, 0.1f);
    //_bowlingPin->SetActive(false);
    ////_bowlingPin->SetTexture(pinTexture);
    //Level::AddObjectToLevel(_bowlingPin);
    //
    ////Bunny
    //_bunny = ProjectFactory::Instance()->MakeCube();
    //_bunny->InitCube("./Assets/Models/Course/bunny.obj");
    //_bunny->SetPosition(-2.0f, 0.0f, 0.0f);
    //_bunny->SetScale(0.7f, 0.7f, 0.7f);
    ////_bunny->SetActive(false);
    ////_bunny->SetTexture(TE::TextureManager::Instance()->GetTexture(503));
    //Level::AddObjectToLevel(_bunny);

    ////Floor
    //_floor = ProjectFactory::Instance()->MakeCube();
    //_floor->InitCube("./Assets/Models/Course/floor.obj");
    //_floor->SetPosition(0.0f, -1.0f, 0.0f);
    //_floor->SetScale(10.0f, 0.1f, 10.0f);
    //_floor->SetTexture(TE::TextureManager::Instance()->GetTexture(504));
    ////_floor->SetActive(false);
    //Level::AddObjectToLevel(_floor);

    //Light
    /* _light = ProjectFactory::Instance()->MakeCube();
    _light->InitCube("./Assets/Models/Course/light.obj", ligthShaderID);
    _light->SetPosition(0.0f, 2.0f, 8.0f);
    _light->SetActiveUpdate(false);
    _light->SetActive(false);
    Level::AddObjectToLevel(_light); */

    TE::Color lightColor(1.0f, 1.0f, 1.0f);
    lightColor.UseAlpha(false);
    TM::Point3 lightPos {0.0f, 2.0f, 8.0f};
    TM::Vector3 lightDirection{ 0.0f, -0.9f, -0.17f };
    TE::Color ambient{ 1.0f, 1.0f, 1.0f };
    ambient.UseAlpha(false);
    TE::Color specular{ 1.0f, 1.0f, 1.0f };
    specular.UseAlpha(false);

    /*TM::Point targetPos = _robot->GetPosition();
    _orbitCamera.SetTarget(targetPos[0], targetPos[1] + 3.0f, targetPos[2]);
    _orbitCamera.SetUpVector(0.0f, 1.0f, 0.0f);
    _orbitCamera.SetMouseSensitivity(0.25f);*/

    //Add the following: 
    // point:
    // set uniform name = light.constant = 1.0f
    // set uniform name = light.linear = 0.07f
    // set uniform name = light.exponent = 0.017f
    //
    // spot:
    // set uniform name = light.cosInnerCone = cos(Randian(15.0f))
    // set uniform name = light.cosOuterCone = cos(Radian(20.0f))
    // set uniform name = light.on = bool flashLightOn. Use F key to toggle on and off. 

    crate1->GetShader()->SetUniform("light.ambient", ambient);
    crate1->GetShader()->SetUniform("light.diffuse", lightColor);
    crate1->GetShader()->SetUniform("light.specular", specular);
    crate1->GetShader()->SetUniform("light.position", lightPos);
    crate1->GetShader()->SetUniform("light.direction", lightDirection);


    //_light->GetShader()->SetUniform("lightColor", lightColor);


    TE::Color ambientMat{ 0.1f, 0.1f, 0.1f };
    ambientMat.UseAlpha(false);
    TE::Color specularMat{ 0.5f, 0.5f, 0.5f };
    specularMat.UseAlpha(false);
    F32 shininess = 150.0f;
    
    TE::GameObjectManager::Instance()->SetStaticGameObject3DUniforms("material.ambient", ambientMat);
    TE::GameObjectManager::Instance()->SetStaticGameObject3DUniforms("material.specular", specularMat);
    TE::GameObjectManager::Instance()->SetStaticGameObject3DUniforms("material.shininess", shininess);

    crate1->GetShader()->SetUniformSampler("material.diffuseMap", 0); //Texture slot 0
    //_crate2->GetShader()->SetUniformSampler("material.diffuseMap", 0); //Texture slot 0
    //_robot->GetShader()->SetUniformSampler("material.diffuseMap", 0); //Texture slot 0
    //_bowlingPin->GetShader()->SetUniformSampler("material.diffuseMap", 0); //Texture slot 0
    //_bunny->GetShader()->SetUniformSampler("material.diffuseMap", 0); //Texture slot 0
    //_floor->GetShader()->SetUniformSampler("material.diffuseMap", 0); //Texture slot 0

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
        //TE::OpenGLGameWindow::Instance()->ToggleWireFrame();
    }
    else if(TE::Input::Instance()->GetKeyDown(TE::Keys::F1))
    {
        _useOrbit = !_useOrbit;

        if(!_useOrbit)
        {
            TE::CameraController::Instance()->SetCamera(&_fpsCamera);
            //TE::Driver::Instance()->DisableMouseCursor();
        }
        else
        {
            TE::CameraController::Instance()->SetCamera(&_orbitCamera);
            //TE::OpenGLGameWindow::Instance()->EnableMouseCursor();
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

    ////Move Light Code
    //_lightMovAngle += TM::Timer::Instance()->DeltaTime() * 50.0f;
    //_light->SetPositionX(8.0f * sin(RADIAN(_lightMovAngle)));
    //
    //TM::Point lightPos = _light->GetPosition();

    ////Update view Position
    //Level::SetObjectUniforms("view_position", viewPos);

    ////Update light Position
    //Level::SetObjectUniforms("light.position", lightPos);
}
