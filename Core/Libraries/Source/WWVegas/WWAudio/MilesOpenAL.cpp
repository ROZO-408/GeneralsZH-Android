#include "MilesOpenAL.h"

#if defined(SAGE_USE_OPENAL)

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
    return new MilesSample();
}

void DestroySample(MilesSample* sample)
{
    delete sample;
}

void Play(MilesSample*)
{
}

void Stop(MilesSample*)
{
}

void Pause(MilesSample*)
{
}

void SetVolume(MilesSample*, float)
{
}

void SetPan(MilesSample*, float)
{
}

void SetLooping(MilesSample*, bool)
{
}

void SetPosition(MilesSample*, float, float, float)
{
}

}

#endif
