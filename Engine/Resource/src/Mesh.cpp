#include "Mesh.h"

namespace VEX
{
	Mesh::Mesh(std::vector<glm::fvec3>& vertices, std::vector<unsigned>& indices) : id(0), vertices(vertices), indices(indices)
	{
	}

	void Mesh::Clear() const
	{
		vertices.clear();
		indices.clear();
	}
}
