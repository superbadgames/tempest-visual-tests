#pragma once

//=====Engine Includes=====
#include "stdafx.h"
#include <Engine/Atom.h>
#include <Engine/Level.h>
#include <Engine/Texture.h>
#include <Engine/OpenGLGameWindow.h>
#include <Engine/Controller.h>
#include <Engine/Engine.h>
#include <Engine/Timer.h>
#include <Engine/Camera2D.h>
#include <Engine/FPSCamera.h>
#include <Boxes/DataBases.h>
#include <Boxes/Box.h>

namespace TE = Tempest;
namespace TM = TempestMath;

namespace Boxes
{
    class TiledTest : public TE::Level
    {
    public:
        //==========================================================================================================================
        //
        //Constructors	 	
        //
        //==========================================================================================================================
        TiledTest(void);

        ~TiledTest(void);

        //==========================================================================================================================
        //
        //Functions
        //
        //==========================================================================================================================
        void v_Init(void)final;
        
        void v_Update(void) final;

        void v_Enter(void) final
        {
            
            ActivateBackgroundColor();
        }

    };//end Class
    typedef shared_ptr<TiledTest> p_TiledTest;
}
