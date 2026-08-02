#pragma once

#if defined(SAGE_USE_OPENAL)

#include <cstdint>

#ifdef __ANDROID__
#include <AL/al.h>
#include <AL/alc.h>
#else
#include <AL/al.h>
#include <AL/alc.h>
#endif

struct MilesSample
{
    ALuint source = 0;
    ALuint buffer = 0;

    float volume = 1.0f;
    float pan = 0.0f;

    bool looping = false;

    uint32_t playbackRate = 22050;

    void* userData[8] = {};
};

namespace MilesOpenAL
{
    bool Initialize();
    void Shutdown();

    MilesSample* CreateSample();
    void DestroySample(MilesSample* sample);

    void Play(MilesSample* sample);
    void Stop(MilesSample* sample);
    void Pause(MilesSample* sample);

    void SetVolume(MilesSample* sample, float volume);
    void SetPan(MilesSample* sample, float pan);
    void SetLooping(MilesSample* sample, bool loop);

    void SetPosition(MilesSample* sample, float x, float y, float z);
}

#endif
