/*=========================================================================
The player controled object in the basic game of boxes. It will inher-
it from the GameObject class, and will define its own update and render.
It will have a controller in time that will allow a player to control 
where the box goes.

This is not free to use, and cannot be used without the express permission
of KillerWave.

Written by Maxwell Miller
=========================================================================*/
#pragma once;

//Killer1 Includes
#include "stdafx.h"
#include <Engine/Atom.h>
#include <Engine/GameObject2D.h>
#include <Engine/Input.h>
#include <Engine/Timer.h>
#include <Engine/Vector2.h>
#include <Engine/Point2.h>
#include <Engine/Color.h>
#include <Engine/AABB.h>

namespace TE = Tempest;
namespace TM = TempestMath;
namespace TC = TempestCollisions;

namespace Boxes
{
    class Box;
    typedef shared_ptr<Box> p_Box;

    class Box : public TE::GameObject2D
    {
    public:		
        Box(void);
        
        void v_Update(void);

        bool OverlapCheck(const shared_ptr<Box> other);

        void v_OnCollide(U32 otherObjectID) final;

        void CheckInputToggleOnOff(void);

        void CheckDirectionalInput(void);

        void UpdatePosition(void);
        
        void BorderCheck(void);

        void On(void);

        void Off(void);

    private:		
        bool _toggle;
        F32	_speed;
        F32 _collisionBuffer;
        TM::Vector2 _direction;
    };

}//End namespace
