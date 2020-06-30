#include "stdafx.h"
#include <Boxes/Cannon.h>

using namespace Boxes;

//==========================================================================================================================
//
//Constructors
//
//==========================================================================================================================
Cannon::Cannon(void) 
: 
_movementSpeed(1.0f),
_bottomBoundary(0.0f),
_topBoundary(700.0f),
_upDirection(0.0f, 1.0f),
_downDirection(0.0f, -1.0f),
_projectilePool()
{
    Init();
}

Cannon::~Cannon(void)
{
    _projectilePool.clear();
}
//==========================================================================================================================
//
//Update
//
//==========================================================================================================================
void Cannon::v_Update(void)
{
    //_forceRegistry.UpdateForces();

    //std::cout << ""

    F32 yPos = GetPosition().y;

    if(yPos > _bottomBoundary && yPos < _topBoundary)
    {
        if(TE::Input::Instance()->GetKeyHeld(TE::W))
        {
            AddPosition(_upDirection * _movementSpeed * TM::Timer::Instance()->DeltaTime());
        }
        else if(TE::Input::Instance()->GetKeyHeld(TE::S))
        {
            AddPosition(_downDirection * _movementSpeed * TM::Timer::Instance()->DeltaTime());
        }
    }
    else
    {
        if(yPos <= _bottomBoundary)
        {
            AddPosition(_upDirection * _movementSpeed);
        }
        else if(yPos >= _topBoundary)
        {
            AddPosition(_downDirection * _movementSpeed);
        }
    }

    DefaultUpdate();
}

void Cannon::Fire(const TM::Vector2& heading, ProjectileType type)
{
    for(auto projectile : _projectilePool)
    {
        if(!projectile->GetActive())
        {
            projectile->SetPosition(GetPosition());
            projectile->SetType(type);
            projectile->AddScaledVelocity(heading, projectile->GetSpeedScale());
            projectile->SetActive(true);
            return;
        }
    }
}