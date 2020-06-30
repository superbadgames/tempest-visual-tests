#pragma once

//=====Engine Includes=====
#include "stdafx.h"
#include <Engine/Atom.h>
#include <Engine/Factory.h>
#include <Engine/GameObject2D.h>
#include <Engine/TextureManager.h>

namespace TE = Tempest;

//===== Boxes Includes =====
#include <Boxes/Box.h>
#include <Boxes/Cannon.h>
#include <Boxes/Projectile.h>
#include <Boxes/Cube.h>

namespace Boxes
{
    class BoxesFactory : public TE::Factory 
    {
    public:
        BoxesFactory(void);

        ~BoxesFactory(void);

        TE::p_GameObject2D v_Create(string type, const TM::Point2& pos, F32 scale, F32 pixelSize, U32 textureID) final;

    private:

    };//end Class
    typedef shared_ptr<BoxesFactory> p_ProjectFactory;
}//end Namespace
