#include "stdafx.h"
#include <Boxes/MainMenu.h>

using namespace Boxes;

//==========================================================================================================================
//
//Constructors
//
//==========================================================================================================================
MainMenu::MainMenu(void) 
: 
_selector(ProjectFactory::Instance()->MakeBox()),
_menu(),
_menuItemFont(),
_mainTitle()
{  }

MainMenu::~MainMenu(void) 
{  }	

//==========================================================================================================================
//
//Virtual Functions
//
//==========================================================================================================================
void MainMenu::v_Init(void)
{
    Level::SetID(MAIN_MENU_ID);
    Level::SetWidth(TE::Engine::Instance()->GetScreenWidth());
    Level::SetHeight(TE::Engine::Instance()->GetScreenHeight());
    Level::SetBackgroundColor(TE::Color(0.2f, 0.2f, 0.2f));

    DefaultInit();

    F32 top = TE::Engine::Instance()->GetScreenTop();

    _selector->SetColor(TE::Color(1.0f, 0.0f, 0.0f));
    _selector->SetTexture(TE::TextureManager::Instance()->GetTexture(100));
    _selector->SetScale(15.0f, 15.0f);

    _mainTitle.SetFont(TE::FontManager::Instance()->GetFont(101));
    _mainTitle.AddText("BOXES vs TRIANGLES");

    _menu.SetPosition(-_mainTitle.GetWidth(), top - (top * 0.1f));
    _menu.SetTitleOffset(_mainTitle.GetWidth() / 2.0f, -top * 0.333f);
    _menu.SetItemOffset(0.0f, -60.0f);
    _menu.SetSelectorOffset(-50.0f, 0.0f);
    _menu.SetWrap(true);

    TE::MenuItem level1 { };
    level1.text = shared_ptr<TE::Text>(new TE::Text("Moving Boxes", TE::FontManager::Instance()->GetFont(100)));
    level1.Action = &MenuItem_Level1Action;

    TE::MenuItem ballistics { };
    ballistics.text = shared_ptr<TE::Text>(new TE::Text("Ballistic", TE::FontManager::Instance()->GetFont(100)));
    ballistics.Action = &MenuItem_BallisticsAction;

    //TE::MenuItem firework { };
    //firework.text = shared_ptr<TE::Text>(new TE::Text("Firework Demo", TE::FontManager::Instance()->GetFont(100)));
    //firework.Action = &MenuItem_FireworkAction;

    //TE::MenuItem springs { };
    //springs.text = shared_ptr<TE::Text>(new TE::Text("Springs Demo", TE::FontManager::Instance()->GetFont(100)));
    //springs.Action = &MenuItem_SpringsAction;

    /*TE::MenuItem opengl { };
    opengl.text = shared_ptr<TE::Text>(new TE::Text("3D Level", TE::FontManager::Instance()->GetFont(100)));
    opengl.Action = &MenuItem_OpenglAction;*/


    Level::AddObjectToLevel(_selector);
    Level::AddTextToLevel(_mainTitle);
    Level::AddTextToLevel(level1.text);
    Level::AddTextToLevel(ballistics.text);
    //Level::AddTextToLevel(firework.text);
    //Level::AddTextToLevel(springs.text);
    //Level::AddTextToLevel(opengl.text);

    _menu.SetSelector(_selector);
    _menu.SetTitle(_mainTitle);
    _menu.AddItem(level1);
    _menu.AddItem(ballistics);
    //_menu.AddItem(firework);
    //_menu.AddItem(springs);
    //_menu.AddItem(opengl);

}

void MainMenu::v_Update(void)
{
    TE::AudioManager::Instance()->PlaySource(1);
    if(TE::Controller::Instance()->GetKeyDown(TE::Keys::ESCAPE))
    {
        TE::AudioManager::Instance()->StopSource(1);
        TE::Engine::Instance()->End();
    }

    if(TE::Controller::Instance()->GetKeyDown(TE::Keys::UP_ARROW))
    {
        _menu.MoveSelectorUp();
    }	

    if(TE::Controller::Instance()->GetKeyDown(TE::Keys::DOWN_ARROW))
    {
        _menu.MoveSelectorDown();
    }


    if(TE::Controller::Instance()->GetKeyDown(TE::Keys::ENTER))
    {
        TE::AudioManager::Instance()->StopSource(1);
        _menu.CallSelectedAction();
    }
}