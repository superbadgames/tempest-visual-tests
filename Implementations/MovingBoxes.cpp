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
        TE::Engine::Instance()->End();
        return;
    }

    _DefaultUpdate();

    /*
      

    if(TE::Input::Instance()->GetKeyDown(TE::U))
    {
        if(_updateText.GetText() == _message1)
        {
            _updateText.AddText(_message2);
        }
        else
        {
            _updateText.AddText(_message1);
        }
    }

    CheckBoxEdge(_redbox);
    CheckBoxEdge(_greenbox);
    CheckBoxEdge(_bluebox);

    CheckCollisions();*/
}//End update

//==========================================================================================================================
//
//MovingBoxes functions
//
//==========================================================================================================================	
//void MovingBoxes::CheckBoxEdge(p_Box b)
//{
//    TM::Point2 tempPos = b->GetPosition();
//
//    //Righ/Left check
//    if(tempPos.x >= _right) 
//    {
//        tempPos.x = _left;
//    }
//    else if(tempPos.x <= _left) 
//    {
//        tempPos.x = _right;
//    }
//    
//    //Top/Bottom check
//    if(tempPos.y >= _top) 
//    {
//        tempPos.y = _bottom;
//    }
//    else if(tempPos.y <= _bottom) 
//    {
//        tempPos.y = _top;
//    }
//
//    b->SetPosition(tempPos);
//}
//
//void MovingBoxes::CheckCollisions(void)
//{
//
//    if(_redbox->OverlapCheck(_greenbox) || _redbox->OverlapCheck(_bluebox))
//    {
//        _redbox->OnCollide();
//    }
//
//    if(_greenbox->OverlapCheck(_redbox) || _greenbox->OverlapCheck(_bluebox))
//    {
//        _greenbox->OnCollide();
//    }
//
//    if(_bluebox->OverlapCheck(_redbox) || _bluebox->OverlapCheck(_greenbox))
//    {
//        _bluebox->OnCollide();
//    }
//
//}