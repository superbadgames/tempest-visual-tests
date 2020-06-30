#pragma once

//=====Engine Includes=====
#include "stdafx.h"
#include <Engine/Atom.h>
#include <Engine/Engine.h>
#include <Engine/Level.h>
#include <Engine/Controller.h>

namespace TE = Tempest;

namespace Boxes
{

    class DirectXTests : public TE::Level
    {
    public:
        //==========================================================================================================================
        //
        //Constructors	 	
        //
        //==========================================================================================================================
        DirectXTests(void);

        ~DirectXTests(void);

        //==========================================================================================================================
        //
        //Functions
        //
        //==========================================================================================================================
        void v_Init(void) final;

        void v_Update(void) final;
    private:

    };//end Class
    typedef shared_ptr<DirectXTests> p_DirectXTests;
}