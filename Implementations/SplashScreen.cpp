#include "stdafx.h"
#include <Boxes/SplashScreen.h>

using namespace Boxes;
//=============================================================================
//
//Constructor
//
//=============================================================================
SplashScreen::SplashScreen(void) 
: 
_red(ProjectFactory::Instance()->MakeBox()),
_green(ProjectFactory::Instance()->MakeBox()),
_blue(ProjectFactory::Instance()->MakeBox()),
_mainTitle()
{
    Level::SetID(SPLASH_SCREEN_ID);
}
 
SplashScreen::~SplashScreen(void) 
{

}

//=============================================================================
//
//InitLevel
//
//=============================================================================
void SplashScreen::v_Init(void) 
{
    Level::SetWidth(TE::Engine::Instance()->GetScreenWidth());
    Level::SetHeight(TE::Engine::Instance()->GetScreenHeight());
    Level::SetBackgroundColor(TE::Color(0.0f, 0.0f, 0.0f));

    DefaultInit();

    F32 left = TE::Engine::Instance()->GetScreenLeft();
    F32 right = TE::Engine::Instance()->GetScreenRight();
    F32 bottom = TE::Engine::Instance()->GetScreenBottom();
    F32 top = TE::Engine::Instance()->GetScreenTop();

    _red->SetPosition(0.0f, 0.0f);
    _red->SetTexture(TE::TextureManager::Instance()->GetTexture(100));
    _red->SetScale(25.0f, 25.0f);
    Level::AddObjectToLevel(_red);

    _green->SetPosition(left / 3.0f, top / 3.0f);
    _green->SetTexture(TE::TextureManager::Instance()->GetTexture(101));
    _green->SetScale(25.0f, 25.0f);
    _green->SetSpeed(400.0f);
    Level::AddObjectToLevel(_green);

    _blue->SetPosition(right / 3.0f, top / 3.0f);
    _blue->SetTexture(TE::TextureManager::Instance()->GetTexture(102));
    _blue->SetScale(25.0f, 25.0f);
    _blue->SetSpeed(400.0f);
    Level::AddObjectToLevel(_blue);
    
    _mainTitle.SetFont(TE::FontManager::Instance()->GetFont(100));
    _mainTitle.AddText("BOXES vs TRIANGLES");
    _mainTitle.SetPosition(TM::Point2(-_mainTitle.GetWidth(), top - (top * 0.1f)));
    Level::AddTextToLevel(_mainTitle);

    
}

//=============================================================================
//
//Update
//
//=============================================================================
void SplashScreen::v_Update(void) 
{
    TE::AudioManager::Instance()->PlaySource(1);

    if(TE::Controller::Instance()->GetKeyDown(TE::Keys::ESCAPE))
    {
        TE::Engine::Instance()->End();
    }

    TM::Point2 greenPos = _green->GetPosition();
    TM::Point2 bluePos  = _blue->GetPosition();
    F32 redWidth   = _red->GetScale().y;

    if(greenPos.y >= TE::Engine::Instance()->GetScreenBottom()) 
    {
        _green->SetDirection(0.0f, -1.0f);

        _blue->SetDirection(0.0f, -1.0f);
    }
    else if(redWidth <= 500.0f) 
    {
        _green->SetActive(false);
        _blue->SetActive(false);

        F32 size = _red->GetScale().y + TM::Timer::Instance()->DeltaTime() * 250.0f;
        _red->SetScale(size, size);
    }
    
    else 
    { 
        TE::AudioManager::Instance()->PauseSource(1);
        TE::Engine::Instance()->SetActiveLevel(TE::LevelManager::Instance()->GetLevel(MAIN_MENU_ID));
        return;
    }
}