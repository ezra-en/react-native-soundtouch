#include <jni.h>
#include "react-native-soundtouch.h"

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_soundtouch_SoundtouchModule_nativeMultiply(JNIEnv *env, jclass type, jdouble a, jdouble b) {
    return soundtouch::multiply(a, b);
}
