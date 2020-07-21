#include "stdafx.h"
#include <Boxes/BoxesFactory.h>

using namespace Boxes;

BoxesFactory::BoxesFactory(void)
{

}

BoxesFactory::~BoxesFactory(void)
{

}

TE::p_GameObject2D BoxesFactory::v_Create2D(string type, const TM::Point2& pos, F32 scale, F32 pixelSize, U32 textureID)
{
    TE::ErrorManager::Instance()->SetError(TE::APPLICATION, "BoxesFactory::Create unable to create object with type " + type);
    return nullptr;
}

TE::p_GameObject3D BoxesFactory::v_Create3D(string type, const TM::Point3& pos, F32 scale, F32 pixelSize, U32 textureID)
{
    TE::ErrorManager::Instance()->SetError(TE::APPLICATION, "BoxesFactory::Create unable to create object with type " + type);
    return nullptr;
}