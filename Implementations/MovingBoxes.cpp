#include "stdafx.h"
#include <Boxes/MovingBoxes.h>

using namespace Boxes;

//=============================================================================
//
//Constructor
//
//=============================================================================
MovingBoxes::MovingBoxes(void)
    :
    _redBoxID(0),
    _greenBoxID(0),
    _blueBoxID(0)
{  }

MovingBoxes::~MovingBoxes(void) 
{  }


void MovingBoxes::v_Update(void)
{
    TE::AudioManager::Instance()->PlaySource(2);

    if(TE::Input::Instance()->GetKeyDown(TE::Keys::ESCAPE))
    {
        TE::AudioManager::Instance()->StopSource(2);
        //TE::Engine::Instance()->SetActiveLevel(TE::LevelManager::Instance()->GetLevel(MAIN_MENU_ID));
        TE::Driver::Instance()->End();
        return;
    }
}

void MovingBoxes::v_Init(string path)
{
    _DefaultInit(path);
}