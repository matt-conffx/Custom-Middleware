/*
* Copyright (c) 2017-2022 The Forge Interactive Inc.
*
* This is a part of Ephemeris.
* This file(code) is licensed under a Creative Commons Attribution-NonCommercial 4.0 International License (https://creativecommons.org/licenses/by-nc/4.0/legalcode) Based on a work at https://github.com/ConfettiFX/The-Forge.
* You can not use this code for commercial purposes.
*
*/

#pragma once

#include "../../../../The-Forge/Common_3/Graphics/Interfaces/IGraphics.h"
#include "../../../../The-Forge/Common_3/Utilities/ThirdParty/OpenSource/EASTL/vector.h"
#include "../../../../The-Forge/Common_3/Utilities/ThirdParty/OpenSource/EASTL/map.h"

typedef struct TriangleVertex
{
  float vertex[3];
  TriangleVertex(float x, float y, float z)
  {
    vertex[0] = x;
    vertex[1] = y;
    vertex[2] = z;
  };
}TriangleVertex;

typedef struct TriangleIndex
{
  uint32_t index[3];
  TriangleIndex(uint32_t x, uint32_t y, uint32_t z)
  {
    index[0] = x;
    index[1] = y;
    index[2] = z;
  };
}TriangleIndex;

//using Lookup = eastl::map<eastl::pair<uint32_t, uint32_t>, uint32_t>;
using IndexedMesh = eastl::pair<eastl::vector<TriangleVertex>, eastl::vector<TriangleIndex>>;

class Icosahedron
{
public:    
    Icosahedron():radius(1.0f), subdivision(5), IndexCount(0) {}
    Icosahedron(uint32_t div) :radius(1.0f), subdivision(div), IndexCount(0) {};
   
    void GetBasicData(eastl::vector<TriangleVertex> &vertices, eastl::vector<TriangleIndex> &indicies);
    uint32_t vertex_for_edge(eastl::map< eastl::pair<uint32_t, uint32_t>, uint32_t>& lookup, eastl::vector<TriangleVertex>& vertices, uint32_t first, uint32_t second);
    eastl::vector<TriangleIndex> Subdivide(eastl::vector<TriangleVertex>& vertices, const eastl::vector<TriangleIndex>& triangles);
    void CreateIcosphere(int subdivisions, eastl::vector<float> &vertices, eastl::vector<uint32_t> &indices);

    float radius;
    uint32_t subdivision;
		uint32_t IndexCount;
};


