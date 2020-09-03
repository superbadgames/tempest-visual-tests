#pragma once

#include "stdafx.h"
#include <Engine/Atom.h>
#include <Engine/Factory.h>
#include <Engine/StaticGameObject2D.h>
#include <Engine/StaticGameObject3D.h>
#include <Engine/TextureManager.h>

namespace TE = Tempest;

#include "Boxes/Box.h"
#include "Boxes/Cannon.h"
#include "Boxes/Projectile.h"

namespace Boxes
{
    class Factory : public TE::Factory 
    {
    public:
        BOXES_API Factory(void);

        BOXES_API ~Factory(void);

        BOXES_API TE::p_GameObject2D v_Create2D(string type, const TM::Point2& pos, F32 scale, F32 pixelSize, U32 textureID) final;

        BOXES_API TE::p_GameObject3D v_Create3D(string type, const TM::Point3& pos, F32 scale, F32 pixelSize, U32 textureID) final;

    private:

    };//end Class
    typedef shared_ptr<Factory> p_ProjectFactory;
}//end Namespace
