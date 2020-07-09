#include "stdafx.h"
#include <Boxes/Box.h>
#include <iostream>
using namespace Boxes;


Box::Box(void)
    :
    _toggle(false),
    _speed(150.0f),
    _collisionBuffer(10.0f),
    _direction(0.0f)
{
    Init();
}

void Box::v_Update(void)
{
    CheckInputToggleOnOff();
    CheckDirectionalInput();
    UpdatePosition();
    BorderCheck();
    DefaultUpdate();
}

bool Box::OverlapCheck(const shared_ptr<Box> other)
{
    return _boundingBox.TestCollision(other->GetBounding());
}

void Box::v_OnCollide(string otherObjectID)
{
    TE::p_GameObject2D otherObject = TE::GameObjectManager::Instance()->GetDynamicObject(otherObjectID);
    if(otherObject != nullptr)
    {
        _direction = -_direction;
        return;
    }
    
    AddPosition(-_direction * _collisionBuffer);
    _direction = 0.0f;
}

void Box::CheckInputToggleOnOff(void)
{
    if(TE::Input::Instance()->GetKeyDown(TE::Keys::ONE))
    {
        if(std::strcmp(_name.c_str(), "red") == 0)
        {
            On();
        }
        else
        {
            Off();
        }
    }
    else if(TE::Input::Instance()->GetKeyDown(TE::Keys::TWO)) 
    { 
        if(std::strcmp(_name.c_str(), "green") == 0)
        {
            On();
        }
        else
        {
            Off();
        }
    }
    else if(TE::Input::Instance()->GetKeyDown(TE::Keys::THREE)) 
    { 
        if(std::strcmp(_name.c_str(), "blue") == 0)
        {
            On();
        }
        else
        {
            Off();
        }
    }
}

void Box::CheckDirectionalInput(void)
{
    if(_toggle)
    {
        bool up = TE::Input::Instance()->GetKeyDown(TE::UP_ARROW);
        bool down = TE::Input::Instance()->GetKeyDown(TE::DOWN_ARROW);
        bool left = TE::Input::Instance()->GetKeyDown(TE::LEFT_ARROW);
        bool right = TE::Input::Instance()->GetKeyDown(TE::RIGHT_ARROW);

        if(up)	  
        { 
            _direction.Set(0.0f, 1.0f);
        }
        else if(down)  
        { 
            _direction.Set(0.0f, -1.0f);
        }
        else if(right) 
        { 
            _direction.Set(1.0f, 0.0f);
        }
        else if(left)  
        { 
            _direction.Set(-1.0f, 0.0f);
        }
    
        if(up && right)
        { 
            _direction.Set(1.0f, 1.0f);	
        }
        else if(up && left)
        {
            _direction.Set(-1.0f, 1.0f);
        }
        else if(down && right) 
        { 
            _direction.Set(1.0f, -1.0f);
        }
        else if(down && left)  
        { 
            _direction.Set(-1.0f, -1.0f);
        }

        if(TE::Input::Instance()->GetKeyHeld(TE::E))
        {
            AddOrientation(1.0f);
        }
        else if(TE::Input::Instance()->GetKeyHeld(TE::Q))
        {
            AddOrientation(-1.0f);
        }
        
        if(TE::Input::Instance()->GetKeyDown(TE::SPACE))
        {
            _direction.Set(0.0f, 0.0f);
        }
    }
}

void Box::UpdatePosition(void)
{
    AddPosition(_direction * TM::Timer::Instance()->DeltaTime() * _speed);
}

void Box::BorderCheck(void)
{
    if(GetPosition().x >= static_cast<real>(_level->GetRightBorder()))
    {
        SetPositionX(static_cast<real>(_level->GetLeftBorder()));
    }
    else if(GetPosition().x <= static_cast<real>(_level->GetLeftBorder()))
    {
        SetPositionX(static_cast<real>(_level->GetRightBorder()));
    }
    
    if(GetPosition().y >= static_cast<real>(_level->GetTopBorder()))
    {
        SetPositionY(static_cast<real>(_level->GetBottomBorder()));
    }
    else if(GetPosition().y <= static_cast<real>(_level->GetBottomBorder()))
    {
        SetPositionY(static_cast<real>(_level->GetTopBorder()));
    }
}

void Box::On(void)
{
    _toggle = true;
}

void Box::Off(void)
{
    _toggle = false;
}