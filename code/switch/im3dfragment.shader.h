////////////////////////////////////////////////////////////////////////////////
///
///     @file       Im3dFragment.shader.h
///     @author     
///     @date       
///
///     @brief      Immediate Mode Fragment
///
///     Copyright (c) 2020 Hello Games Ltd. All Rights Reserved.
///
////////////////////////////////////////////////////////////////////////////////

#version 440 core
#extension GL_NV_gpu_shader5 : require
#extension GL_ARB_separate_shader_objects : require

#ifndef D_FRAGMENT
#define D_FRAGMENT
#endif

#include "Common/Defines.shader.h"

struct CommonPerMeshUniforms
{
    vec4 gImmediateRenderParams;
    mat4 gWorldViewProjectionMat4;

BEGIN_SAMPLERBLOCK
	SAMPLER2D( gColourMap );
END_SAMPLERBLOCK

DECLARE_UNIFORMS
     DECLARE_PTR( CommonPerMeshUniforms, mpCommonPerMesh )       /*: PER_MESH*/
DECLARE_UNIFORMS_END

DECLARE_INPUT
    INPUT( vec2, UV             , TEXCOORD0 )
    INPUT( vec4, Color          , COLOR )
#if defined( D_USING_LOGDEPTH )
    INPUT( vec2, mDepthVal      , TEXCOORD1 )
#endif
DECLARE_INPUT_END

#if defined( D_USING_LOGDEPTH )
FRAGMENT_MAIN_COLOUR_DEPTH_SRT
#else
FRAGMENT_MAIN_COLOUR_SRT
#endif
{
    FRAGMENT_COLOUR = In.Color;
#if defined( D_USING_LOGDEPTH )
    FRAGMENT_DEPTH  = log2( In.mDepthVal.x ) * In.mDepthVal.y;
#endif
}
