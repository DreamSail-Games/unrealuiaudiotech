#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#include <OpenGLES/ES1/glext.h>

@interface GLView : UIView {
	EAGLContext* m_context;
	GLuint m_framebuffer;
    GLuint m_renderbuffer;
	CADisplayLink* m_displayLink;

}

- (void)startRendering;
- (void)stopRendering;
- (void)renderFrame: (CADisplayLink*) displayLink;
@end
