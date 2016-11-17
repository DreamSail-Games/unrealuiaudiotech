#import <UIKit/UIKit.h>
#import "GLView.h"
#import <AVFoundation/AVAudioSession.h>

@class GamePadViewController;

@interface IntegrationDemoAppDelegate : UIResponder <UIApplicationDelegate,UIAlertViewDelegate> {
    UIWindow *window;
	GLView* m_gameView; // Background view to instert into reusable view controller.
	
	bool m_bIsInit;
	
}
@property (nonatomic, strong) UIWindow *window;
@property (nonatomic, strong) GamePadViewController *viewController;
@property (readwrite, strong) AVAudioSession* session; // Use atomic since it is used by multiple threads.

@end

