#if DEBUG
#pragma comment(lib, "Tempest_Win32_Debug.lib")
#pragma comment(lib, "Project_Boxes_Win32_Debug.lib")
#else
#pragma comment(lib, "Tempest_Win32_Release.lib")
#pragma comment(lib, "Project_Boxes_Win32_Debug.lib")
#endif

#include "stdafx.h"
#include <Engine/Atom.h>
#include <Engine/ErrorManager.h>
#include <Engine/Timer.h>
#include <Engine/LevelManager.h>
#include <Engine/Input.h>
#include <Engine/OpenGLGameWindow.h>
#include <Engine/TextureManager.h>
#include <Engine/FontManager.h>
#include <Engine/Driver.h>
#include <Engine/Color.h>
#include <Engine/Shader.h>
#include <Engine/AudioManager.h>
#include <Engine/AudioSource.h>
#include <Engine/AudioClip.h>

namespace TE = Tempest;

#include "Boxes/Factory.h"
#include "Game/MovingBoxes.h"
#include "Game/Demo3D.h"


int main(void)
{
//=====Window Parameter Constants=====
    S32 wndWidth = 1024;
    S32 wndHeight = 768;
    string wndTitle = "Tempest Demo";
    bool wndFullScreen = false;
    bool useOpenGL = true; 


    TE::Driver::Instance()->Init(wndWidth, wndHeight, wndTitle, wndFullScreen);

    TE::AudioManager::Instance();
    TE::ErrorManager::Instance()->DisplayErrors();

//=====Pre-Load Assets=====	
    TE::TextureManager::Instance()->LoadTexture(100, "./Assets/Textures/Boxes/red_box_32_32.png");
    TE::TextureManager::Instance()->LoadTexture(101, "./Assets/Textures/Boxes/green_box_32_32.png");
    TE::TextureManager::Instance()->LoadTexture(102, "./Assets/Textures/Boxes/blue_box_32_32.png");
    TE::TextureManager::Instance()->LoadTexture(103, "./Assets/Textures/Environmental/brick_wall_v1.png");
    TE::TextureManager::Instance()->LoadTexture(300, "./Assets/Textures/Ballistics/cannon.png");
    TE::TextureManager::Instance()->LoadTexture(301, "./Assets/Textures/Ballistics/bullet_v2.png");
    TE::TextureManager::Instance()->LoadTexture(302, "./Assets/Textures/Ballistics/artillery_v1.png");
    TE::TextureManager::Instance()->LoadTexture(303, "./Assets/Textures/Ballistics/missile_v1.png");
    TE::TextureManager::Instance()->LoadTexture(304, "./Assets/Textures/Ballistics/fireball_v1.png");
    TE::TextureManager::Instance()->LoadTexture(305, "./Assets/Textures/Ballistics/lazer_v1.png");
    TE::TextureManager::Instance()->LoadTexture(306, "./Assets/Textures/Ballistics/grenade_v1.png");
    TE::TextureManager::Instance()->LoadTexture(500, "./Assets/Textures/Course/crate.jpg");
    TE::TextureManager::Instance()->LoadTexture(501, "./Assets/Textures/Course/woodcrate_diffuse.jpg");
    TE::TextureManager::Instance()->LoadTexture(502, "./Assets/Textures/Course/robot_diffuse.jpg");
    TE::TextureManager::Instance()->LoadTexture(503, "./Assets/Textures/Course/bunny_diffuse.jpg");
    TE::TextureManager::Instance()->LoadTexture(504, "./Assets/Textures/Course/tile_floor.jpg");

    TE::ErrorManager::Instance()->DisplayErrors();

    TE::FontManager::Instance()->LoadFont(100, "ariel", "./Assets/Fonts/arial.ttf", 18);
    TE::FontManager::Instance()->LoadFont(101, "bank_gothic", "./Assets/Fonts/bank_gothic.ttf", 18);

    TE::ErrorManager::Instance()->DisplayErrors();

    TE::AudioManager::Instance()->SetListener();

    shared_ptr<TE::AudioClip> skate = make_shared<TE::AudioClip>();
    skate->LoadWAV2("./Assets/Audio/Komiku_04_Skate.wav");

    TE::ErrorManager::Instance()->DisplayErrors();

    shared_ptr<TE::AudioClip> battle = make_shared<TE::AudioClip>();
    battle->LoadWAV2("./Assets/Audio/Komiku_07_Battle_of_Pogs.wav");
    
    shared_ptr<TE::AudioSource> background = make_shared<TE::AudioSource>();
    background->AddClip(skate);
    
    shared_ptr<TE::AudioSource> movingBoxesBackground = make_shared<TE::AudioSource>();
    movingBoxesBackground->AddClip(battle);

    TE::ErrorManager::Instance()->DisplayErrors();

    TE::AudioManager::Instance()->AddClip(1, skate);
    TE::AudioManager::Instance()->AddClip(2, battle);
    TE::AudioManager::Instance()->AddSource(1, background);
    TE::AudioManager::Instance()->AddSource(2, movingBoxesBackground);

    TE::ErrorManager::Instance()->DisplayErrors();


    //=====Add Levels=====
    // Removed for now. These will be used again when the Main Menu has been refactored or when there is a better way 
    // to switch between levels. 
/*
    shared_ptr<SplashScreen> splashScreen = make_shared<SplashScreen>();
    TE::Driver::Instance()->SetActiveLevel(splashScreen);
    
    shared_ptr<MainMenu> mainMenu = make_shared<MainMenu>();
    mainMenu->v_Init();
    TE::LevelManager::Instance()->Add(mainMenu);

    p_SplashScreen splashScreen = make_shared<SplashScreen>();
    splashScreen->v_Init();
    
    p_TiledTest level = make_shared<TiledTest>();
    level->v_Init();
*/

    p_MovingBoxes boxes = make_shared<MovingBoxes>();
    boxes->SetFactory(make_shared<Boxes::Factory>());
    // Do not Init in order to prevent two levels being loaded at the same time. 
    boxes->v_Init("./Assets/Levels/moving_boxes.xml");

    TE::ErrorManager::Instance()->DisplayErrors();

    p_Demo3D demo3d = make_shared<Demo3D>();
    demo3d->SetFactory(make_shared<Boxes::Factory>());
    //demo3d->v_Init();

    TE::ErrorManager::Instance()->DisplayErrors();

    TE::Driver::Instance()->SetActiveLevel(boxes);
    //TE::Driver::Instance()->SetActiveLevel(demo3d);
    
    if(TE::ErrorManager::Instance()->DisplayErrors())
    {
        TE::Driver::Instance()->End();
    }

    while (TE::Driver::Instance()->Running()) 
    {
        TE::Driver::Instance()->DisplayFPS();
        TE::Driver::Instance()->Render();
        TE::Driver::Instance()->Update();
        
        if(TE::ErrorManager::Instance()->DisplayErrors())
        {
            TE::Driver::Instance()->End();
        }

    }
    
    TE::Driver::Instance()->ShutDown();
}
