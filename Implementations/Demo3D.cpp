#include "stdafx.h"
/*

This needs to be refactored and made into something far more interesting. This is going to be a task for another day. 

#include <Boxes/Demo3D.h>

using namespace Boxes;

//==========================================================================================================================
//
//Constructors	 	
//
//==========================================================================================================================
Demo3D::Demo3D(void)
:
_useOrbit(true),
_crate1(nullptr),
_crate2(nullptr),
_floor(nullptr),
_robot(nullptr),
_bowlingPin(nullptr),
_bunny(nullptr),
_light(nullptr),
_lightMovAngle(0.0f),
_orbitCamera(make_shared<TE::OrbitCamera>()),
_fpsCamera(make_shared<TE::FPSCamera>())
{

}

Demo3D::~Demo3D(void)
{  }

void Demo3D::v_Init(void)
{
    Level::SetID(DEMO3D_ID);
    Level::SetWidth(TE::OpenGLGameWindow::Instance()->GetWidth());
    Level::SetHeight(TE::OpenGLGameWindow::Instance()->GetHeight());
    Level::SetBackgroundColor(TE::Color(0.2f, 0.4f, 0.5f));

    //Set up Cameras
    F32 left = -25.0f;
    F32 right = 25.0f;
    F32 bottom = -25.0f;
    F32 top = 25.0f;

    //Load Light Shader
    //Light
    std::vector<TE::ShaderData> shaderData;
    TE::ShaderData vs;
    vs.filePath = "./Assets/Shaders/light_vertex.glsl";
    vs.type = TE::ShaderType::VERTEX;
    shaderData.push_back(vs);

    TE::ShaderData fs;
    fs.filePath = "./Assets/Shaders/light_fragment.glsl";
    fs.type = TE::ShaderType::FRAGMENT;
    shaderData.push_back(fs);

    U32 ligthShaderID = 102;

    TE::ShaderManager::Instance()->LoadShader(ligthShaderID, shaderData);

    _orbitCamera->SetPerspective(45.0f, static_cast<F32>(Level::GetWidth()) / static_cast<F32>(Level::GetHeight()), 0.1f, 100.0f);
    //_orbitCamera->SetOrthographic(left, right, bottom, top, 0.01f, 100.0f);
    _orbitCamera->SetPosition(0.0f, 0.0f, 0.0f);
    //Offset for robot to look right
    

    _fpsCamera->SetPerspective(45.0f, static_cast<F32>(Level::GetWidth()) / static_cast<F32>(Level::GetHeight()), 0.1f, 100.0f);
    //_fpsCamera->SetOrthographic(left, right, bottom, top, -100.0f, 100.0f);
    _fpsCamera->SetPosition(0.0f, 0.0f, 0.0f);
    _fpsCamera->SetMoveSpeed(10.0f);
    _fpsCamera->SetMouseSensitivity(0.1f);
    _fpsCamera->SetDeadZone(0.2f);

    TE::OpenGLGameWindow::Instance()->SetCamera(_orbitCamera);

    //Crate1
    _crate1 = ProjectFactory::Instance()->MakeCube();
    _crate1->InitCube("./Assets/Models/Course/crate.obj");
    _crate1->SetPosition(-5.0f, 0.0f, 0.0f);
    _crate1->SetTexture(TE::TextureManager::Instance()->GetTexture(500));
    _crate1->SetColor(1.0f, 0.0f, 0.0f);
    Level::AddObjectToLevel(_crate1);

    //Crate2
    _crate2 = ProjectFactory::Instance()->MakeCube();
    _crate2->InitCube("./Assets/Models/Course/crate.obj");
    _crate2->SetPosition(5.0f, 0.0f, 0.0f);
    _crate2->SetTexture(TE::TextureManager::Instance()->GetTexture(501));
    _crate2->SetColor(0.0f, 1.0f, 0.0f);
    //_crate2->SetActive(false);
    Level::AddObjectToLevel(_crate2);

    //Robot	
    _robot = ProjectFactory::Instance()->MakeCube();
    _robot->InitCube("./Assets/Models/Course/robot.obj");
    _robot->SetPosition(0.0f, -1.0f, -2.0f);
    _robot->SetTexture(TE::TextureManager::Instance()->GetTexture(502));
    _robot->SetColor(0.5f, 0.5f, 0.5f);
    //_robot->SetActive(false);
    Level::AddObjectToLevel(_robot);

    //Bowling Pin
    _bowlingPin = ProjectFactory::Instance()->MakeCube();
    _bowlingPin->InitCube("./Assets/Models/Course/bowling_pin.obj");
    _bowlingPin->SetPosition(0.0f, 0.0f, 4.0f);
    _bowlingPin->SetScale(0.1f, 0.1f, 0.1f);
    _bowlingPin->SetActive(false);
    //_bowlingPin->SetTexture(pinTexture);
    Level::AddObjectToLevel(_bowlingPin);
    
    //Bunny
    _bunny = ProjectFactory::Instance()->MakeCube();
    _bunny->InitCube("./Assets/Models/Course/bunny.obj");
    _bunny->SetPosition(-2.0f, 0.0f, 0.0f);
    _bunny->SetScale(0.7f, 0.7f, 0.7f);
    //_bunny->SetActive(false);
    //_bunny->SetTexture(TE::TextureManager::Instance()->GetTexture(503));
    Level::AddObjectToLevel(_bunny);

    //Floor
    _floor = ProjectFactory::Instance()->MakeCube();
    _floor->InitCube("./Assets/Models/Course/floor.obj");
    _floor->SetPosition(0.0f, -1.0f, 0.0f);
    _floor->SetScale(10.0f, 0.1f, 10.0f);
    _floor->SetTexture(TE::TextureManager::Instance()->GetTexture(504));
    //_floor->SetActive(false);
    Level::AddObjectToLevel(_floor);

    //Light
    _light = ProjectFactory::Instance()->MakeCube();
    _light->InitCube("./Assets/Models/Course/light.obj", ligthShaderID);
    _light->SetPosition(0.0f, 2.0f, 8.0f);
    _light->SetActiveUpdate(false);
    _light->SetActive(false);
    Level::AddObjectToLevel(_light);	

    TE::Color lightColor(1.0f, 1.0f, 1.0f);	
    lightColor.UseAlpha(false);
    TM::Point lightPos = _light->GetPosition();
    TM::Vector3 lightDirection{ 0.0f, -0.9f, -0.17f };
    TE::Color ambient{ 1.0f, 1.0f, 1.0f };
    ambient.UseAlpha(false);
    TE::Color specular{ 1.0f, 1.0f, 1.0f };
    specular.UseAlpha(false);

    TM::Point targetPos = _robot->GetPosition();
    _orbitCamera->SetTarget(targetPos[0], targetPos[1] + 3.0f, targetPos[2]);
    _orbitCamera->SetUpVector(0.0f, 1.0f, 0.0f);
    _orbitCamera->SetMouseSensitivity(0.25f);

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

    Level::SetObjectUniforms("light.ambient", ambient);
    Level::SetObjectUniforms("light.diffuse", lightColor);
    Level::SetObjectUniforms("light.specular", specular);
    Level::SetObjectUniforms("light.position", lightPos);
    Level::SetObjectUniforms("light.direction", lightDirection);


    _light->GetShader()->SetUniform("lightColor", lightColor);


    TE::Color ambientMat{ 0.1f, 0.1f, 0.1f };
    ambientMat.UseAlpha(false);
    TE::Color specularMat{ 0.5f, 0.5f, 0.5f };
    specularMat.UseAlpha(false);
    F32 shininess = 150.0f;
    
    Level::SetObjectUniforms("material.ambient", ambientMat);
    Level::SetObjectUniforms("material.specular", specularMat);
    Level::SetObjectUniforms("material.shininess", shininess);

    _crate1->GetShader()->SetUniformSampler("material.diffuseMap", 0); //Texture slot 0
    _crate2->GetShader()->SetUniformSampler("material.diffuseMap", 0); //Texture slot 0
    _robot->GetShader()->SetUniformSampler("material.diffuseMap", 0); //Texture slot 0
    _bowlingPin->GetShader()->SetUniformSampler("material.diffuseMap", 0); //Texture slot 0
    _bunny->GetShader()->SetUniformSampler("material.diffuseMap", 0); //Texture slot 0
    _floor->GetShader()->SetUniformSampler("material.diffuseMap", 0); //Texture slot 0

}

void Demo3D::v_Update(void)
{
    if(TE::Controller::Instance()->GetKeyDown(TE::Keys::ESCAPE))
    {
        TE::Engine::Instance()->SetActiveLevel(TE::LevelManager::Instance()->GetLevel(MAIN_MENU_ID));
        return;
    }
    else if(TE::Controller::Instance()->GetKeyDown(TE::Keys::F11))
    {
        TE::OpenGLGameWindow::Instance()->ToggleWireFrame();
    }
    else if(TE::Controller::Instance()->GetKeyDown(TE::Keys::F1))
    {
        _useOrbit = !_useOrbit;

        if(!_useOrbit)
        {
            TE::OpenGLGameWindow::Instance()->SetCamera(_fpsCamera);
            TE::OpenGLGameWindow::Instance()->DisableMouseCursor();
        }
        else
        {
            TE::OpenGLGameWindow::Instance()->SetCamera(_orbitCamera);
            TE::OpenGLGameWindow::Instance()->EnableMouseCursor();
        }
    }

    TM::Vector4 viewPos;

    if(_useOrbit)
    {
        viewPos = _orbitCamera->GetPosition();

        if(TE::Controller::Instance()->GetKeyHeld(TE::LEFT_MOUSE))
        {
            _orbitCamera->Orbit();
        }

        if(TE::Controller::Instance()->GetKeyHeld(TE::RIGHT_MOUSE))
        {
            _orbitCamera->Zoom();
        }
    }
    else
    {
        viewPos = _fpsCamera->GetPosition();

        if(TE::Controller::Instance()->GetKeyHeld(TE::W))
        {
            _fpsCamera->v_Move(_fpsCamera->GetLookVector()); //forward
        }
        else if(TE::Controller::Instance()->GetKeyHeld(TE::S))
        {
            _fpsCamera->v_Move(_fpsCamera->GetLookVector() * -1.0f); //back
        }
        
        if(TE::Controller::Instance()->GetKeyHeld(TE::D))
        {
            _fpsCamera->v_Move(_fpsCamera->GetRightVector()); //right
        }
        else if(TE::Controller::Instance()->GetKeyHeld(TE::A))
        {
            _fpsCamera->v_Move(_fpsCamera->GetRightVector() * -1.0f); //left
        }

        if(TE::Controller::Instance()->GetKeyHeld(TE::SPACE))
        {
            _fpsCamera->v_Move(_fpsCamera->GetUpVector()); //up
        }
        else if(TE::Controller::Instance()->GetKeyHeld(TE::LSHIFT))
        {
            _fpsCamera->v_Move(_fpsCamera->GetUpVector() * -1.0f); //down
        }
    }

    //Move Light Code
    _lightMovAngle += TM::Timer::Instance()->DeltaTime() * 50.0f;
    _light->SetPositionX(8.0f * sin(RADIAN(_lightMovAngle)));
    
    TM::Point lightPos = _light->GetPosition();

    //Update view Position
    Level::SetObjectUniforms("view_position", viewPos);

    //Update light Position
    Level::SetObjectUniforms("light.position", lightPos);
}

*/