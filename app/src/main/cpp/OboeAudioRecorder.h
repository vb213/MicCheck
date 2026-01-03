
#ifndef OBOEAUDIORECORDER_OBOEAUDIORECORDER_H
#define OBOEAUDIORECORDER_OBOEAUDIORECORDER_H


#endif //OBOEAUDIORECORDER_OBOEAUDIORECORDER_H

class OboeAudioRecorder: public oboe::AudioStreamCallback {
public:
    static OboeAudioRecorder *get();
    bool isRecording = true;
    void StopAudioRecorder();
    void StartAudioRecorder(const char *fullPathToFile, int recordingFreq);
private:
    oboe::ManagedStream outStream;
    oboe::AudioStream *stream{};

    oboe::DataCallbackResult onAudioReady(oboe::AudioStream *oboeStream, void *audioData, int32_t numFrames) override;
    static OboeAudioRecorder *singleton;
    explicit OboeAudioRecorder() = default;
};