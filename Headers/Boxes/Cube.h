#pragma once

//=====Engine Includes=====
#include "stdafx.h"
#include <Engine/Atom.h>
#include <Engine/GameObject3D.h>
#include <Engine/Vector4.h>
#include <Engine/Vertex.hpp>
#include <Engine/Color.h>
#include <Engine/Timer.h>
#include <Engine/OpenGLGameWindow.h>

namespace TE = Tempest;
namespace TM = TempestMath;

namespace Boxes
{
    class Cube;
    typedef shared_ptr<Cube> p_Cube;

    class Cube : public TE::GameObject3D
    {
    public:
//==========================================================================================================================
//
//Constructors	 	
//
//==========================================================================================================================
        Cube(void);

        ~Cube(void);
//==========================================================================================================================
//
//Virtual Functions
//
//==========================================================================================================================
        void v_Update(void);

//==========================================================================================================================
//
//Functions
//
//==========================================================================================================================
        void InitCube(string meshFilePath);

        void InitCube(string meshFilePath, U32 shaderID);

        void InitCube(void);


    private:
//==========================================================================================================================
//
//Data
//
//==========================================================================================================================
        bool		_rotateRight;
        bool 		_rotateLeft;
        bool 		_rotateUp;
        bool 		_rotateDown;
        F32 		_angle;
        U32 		_defaultShaderID;
    };//end Class
}//end Namespace