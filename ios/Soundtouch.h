#ifdef __cplusplus
#import "react-native-soundtouch.h"
#endif

#ifdef RCT_NEW_ARCH_ENABLED
#import "RNSoundtouchSpec.h"

@interface Soundtouch : NSObject <NativeSoundtouchSpec>
#else
#import <React/RCTBridgeModule.h>

@interface Soundtouch : NSObject <RCTBridgeModule>
#endif

@end
