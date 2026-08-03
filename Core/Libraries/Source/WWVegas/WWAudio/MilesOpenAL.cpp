#include "MilesStub.h"
#include "MilesOpenAL.h"

#include <AL/al.h>
#include <AL/alc.h>

static ALCdevice* g_Device = nullptr;
static ALCcontext* g_Context = nullptr;

namespace MilesOpenAL
{

bool Initialize()
{
    g_Device = alcOpenDevice(nullptr);
    if (!g_Device)
        return false;

    g_Context = alcCreateContext(g_Device, nullptr);
    if (!g_Context)
        return false;

    alcMakeContextCurrent(g_Context);
    return true;
}

void Shutdown()
{
    if (g_Context)
    {
        alcMakeContextCurrent(nullptr);
        alcDestroyContext(g_Context);
        g_Context = nullptr;
    }

    if (g_Device)
    {
        alcCloseDevice(g_Device);
        g_Device = nullptr;
    }
}

MilesSample* CreateSample()
{
    MilesSample* s = new MilesSample();
    alGenSources(1, &s->source);
    return s;
}

void DestroySample(MilesSample* s)
{
    if (!s)
        return;

    if (s->source)
        alDeleteSources(1, &s->source);

    if (s->buffer)
        alDeleteBuffers(1, &s->buffer);

    delete s;
}

void Play(MilesSample* s)
{
    if (s)
        alSourcePlay(s->source);
}

void Stop(MilesSample* s)
{
    if (s)
        alSourceStop(s->source);
}

void Pause(MilesSample* s)
{
    if (s)
        alSourcePause(s->source);
}

void SetVolume(MilesSample* s, float volume)
{
    if (!s)
        return;

    s->volume = volume;
    alSourcef(s->source, AL_GAIN, volume);
}

void SetPan(MilesSample* s, float pan)
{
    if (!s)
        return;

    s->pan = pan;
    alSource3f(s->source, AL_POSITION, pan, 0.0f, 0.0f);
}

void SetLooping(MilesSample* s, bool loop)
{
    if (!s)
        return;

    s->looping = loop;
    alSourcei(s->source, AL_LOOPING, loop ? AL_TRUE : AL_FALSE);
}

void SetPosition(MilesSample* s, float x, float y, float z)
{
    if (s)
        alSource3f(s->source, AL_POSITION, x, y, z);
}

}
