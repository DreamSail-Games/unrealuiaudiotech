// NSGLView.h
// Copyright (C) 2011 Audiokinetic Inc.
/// \file 
/// NSView that holds the OpenGL view.

#import <Cocoa/Cocoa.h>
#import <QuartzCore/CVDisplayLink.h>

@interface NSGLView : NSOpenGLView {
	CVDisplayLinkRef	m_displayLink;
	NSDictionary*		m_keyMap;
}

@end
