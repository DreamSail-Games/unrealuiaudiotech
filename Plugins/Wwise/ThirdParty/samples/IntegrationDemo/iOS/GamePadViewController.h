#import <UIKit/UIKit.h>
#import "StickView.h"
#import "InputMgr.h"
#import "GLView.h"

// Used by both IntegratoinDemo and GameSim
@interface GamePadViewController : UIViewController {
	NSDictionary *m_buttons;
	StickView* m_leftStick;
	StickView* m_rightStick;
	UIView* backgroundView; // Inserted view from caller, can be IntegrationDemo or GameSim main view.
	CGFloat m_buttonSize;
	CGFloat m_marginSize;
}

@property (nonatomic, strong) UIView *backgroundView;

- (id)initWithButtonSize:(CGFloat) buttonSize marginSize:(CGFloat) marginSize;
- (void) rotateToOrientation:(UIInterfaceOrientation) orientation;
@end

