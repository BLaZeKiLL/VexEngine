#pragma once

#include <vector>
#include "Vex/Libs.h"

namespace VEX
{
	class Mesh final
	{
	public:
		unsigned int id;
		std::vector<glm::fvec3>& vertices;
		std::vector<unsigned int>& indices;

		Mesh(std::vector<glm::fvec3>& vertices, std::vector<unsigned int>& indices);

		void Clear() const;
	};
}
