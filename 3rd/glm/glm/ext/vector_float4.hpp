/// @ref core
/// @file glm/ext/vector_float4.hpp

#pragma once
#include "../detail/type_vec4.hpp"

namespace glm
{
	/// @addtogroup core
	/// @{

#	if(defined(GLM_PRECISION_LOWP_FLOAT))
		typedef vec<4, float, lowp>		vec4;
#	elif(defined(GLM_PRECISION_MEDIUMP_FLOAT))
		typedef vec<4, float, mediump>	vec4;
#	else //defined(GLM_PRECISION_HIGHP_FLOAT)
		/// 4 components vector of single-precision floating-point numbers.
		///
		/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.5 Vectors</a>
		typedef vec<4, float, highp>	vec4;
#	endif//GLM_PRECISION

	/// @}
}//namespace glm
