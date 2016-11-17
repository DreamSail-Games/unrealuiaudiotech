// InputMgr.h
// Copyright (C) 2011 Audiokinetic Inc 
/// \file 
/// This class prints coregraphics text to an OpenGL texture
/// This is highly suboptimal so don't use it as is to 
/// display text in your OpenGL game.

#include <TargetConditionals.h>
#import <Foundation/Foundation.h>
#include <CoreGraphics/CoreGraphics.h>

#if TARGET_OS_IPHONE 
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>
#else
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#endif

#include "Platform.h"
#include "Drawing.h"

#define CHECK_GL_ERROR() ({ GLenum __error = glGetError(); if(__error) printf("OpenGL error 0x%04X in %s\n", __error, __FUNCTION__); (__error ? NO : YES); })

@interface TextTexure2D : NSObject 
{
@private
	GLuint						m_name;
	NSUInteger					m_contentWidth;
	NSUInteger					m_contentHeight;
	
	NSUInteger					m_textureWidth;
	NSUInteger					m_textureHeight;

	GLfloat						m_maxS;
	GLfloat						m_maxT;
	
}
- (id) initWithString:(char*)string withStyle:(DrawStyle) in_eDrawStyle;
- (void) drawAtPoint:(CGPoint)point;
@end


