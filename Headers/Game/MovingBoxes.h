#pragma once

#include "stdafx.h"
#include <Engine/Atom.h>
#include <Engine/Driver.h>
#include <Engine/Level.h>
#include <Engine/Input.h>
#include <Engine/AudioManager.h>

namespace TE = Tempest;
namespace TM = TempestMath;



class MovingBoxes : public TE::Level 
{
public:
    MovingBoxes(void);
        
    ~MovingBoxes(void) final;

    void v_Update(void);

private:
    U32 _redBoxID;
    U32 _greenBoxID;
    U32 _blueBoxID;
};
typedef shared_ptr<MovingBoxes> p_MovingBoxes;
