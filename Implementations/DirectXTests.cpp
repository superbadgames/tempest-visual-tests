#include "stdafx.h"
#include <Boxes/DirectXTests.h>

using namespace Boxes;

DirectXTests::DirectXTests(void)
{  }

DirectXTests::~DirectXTests(void)
{  }

void DirectXTests::v_Init(void)
{

}
        
void DirectXTests::v_Update(void)
{
    if(TE::Controller::Instance()->GetKeyDown(TE::ESCAPE))
    {
        TE::Engine::Instance()->End();
    }
}