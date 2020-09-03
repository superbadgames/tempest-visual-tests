#pragma once

#include "stdafx.h"
#include <Engine/Atom.h>
#include <Engine/GameObject2D.h>
#include <Engine/Input.h>
#include <Engine/Timer.h>
#include <Engine/Vector2.h>

namespace TE = Tempest;
namespace TM = TempestMath;

#include "Boxes/Definitions.h"

namespace Boxes
{
    class Box : public TE::GameObject2D
    {
    public:
        BOXES_API Box(void);
        
        BOXES_API void v_Update(void);

        BOXES_API bool OverlapCheck(const shared_ptr<Box> other);

        BOXES_API void v_OnCollide(string otherObjectID) final;

        BOXES_API void CheckInputToggleOnOff(void);

        BOXES_API void CheckDirectionalInput(void);

        BOXES_API void UpdatePosition(void);
        
        BOXES_API void BorderCheck(void);

        BOXES_API void On(void);

        BOXES_API void Off(void);

    private:
        bool _toggle;
        F32	_speed;
        F32 _collisionBuffer;
        TM::Vector2 _direction;
    };
    typedef shared_ptr<Box> p_Box;
}//End namespace
