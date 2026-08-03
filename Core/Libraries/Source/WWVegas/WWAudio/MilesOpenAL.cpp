#include "MilesOpenAL.h"

namespace MilesOpenAL
{

bool Initialize()
{
    return true;
}

void Shutdown()
{
}

MilesSample* CreateSample()
{
    auto* sample = new MilesSample;

    alGenSources(1, &sample->source);

    return sample;
}

void DestroySample(MilesSample* sample)
{
    if (!sample)
        return;

    if (sample->source)
        alDeleteSources(1, &sample->source);

    if (sample->buffer)
        alDeleteBuffers(1, &sample->buffer);

    delete sample;
}

void Play(MilesSample* sample)
{
    if (!sample)
        return;

    alSourcePlay(sample->source);
}

void Stop(MilesSample* sample)
{
    if (!sample)
        return;

    alSourceStop(sample->source);
}

void Pause(MilesSample* sample)
{
    if (!sample)
        return;

    alSourcePause(sample->source);
}

void SetVolume(MilesSample* sample, float volume)
{
    if (!sample)
        return;

    sample->volume = volume;

    alSourcef(sample->source, AL_GAIN, volume);
}

void SetPan(MilesSample* sample, float pan)
{
    if (!sample)
        return;

    sample->pan = pan;

    alSource3f(sample->source, AL_POSITION, pan, 0.0f, 0.0f);
}

void SetLooping(MilesSample* sample, bool loop)
{
    if (!sample)
        return;

    sample->looping = loop;

    alSourcei(sample->source, AL_LOOPING, loop ? AL_TRUE : AL_FALSE);
}

void SetPosition(MilesSample* sample, float x, float y, float z)
{
    if (!sample)
        return;

    alSource3f(sample->source, AL_POSITION, x, y, z);
}

}
