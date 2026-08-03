#include "MilesStub.h"
#include "MilesOpenAL.h"

// ============================================================================
// Sample management
// ============================================================================

HSAMPLE AIL_allocate_sample_handle(HDIGDRIVER)
{
    return MilesOpenAL::CreateSample();
}

void AIL_release_sample_handle(HSAMPLE sample)
{
    MilesOpenAL::DestroySample(sample);
}

void AIL_init_sample(HSAMPLE)
{
}

void AIL_start_sample(HSAMPLE sample)
{
    MilesOpenAL::Play(sample);
}

void AIL_stop_sample(HSAMPLE sample)
{
    MilesOpenAL::Stop(sample);
}

void AIL_resume_sample(HSAMPLE sample)
{
    MilesOpenAL::Play(sample);
}

void AIL_end_sample(HSAMPLE sample)
{
    MilesOpenAL::Stop(sample);
}
