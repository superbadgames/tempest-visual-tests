#include "stdafx.h"
#include "Game/Ballistics.h"


//=============================================================================
//
//Constructor
//
//=============================================================================
Ballistics::Ballistics(void) 
:
_poolSize(10),
_activeProjectileType(Boxes::ProjectileType::BULLET),
_levelTitle(),
_cannon(nullptr),
p_gravityForce(nullptr)
{
    p_gravityForce = TP::PhysicsFactory::Instance()->MakeGravityForce();
    p_gravityForce->Set(0.0f, -100.0f, 0.0f);
}

Ballistics::~Ballistics(void)
{
    _cannon.reset();
}

//=============================================================================
//
//InitLevel
//
//=============================================================================
void Ballistics::v_Init(void)
{
    SetID(BALLISTICS_ID);
    SetWidth(TE::Driver::Instance()->GetScreenWidth());
    SetHeight(TE::Driver::Instance()->GetScreenHeight());
    SetBackgroundColor(TE::Color(0.2f, 0.2f, 0.2f));

    _DefaultInit();

    F32 left = TE::Driver::Instance()->GetScreenLeft();
    F32 bottom = TE::Driver::Instance()->GetScreenBottom();
    F32 top = TE::Driver::Instance()->GetScreenTop();

    _levelTitle.SetFont(TE::FontManager::Instance()->GetFont(100));
    _levelTitle.AddText("BALLISTICS");
    _levelTitle.SetPosition(TM::Point2(-_levelTitle.GetWidth(), top - (top * 0.1f)));

    //=====Setup GameObjects=====
    //TODO::Make the cannon using the factory. You may have to teach it how to make a cannon.
    //minus because left and bottom are already negative
    _cannon->SetPosition(left - (left / 10.0f), bottom - (bottom / 10.0f));
    _cannon->SetScale(5.0f);
    _cannon->SetMovementSpeed(120.0f);
    _cannon->SetTopBoundary(top);
    _cannon->SetBottomBoundary(bottom);
    _cannon->SetTexture(TE::TextureManager::Instance()->GetTexture(300));
    

    
    for(U32 i = 0; i < _poolSize; ++i)
    {
        //TODO::Make a projectile from the factory called p.
        //TODO::Set the scale of the projectile.
        //TODO:: Called Cannon::AddToPool, registering the projectile with the cannon.
        //TODO:: Add the projectile to the GameObjectManager.
        //TODO:: Register the projectile with a gravity force.
    }
}

//=============================================================================
//
//Update
//
//=============================================================================
void Ballistics::v_Update(void)
{
    if(TE::Input::Instance()->GetKeyDown(TE::Keys::ESCAPE)) 
    { 
        TE::Driver::Instance()->SetActiveLevel(TE::LevelManager::Instance()->GetLevel(MAIN_MENU_ID));
        return;
    }

    //===== Get User Input =====
    if(TE::Input::Instance()->GetKeyDown(TE::Keys::ONE))
    {
        _activeProjectileType = Boxes::ProjectileType::BULLET;
    }
    else if(TE::Input::Instance()->GetKeyDown(TE::Keys::TWO))
    {
        _activeProjectileType = Boxes::ProjectileType::ARTILLERY;
    }
    else if(TE::Input::Instance()->GetKeyDown(TE::Keys::THREE))
    {
        _activeProjectileType = Boxes::ProjectileType::MISSILE;
    }
    else if(TE::Input::Instance()->GetKeyDown(TE::Keys::FOUR))
    {
        _activeProjectileType = Boxes::ProjectileType::FIRE_BALL;
    }
    else if(TE::Input::Instance()->GetKeyDown(TE::Keys::FIVE))
    {
        _activeProjectileType = Boxes::ProjectileType::LAZER;
    }
    else if(TE::Input::Instance()->GetKeyDown(TE::Keys::SIX))
    {
        _activeProjectileType = Boxes::ProjectileType::GRENADE;
    }

    if(TE::Input::Instance()->GetKeyDown(TE::Keys::LEFT_MOUSE)) 
    { 
        TM::Point2 input = TE::Input::Instance()->GetMouseCoordInScreen();

        TM::Vector2 heading = TM::Vector2(input - _cannon->GetPosition());

        heading.Normalize();
                
        _cannon->Fire(heading, _activeProjectileType);
    }
}