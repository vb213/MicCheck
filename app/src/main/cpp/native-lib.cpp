#include <jni.h>
#include <string>
#include <android/log.h>
#include <oboe/Oboe.h>
#include <thread>
#include "OboeAudioRecorder.h"


extern "C" JNIEXPORT jboolean JNICALL
Java_com_example_miccheck_MainActivity_startRecording(
        JNIEnv* env,
        jobject MainActivity,
        jstring fullPathToFile,
        jint recordingFrequency) {

        const char *path = env->GetStringUTFChars(fullPathToFile, 0);
        const int freq = (int) recordingFrequency;

        static auto a = OboeAudioRecorder::get();
        a->StartAudioRecorder(path, freq);
        return true;
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_example_miccheck_MainActivity_stopRecording(
        JNIEnv* env,
        jobject /* this */){
    static auto a = OboeAudioRecorder::get();
    a->StopAudioRecorder();
    return true;
}
