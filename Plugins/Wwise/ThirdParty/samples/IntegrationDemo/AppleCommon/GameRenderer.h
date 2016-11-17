// GameRenderer.mm
// Copyright (C) 2011 Audiokinetic Inc 
/// \file 
/// Common implementation (iOS and Mac OS X) for drawing
/// Integration Demo text on screen.

#import "TextTexure2D.h"

@interface GameRenderer : NSObject<NSCacheDelegate> {
	GLuint		m_framebuffer;
    GLuint		m_renderbuffer;
	GLuint		m_viewWidth;
	GLuint		m_viewHeight;
	
	NSCache*	m_cache;	
}
-(void) drawTextOnScreenWithString:(char*) string AtPostionX:(int)in_iXPos Y:(int)in_iYPos withStyle:(DrawStyle) in_eDrawStyle;
-(void) doneDrawing;
-(void) beginDrawing;
-(void) freeTextureCache;
-(void) render;
@end
