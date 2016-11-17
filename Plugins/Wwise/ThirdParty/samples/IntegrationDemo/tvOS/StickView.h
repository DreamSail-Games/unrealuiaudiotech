
#import <UIKit/UIKit.h>

// Used by both IntegratoinDemo and GameSim
@interface StickView : UIView {
	BOOL m_bIsMoving;
	CGRect m_stickRect;
}
@property (readonly) CGPoint normalizedPostion;
-(void) moveStickToPosition:(CGPoint) position;
@end
