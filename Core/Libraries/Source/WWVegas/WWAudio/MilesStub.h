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
typedef void* HSAMPLE;
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
    int,
    float)
{
}

inline HSAMPLE AIL_allocate_sample_handle(HDIGDRIVER)
{
    return nullptr;
}

inline void AIL_release_sample_handle(HSAMPLE)
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

inline int AIL_stream_status(HSTREAM)
{
    return 0;
}

#endif


