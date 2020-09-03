#include "stdafx.h"
#include "Game/MovingBoxes.h"

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
        TE::Driver::Instance()->End();
        return;
    }
}
