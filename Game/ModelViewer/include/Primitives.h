#pragma once

#include "Vex/OpenGL.h"
#include "Vertex.h"

class MeshData final
{
public:
    VEX::VertexBufferLayout layout;

    unsigned int vertex_count;
    unsigned int index_count;

    const Vertex* vertices;
    const unsigned int* indices;

    MeshData(const VEX::VertexBufferLayout &layout,
             unsigned int vertexCount, unsigned int indexCount,
             const Vertex* vertices, const unsigned int* indices);

    virtual ~MeshData();
};

class Primitives final
{
public:
    static MeshData* Cube();
};
