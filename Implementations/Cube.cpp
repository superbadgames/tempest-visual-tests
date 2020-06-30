#include "stdafx.h"
#include <Boxes/Cube.h>

using namespace Boxes;

//==========================================================================================================================
//
//Constructors	 	
//
//==========================================================================================================================
Cube::Cube(void)
:
_rotateRight(true),
_rotateLeft(false),
_rotateUp(false),
_rotateDown(false),
_angle(0),
_defaultShaderID(101)
{
    std::vector<TE::ShaderData> shaderData;

    TE::ShaderData vs;
    vs.filePath = "./Assets/Shaders/lighting_directional_vertex.glsl";
    vs.type = TE::ShaderType::VERTEX;
    shaderData.push_back(vs);

    TE::ShaderData fs;
    fs.filePath = "./Assets/Shaders/lighting_directional_fragment.glsl";
    fs.type = TE::ShaderType::FRAGMENT;
    shaderData.push_back(fs);

    TE::ShaderManager::Instance()->LoadShader(_defaultShaderID, shaderData);
}

Cube::~Cube(void)
{  }

//==========================================================================================================================
//
//Virtual Functions
//
//==========================================================================================================================
void Cube::v_Update(void)
{
    DefaultUpdate();
}

//==========================================================================================================================
//
//Functions
//
//==========================================================================================================================
void Cube::InitCube(string filePath)
{
    SetShader(TE::ShaderManager::Instance()->GetShader(_defaultShaderID));	

    _mesh->LoadOBJ(filePath);
}

void Cube::InitCube(string meshFilePath, U32 shaderID)
{
    SetShader(TE::ShaderManager::Instance()->GetShader(shaderID));

    _mesh->LoadOBJ(meshFilePath);
}

void Cube::InitCube(void)
{
    SetShader(TE::ShaderManager::Instance()->GetShader(_defaultShaderID));	

    _mesh->AddVertex(TE::Vertex(TM::Point4(-1.0f, 1.0f, 1.0f, 1.0f), 0.0f, 1.0f)); 	//Front Top Left        0
    _mesh->AddVertex(TE::Vertex(TM::Point4(1.0f, 1.0f, 1.0f, 1.0f), 1.0f, 1.0f)); 	//Front Top Right 		1 
    _mesh->AddVertex(TE::Vertex(TM::Point4(1.0f, -1.0f, 1.0f, 1.0f), 1.0f, 0.0f));	//Front Bottom Right	2
    _mesh->AddVertex(TE::Vertex(TM::Point4(-1.0f, -1.0f, 1.0f, 1.0f), 0.0f, 0.0f));	//Front Bottom Left		3

    _mesh->AddVertex(TE::Vertex(TM::Point4(1.0f, 1.0f, -1.0f, 1.0f), 0.0f, 1.0f)); 	//Back Top Left        	4
    _mesh->AddVertex(TE::Vertex(TM::Point4(-1.0f, 1.0f, -1.0f, 1.0f), 1.0f, 1.0f)); 	//Back Top Right 		5 
    _mesh->AddVertex(TE::Vertex(TM::Point4(-1.0f, -1.0f, -1.0f, 1.0f), 1.0f, 0.0f));	//Back Bottom Right		6
    _mesh->AddVertex(TE::Vertex(TM::Point4(1.0f, -1.0f, -1.0f, 1.0f), 0.0f, 0.0f));	//Back Bottom Left		7

    _mesh->AddVertex(TE::Vertex(TM::Point4(1.0f, 1.0f, 1.0f, 1.0f), 0.0f, 1.0f)); 	//Right Top Left        8
    _mesh->AddVertex(TE::Vertex(TM::Point4(1.0f, 1.0f, -1.0f, 1.0f), 1.0f, 1.0f)); 	//Right Top Right 		9 
    _mesh->AddVertex(TE::Vertex(TM::Point4(1.0f, -1.0f, -1.0f, 1.0f), 1.0f, 0.0f));	//Right Bottom Right	10
    _mesh->AddVertex(TE::Vertex(TM::Point4(1.0f, -1.0f, 1.0f, 1.0f), 0.0f, 0.0f));	//Right Bottom Left		11

    _mesh->AddVertex(TE::Vertex(TM::Point4(-1.0f, 1.0f, -1.0f, 1.0f), 0.0f, 1.0f)); 	//Left Top Left        	12
    _mesh->AddVertex(TE::Vertex(TM::Point4(-1.0f, 1.0f, 1.0f, 1.0f), 1.0f, 1.0f)); 	//Left Top Right 		13
    _mesh->AddVertex(TE::Vertex(TM::Point4(-1.0f, -1.0f, 1.0f, 1.0f), 1.0f, 0.0f));	//Left Bottom Right		14
    _mesh->AddVertex(TE::Vertex(TM::Point4(-1.0f, -1.0f, -1.0f, 1.0f), 0.0f, 0.0f));	//Left Bottom Left		15

    _mesh->AddVertex(TE::Vertex(TM::Point4(-1.0f, -1.0f, 1.0f, 1.0f), 0.0f, 1.0f)); 	//Bottom Top Left       16
    _mesh->AddVertex(TE::Vertex(TM::Point4(1.0f, -1.0f, 1.0f, 1.0f), 1.0f, 1.0f)); 	//Bottom Top Right 		17 
    _mesh->AddVertex(TE::Vertex(TM::Point4(1.0f, -1.0f, -1.0f, 1.0f), 1.0f, 0.0f));	//Bottomn Bottom Right	18
    _mesh->AddVertex(TE::Vertex(TM::Point4(-1.0f, -1.0f, -1.0f, 1.0f), 0.0f, 0.0f));	//Bottomn Bottom Left	19

    _mesh->AddVertex(TE::Vertex(TM::Point4(-1.0f, 1.0f, -1.0f, 1.0f), 0.0f, 1.0f)); 	//Top Top Left        	20
    _mesh->AddVertex(TE::Vertex(TM::Point4(1.0f, 1.0f, -1.0f, 1.0f), 1.0f, 1.0f)); 	//Top Top Right 		21
    _mesh->AddVertex(TE::Vertex(TM::Point4(1.0f, 1.0f, 1.0f, 1.0f), 1.0f, 0.0f));		//Top Bottom Right		22
    _mesh->AddVertex(TE::Vertex(TM::Point4(-1.0f, 1.0f, 1.0f, 1.0f), 0.0f, 0.0f));	//Top Bottom Left		23

    _mesh->SetIndices(std::vector<U32>
    {
        0, 1, 2, //Front
        0, 2, 3,
        4, 5, 6, //Back
        4, 6, 7,
        8, 9, 10, //Right
        8, 10, 11,
        12, 13, 14, //Left
        12, 14, 15,
        16, 17, 18, //Bottom
        16, 18, 19,
        20, 21, 22, //Top
        20, 22, 23
    });

    _mesh->InitOpenGLData();

}