// IntegrationDemoAppDelegate.h
// Copyright (C) 2011 Audiokinetic Inc.
/// \file 
/// Application delegate for the demo.

#import <Cocoa/Cocoa.h>
#import "NSGLView.h"

@interface IntegrationDemoAppDelegate : NSObject <NSApplicationDelegate, NSWindowDelegate> 
{
    NSWindow *m_window;
	NSGLView *m_gameView;
}
@end
