
#ifndef D_FRAGMENT
#define D_FRAGMENT
#endif

#include "Common/Defines.shader.h"
#include "Common/CommonUniforms.shader.h"
#include "Common/CommonFragment.shader.h"

#include "Fullscreen/PostCommon.h"

DECLARE_INPUT
    INPUT_SCREEN_POSITION
    INPUT( vec2, mTexCoordsVec2,     TEXCOORD0 )
DECLARE_INPUT_END

FRAGMENT_MAIN_COLOUR_SRT
{
	vec2 lOffsetVec2 = vec2( 0.5, 0.5 ) / lUniforms.mpCustomPerMesh.gTextureSizeMipLevelVec4.xy; 
	
	vec2 lTexCoordVec2 = IN( mTexCoordsVec2 );

	float lfMipLevel = lUniforms.mpCustomPerMesh.gTextureSizeMipLevelVec4.z;
    vec4 lColor00Vec4 = texture2DLod( SAMPLER_GETMAP( lUniforms.mpCustomPerMesh,gBufferMap ), lTexCoordVec2 + vec2( -1.0, -1.0 ) * lOffsetVec2, lfMipLevel );
    vec4 lColor01Vec4 = texture2DLod( SAMPLER_GETMAP( lUniforms.mpCustomPerMesh,gBufferMap ), lTexCoordVec2 + vec2( -1.0, +1.0 ) * lOffsetVec2, lfMipLevel );
    vec4 lColor10Vec4 = texture2DLod( SAMPLER_GETMAP( lUniforms.mpCustomPerMesh,gBufferMap ), lTexCoordVec2 + vec2( +1.0, -1.0 ) * lOffsetVec2, lfMipLevel );
    vec4 lColor11Vec4 = texture2DLod( SAMPLER_GETMAP( lUniforms.mpCustomPerMesh,gBufferMap ), lTexCoordVec2 + vec2( +1.0, +1.0 ) * lOffsetVec2, lfMipLevel );

	FRAGMENT_COLOUR = 0.25 * ( lColor00Vec4 + lColor01Vec4 + lColor10Vec4 + lColor11Vec4 );
}
