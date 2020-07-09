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
    if(strcmp(type.c_str(), "box") == 0)
    {
        p_Box box = make_shared<Box>();
        box->SetPosition(pos);
        box->SetTexture(TE::TextureManager::Instance()->GetTexture(textureID));
        box->SetDefaultPixelSize(pixelSize);
        box->SetScale(scale);

        return box;
    }
    else
    {
        TE::ErrorManager::Instance()->SetError(TE::APPLICATION, "BoxesFactory::Create unable to create object with type " + type);
        return nullptr;
    }
}

TE::p_GameObject3D BoxesFactory::v_Create3D(string type, const TM::Point3& pos, F32 scale, F32 pixelSize, U32 textureID)
{
    if(strcmp(type.c_str(), "cube") == 0)
    {
        p_Cube cube = make_shared<Cube>();
        
        return cube;
    }
    else
    {
        TE::ErrorManager::Instance()->SetError(TE::APPLICATION, "BoxesFactory::Create unable to create object with type " + type);
        return nullptr;
    }
}