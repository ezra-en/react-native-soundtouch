package com.soundtouch;

import androidx.annotation.NonNull;

import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.module.annotations.ReactModule;

@ReactModule(name = SoundtouchModule.NAME)
public class SoundtouchModule extends ReactContextBaseJavaModule {
  public static final String NAME = "Soundtouch";
  
  
  public SoundtouchModule(ReactApplicationContext reactContext) {
    super(reactContext);
  }
  
  @Override
  @NonNull
  public String getName() {
    return NAME;
  }
  
  private long handle = 0;
  
  private native long nativeNewInstance();
  
  public void createSoundTouch() {
    handle = nativeNewInstance();
  }

  static {
    System.loadLibrary("cpp");
  }


  private static native double nativeMultiply(double a, double b);

  // Example method
  // See https://reactnative.dev/docs/native-modules-android
  @ReactMethod
  public void multiply(double a, double b, Promise promise) {
    promise.resolve(nativeMultiply(a, b));
  }

  private native String nativeGetVersionString();

 @ReactMethod
  public void getVersionString(Promise promise) {
    promise.resolve(nativeGetVersionString());
  }

  private native void nativeSetTempo(long handle, float tempo);

  @ReactMethod
  public void setTempo(float tempo) {
    nativeSetTempo(handle, tempo);
  }

  private native void nativeSetPitchSemiTones(long handle, float pitch);
  
  @ReactMethod
  public void setPitchSemiTones(float pitch) {
    nativeSetPitchSemiTones(handle, pitch);
  }

  private native void nativeSetSpeed(long handle, float speed);
  
  @ReactMethod
  public void setSpeed(float speed) {
    nativeSetSpeed(handle, speed);
  }
  
  private native void nativeDeleteInstance(long handle);

  @ReactMethod
  public void close() {
    nativeDeleteInstance(handle);
    handle = 0;
  }

}