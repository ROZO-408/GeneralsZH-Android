/*
**	Command & Conquer Generals Zero Hour(tm)
**	Copyright 2025 Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
** MilesStub.h
**
** Stub definitions for Miles Sound System types when compiling on Linux with OpenAL.
**
** TheSuperHackers @build 15/12/2024
** This header provides minimal type definitions to allow WWAudio.h and related
** files to compile without the Miles SDK headers. These are only used when
** SAGE_USE_OPENAL is defined (Linux builds).
*/

#pragma once

#if defined(SAGE_USE_OPENAL) && !defined(_MILES_STUB_H)
#define _MILES_STUB_H

// VC++ calling convention stubs
#if !defined(_WIN32)
    #define __stdcall
    #define __cdecl
    #define AILCALLBACK
    #define DP_FILTER 0
#else
    #define AILCALLBACK
#endif

// Windows type stubs
#if !defined(_WIN32)
    typedef unsigned char  U8;
    typedef signed char    S8;
    typedef unsigned short U16;
    typedef signed short   S16;
    typedef unsigned int   U32;
    typedef signed int     S32;
    typedef float          F32;
    typedef double         F64;
    typedef void* HANDLE;
#endif

// Miles Sound System type stubs (not including callback typedefs - those are defined in AudioEvents.h)
typedef void* HDIGDRIVER;
typedef void* HPROVIDER;
typedef void* HSTREAM;
struct MilesSample;
typedef MilesSample* HSAMPLE;
typedef void* H3DSAMPLE;
typedef void* H3DPOBJECT;
typedef void* HTIMER;

// Wave format stub
typedef struct {
    U16 wFormatTag;
    U16 nChannels;
    U32 nSamplesPerSec;
    U32 nAvgBytesPerSec;
    U16 nBlockAlign;
    U16 wBitsPerSample;
} WAVEFORMAT;
typedef WAVEFORMAT* LPWAVEFORMAT;

typedef struct
{
    U32 format;
    U32 data_len;
    void* data_ptr;
    U32 rate;
    U32 bits;
    U32 channels;
} AILSOUNDINFO;

// Driver info stub
struct DRIVER_INFO_STRUCT {
    char name[256];
    int capabilities;
    void* handle;
};

// No-op defines for AIL functions
inline void AIL_set_sample_processor(
    HSAMPLE,
    int,
    HPROVIDER)
{
}

inline void AIL_set_filter_sample_preference(
    HSAMPLE,
    const char*,
    float*)
{
}

inline HSAMPLE AIL_allocate_sample_handle(HDIGDRIVER)
{
    return nullptr;
}

inline void AIL_release_sample_handle(HSAMPLE)
{
}
inline void AIL_set_3D_velocity_vector(
    H3DSAMPLE,
    float,
    float,
    float)
{
}

inline void AIL_set_3D_sample_distances(
    H3DSAMPLE,
    float,
    float)
{
}

inline void AIL_set_3D_sample_effects_level(
    H3DSAMPLE,
    float)
{
}

// Missing Miles API stubs
inline void AIL_lock() {}
inline void AIL_unlock() {}

inline void AIL_set_3D_position(H3DSAMPLE, float, float, float) {}

inline void AIL_set_3D_orientation(
    H3DSAMPLE,
    float, float, float,
    float, float, float) {}
inline void AIL_enter() {}
inline void AIL_leave() {}

inline void AIL_start_stream(HSTREAM) {}
inline void AIL_pause_stream(HSTREAM, int) {}
inline void AIL_close_stream(HSTREAM) {}
inline void AIL_init_sample(HSAMPLE) {}

inline void AIL_set_named_sample_file(
    HSAMPLE,
    char*,
    void*,
    U32,
    U32)
{
}

inline void AIL_start_sample(HSAMPLE) {}

inline void AIL_stop_sample(HSAMPLE) {}

inline void AIL_resume_sample(HSAMPLE) {}

inline void AIL_end_sample(HSAMPLE) {}

inline void AIL_sample_volume_pan(
    HSAMPLE,
    float*,
    float*)
{
}
inline void AIL_set_sample_loop_count(
    HSAMPLE,
    U32)
{
}

inline U32 AIL_sample_loop_count(
    HSAMPLE)
{
    return 0;
}
inline void AIL_set_sample_ms_position(
    HSAMPLE,
    U32)
{
}

inline void AIL_sample_ms_position(
    HSAMPLE,
    S32*,
    S32*)
{
}
inline void AIL_set_sample_user_data(
    HSAMPLE,
    U32,
    void*)
{
}

inline void* AIL_sample_user_data(
    HSAMPLE,
    U32)
{
    return nullptr;
}
inline U32 AIL_sample_playback_rate(
    HSAMPLE)
{
    return 0;
}

inline void AIL_set_sample_volume_pan(
    HSAMPLE,
    float,
    float)
{
}
inline void AIL_set_sample_playback_rate(
    HSAMPLE,
    U32)
{
}
inline int AIL_stream_status(HSTREAM)
{
    return 0;
}

#ifndef WAVE_FORMAT_IMA_ADPCM
#define WAVE_FORMAT_IMA_ADPCM 0x0011
#endif

inline int AIL_WAV_info(
    void*,
    AILSOUNDINFO*)
{
    return 0;
}
inline U32 AIL_set_3D_sample_file(
    H3DSAMPLE,
    void*)
{
    return 1;
}

inline void AIL_start_3D_sample(H3DSAMPLE) {}
inline void AIL_stop_3D_sample(H3DSAMPLE) {}
inline void AIL_resume_3D_sample(H3DSAMPLE) {}
inline void AIL_end_3D_sample(H3DSAMPLE) {}

inline void AIL_set_3D_sample_volume(
    H3DSAMPLE,
    float)
{
}

inline float AIL_3D_sample_volume(
    H3DSAMPLE)
{
    return 0.0f;
}

inline void AIL_set_3D_sample_loop_count(
    H3DSAMPLE,
    U32)
{
}

inline U32 AIL_3D_sample_loop_count(
    H3DSAMPLE)
{
    return 0;
}

inline void AIL_set_3D_sample_offset(
    H3DSAMPLE,
    U32)
{
}

inline U32 AIL_3D_sample_offset(
    H3DSAMPLE)
{
    return 0;
}

inline U32 AIL_3D_sample_length(
    H3DSAMPLE)
{
    return 0;
}

inline void AIL_set_3D_object_user_data(
    H3DSAMPLE,
    U32,
    void*)
{
}

inline void* AIL_3D_object_user_data(
    H3DSAMPLE,
    U32)
{
    return nullptr;
}

inline U32 AIL_3D_sample_playback_rate(
    H3DSAMPLE)
{
    return 0;
}

inline void AIL_set_3D_sample_playback_rate(
    H3DSAMPLE,
    U32)
{
}
inline HSTREAM AIL_open_stream(
    HDIGDRIVER,
    const char*,
    U32)
{
    return nullptr;
}

inline void AIL_stream_volume_pan(
    HSTREAM,
    float*,
    float*)
{
}

inline void AIL_set_stream_volume_pan(
    HSTREAM,
    float,
    float)
{
}

inline void AIL_set_stream_loop_block(
    HSTREAM,
    S32,
    S32)
{
}

inline void AIL_set_stream_loop_count(
    HSTREAM,
    U32)
{
}

inline U32 AIL_stream_loop_count(
    HSTREAM)
{
    return 0;
}

inline void AIL_set_stream_ms_position(
    HSTREAM,
    U32)
{
}

inline void AIL_stream_ms_position(
    HSTREAM,
    S32*,
    S32*)
{
}

inline U32 AIL_stream_playback_rate(
    HSTREAM)
{
    return 0;
}

inline void AIL_set_stream_playback_rate(
    HSTREAM,
    U32)
{
}
#endif


