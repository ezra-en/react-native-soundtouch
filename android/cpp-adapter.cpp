#include <jni.h>
#include "react-native-soundtouch.h"

using namespace soundtouch;

extern "C" JNIEXPORT jdouble JNICALL
Java_com_soundtouch_SoundtouchModule_nativeMultiply(JNIEnv *env, jclass type, jdouble a, jdouble b)
{
  return multiply(a, b);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_soundtouch_SoundtouchModule_nativeGetVersionString(JNIEnv *env, jclass type)
{
  // Call example SoundTouch routine
  const char *version = SoundTouch::getVersionString();

  // return version as string
  return env->NewStringUTF(version);
}

extern "C" JNIEXPORT jlong JNICALL
Java_com_soundtouch_SoundtouchModule_nativeNewInstance(JNIEnv *env, jclass type)
{
  return (jlong)(new SoundTouch());
}

extern "C" JNIEXPORT void JNICALL
Java_com_soundtouch_SoundtouchModule_nativeSetTempo(JNIEnv *env, jclass type, jlong handle, jfloat tempo)
{
  SoundTouch *ptr = (SoundTouch *)handle;
  ptr->setTempo(tempo);
}

extern "C" JNIEXPORT void JNICALL
Java_com_soundtouch_SoundtouchModule_nativeSetPitchSemiTones(JNIEnv *env, jobject thiz, jlong handle, jfloat pitch)
{
	SoundTouch *ptr = (SoundTouch*)handle;
	ptr->setPitchSemiTones(pitch);
}

extern "C" JNIEXPORT void JNICALL
Java_com_soundtouch_SoundtouchModule_nativeSetSpeed(JNIEnv *env, jobject thiz, jlong handle, jfloat speed)
{
	SoundTouch *ptr = (SoundTouch*)handle;
	ptr->setRate(speed);
}

extern "C" JNIEXPORT void JNICALL
Java_com_soundtouch_SoundtouchModule_nativeDeleteInstance(JNIEnv *env, jobject thiz, jlong handle)
{
  SoundTouch *ptr = (SoundTouch *)handle;
  delete ptr;
}