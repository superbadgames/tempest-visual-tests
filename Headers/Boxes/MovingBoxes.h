/*-------------------------------------------------------------------
MovingBoxes is the whole of phase one for Killer Wave Entertainment.
MovingBoxes will move, and will be able to be toggled active. That is 
pretty much it.

This is not free to use, and cannot be used without the express permission
of Layer8Games? I don't know my own name these days. 

Written by Maxwell Miller
---------------------------------------------------------------------*/
#pragma once

//Killer1 Includes
#include "stdafx.h"
#include <Engine/Atom.h>
#include <Engine/ErrorManager.h>
#include <Engine/LevelManager.h>
#include <Engine/Driver.h>
#include <Engine/Level.h>
#include <Engine/Input.h>
#include <Engine/TextureManager.h>
#include <Engine/FontManager.h>
#include <Engine/Text.h>
#include <Engine/Color.h>
#include <Engine/Timer.h>
#include <Engine/AudioManager.h>

#include <Boxes/Box.h>
#include <Boxes/DataBases.h>
#include <Boxes/BoxesFactory.h>

#include <iostream>

namespace TE = Tempest;
namespace TM = TempestMath;

namespace Boxes 
{
    class MovingBoxes : public TE::Level 
    {
    public:
        MovingBoxes(void);
        
        ~MovingBoxes(void) final;

        void v_Update(void);
        
        //void CheckBoxEdge(p_Box b);

        //void CheckCollisions(void);

    private:
        U32 _redBoxID;
        U32 _greenBoxID;
        U32 _blueBoxID;
    };
    typedef shared_ptr<MovingBoxes> p_MovingBoxes;
}//End namespace