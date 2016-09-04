#ifndef MESH_BUILDER_H
#define MESH_BUILDER_H

#include "..\\Classes\\Mesh.h"
#include "..\\Classes\\Vertex.h"
#include <GL\glew.h>
#include <vector>
#include "MyMath.h"
#include "LoadOBJ.h"
#include "LoadHmap.h"
#include "..\\Classes\\SpriteAnimation.h"

/******************************************************************************/
/*!
		Class MeshBuilder:
\brief	Provides methods to generate mesh of different shapes
*/
/******************************************************************************/
class MeshBuilder
{
public:
	static Mesh* GenerateAxes(const std::string &meshName, float lengthX=0.0f, float lengthY=0.0f, float lengthZ=0.0f);
	static Mesh* GenerateCrossHair(const std::string &meshName, float colour_r = 0.8f, float colour_g = 0.8f, float colour_b = 0.8f, float length = 0.5f);
	static Mesh* GenerateQuad(const std::string &meshName, Color color, float length = 1.f);
	static Mesh* GenerateCube(const std::string &meshName, Color color, float length = 1.f);
	static Mesh* GenerateRing(const std::string &meshName, Color color, unsigned numSlice, float outerR = 1.f, float innerR = 0.f);
	static Mesh* GenerateSphere(const std::string &meshName, Color color, unsigned numStack, unsigned numSlice, float radius = 1.f);
	static Mesh* GenerateCone(const std::string &meshName, Color color, unsigned numSlice, float radius, float height);
	static Mesh* GenerateOBJ(const std::string &meshName, const std::string &file_path);
	static Mesh* GenerateText(const std::string &meshName, unsigned row, unsigned col);
	static Mesh* GenerateMinimap(const std::string &meshName, Color color, float length = 1.f);
	static Mesh* GenerateMinimapBorder(const std::string &meshName, Color color, float length = 1.f);
	static Mesh* GenerateMinimapAvatar(const std::string &meshName, Color color, float length = 1.f);
	//TSL
	static Mesh* GenerateSkyPlane(const std::string &meshName, Color color, int slices, float PlanetRadius, float AtmosphereRadius, float hTile, float vTile);
	static Mesh* GenerateTerrain(const std::string &meshName, const std::string &file_path, std::vector<unsigned char>&heightMap);
	static SpriteAnimation* GenerateSpriteAnimation(const std::string &meshName, unsigned numRow, unsigned numCol);

	//Extras
	static Mesh* GenerateCircle(const std::string &meshName, Color color, unsigned numSlices = 36); //numSizes refers to resolution
};

#endif