#include "OpenAL.h"

#include <ctime>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <cstring>

OpenAL::OpenAL(void)
{

}

OpenAL::OpenAL(int buffs, int sour)
{
    NUMBER_OF_BUFFERS = buffs;
    NUMBER_OF_SOURCES = sour;

    countSources = 0;
    countBuffers = 0;
}

OpenAL::~OpenAL(void)
{
    alDeleteBuffers(NUMBER_OF_BUFFERS, buffers);
    alDeleteSources(NUMBER_OF_SOURCES, sources);

    free(buffers);
    free(sources);

    ALCcontext* pCurContext;
    ALCdevice* pCurDevice;

    // Get the current context.
    pCurContext = alcGetCurrentContext();

    // Get the device used by that context.
    pCurDevice = alcGetContextsDevice(pCurContext);

    // Reset the current context to NULL.
    alcMakeContextCurrent(NULL);

    // Release the context and the device.
    alcDestroyContext(pCurContext);
    alcCloseDevice(pCurDevice);
}

void OpenAL::setListenerPos(float x, float y, float z)
{
    listenerPos[0] = x;
    listenerPos[1] = y;
    listenerPos[2] = z;
    alListenerfv(AL_POSITION,    listenerPos);
}

float* OpenAL::getListenerPos()
{
    return listenerPos;
}

void OpenAL::setListenerVel(float x, float y, float z)
{
    listenerVel[0] = x;
    listenerVel[1] = y;
    listenerVel[2] = z;
    alListenerfv(AL_VELOCITY,    listenerVel);
}

float* OpenAL::getListenerVel()
{
    return listenerVel;
}

void OpenAL::setListenerOri(float x, float y, float z, float ux, float uy, float uz)
{
    listenerOri[0] = x;
    listenerOri[1] = y;
    listenerOri[2] = z;
    listenerOri[3] = ux;
    listenerOri[4] = uy;
    listenerOri[5] = uz;
    alListenerfv(AL_ORIENTATION, listenerOri);
}

float* OpenAL::getListenerOri()
{
    return listenerOri;
}

ALboolean OpenAL::contextInit()
{
    ALCdevice* pDevice;
    ALCcontext* pContext;
    const int STRING_MAX = 64;
    ALCchar deviceSpecifier[STRING_MAX];
    ALCchar deviceName[STRING_MAX];

    //ALCchar deviceName[] = "DirectSound3D"; //assumes windows

    strcpy(deviceName,alcGetString(NULL, ALC_DEFAULT_DEVICE_SPECIFIER));

    // Get handle to device.
    pDevice=alcOpenDevice(deviceName);

    // Get the device specifier.
    strcpy(deviceSpecifier,alcGetString(pDevice, ALC_DEVICE_SPECIFIER));

    printf("Using device '%s'.\n", deviceSpecifier);

    // Create audio context.
    pContext = alcCreateContext(pDevice, NULL);

    // Set active context.
    alcMakeContextCurrent(pContext);

    // Check for an error.
    if (alcGetError(pDevice) != ALC_NO_ERROR)
    {
        printf("error setting up device\n");
        return AL_FALSE;
    }

    return AL_TRUE;
}

ALboolean OpenAL::init()
{
    alutInitWithoutContext(NULL,0);

    //Setup the Context
    if(contextInit() == AL_TRUE)
        printf("Buffers Created\n");
    else
    {
        printf("Buffer creation not successful \n");
        return AL_FALSE;
    }

    buffers = (ALuint*)malloc(NUMBER_OF_BUFFERS*sizeof(ALuint));
    sources = (ALuint*)malloc(NUMBER_OF_SOURCES*sizeof(ALuint));

    alGenBuffers(NUMBER_OF_BUFFERS, buffers);

    if (alGetError() != AL_NO_ERROR)
    {
        printf("failed to generate buffers!");
        return AL_FALSE;
    }

    alGenSources(NUMBER_OF_SOURCES, sources);

    if (alGetError() != AL_NO_ERROR)
    {
        printf("failed to generate sources!");
        return AL_FALSE;
    }

    return AL_TRUE;
}

/*Updated to make use of the new wav loading stuff in freealut */
int OpenAL::addBuffer(char* filename)
{
    int bufferAssignment = countBuffers;
    if(countBuffers < NUMBER_OF_BUFFERS)
    {
        buffers[bufferAssignment] = alutCreateBufferFromFile(filename);
        countBuffers++;
    }

    if (alGetError() != AL_NO_ERROR)
    {
        printf("Error: addBuffer(..)\n");
        printf("Error number: %d\n",alGetError());
        printALError(alGetError());
    }

    return bufferAssignment;
}

int OpenAL::addSources(int bufferIndex, float* SourcePos, float* SourceVel, bool loop)
{
    int sourceIndex = countSources; // set the next available index.
    if(countSources < NUMBER_OF_SOURCES)
    {
        alSourcei (sources[sourceIndex], AL_BUFFER,   buffers[bufferIndex]  );
        alSourcef (sources[sourceIndex], AL_PITCH,    1.0f              );
        alSourcef (sources[sourceIndex], AL_GAIN,     1.0f              );
        alSourcefv(sources[sourceIndex], AL_POSITION, SourcePos);
        alSourcefv(sources[sourceIndex], AL_VELOCITY, SourceVel);
        alSourcei (sources[sourceIndex], AL_LOOPING,  loop          );
        countSources++;
    }

    ALenum e = alGetError();

    if (e != AL_NO_ERROR)
    {
        printf("Error: addSource(..)\n");
        printALError(e);
    }

    return sourceIndex;
}

ALuint OpenAL::getSource()
{
    return *sources;
}

void OpenAL::playSource(int buffer)
{
    alSourcePlay(sources[buffer]);

    // check if buffer source is playing
    if (isPlaying(buffer) != true)
    {
        printf("Error: unable to play source(..)\n");
    }
}

// stops and rewinds source
void OpenAL::stopSource(int buffer)
{




    // check if buffer source has stopped
    if (isPlaying(buffer) != true)
    {
            printf("Error: unable to stop source, source was not playing(..)\n");
    }
    else
    {
        alSourceStop(sources[buffer]);

        // rewind source to allow error checking on source to stop
        // tip: use pauseSource() if rewind is not required
        alSourceRewind(sources[buffer]);
        if (isRewinded(buffer) != true)
        {
            printf("Error: unable to stop and rewind source(..)\n");
        }
    }
}

void OpenAL::pauseSource(int buffer)
{
    alSourcePause(sources[buffer]);

    // check if buffer source has stopped
    if (isPaused(buffer) != true)
    {
        // check if source was playing
        if (isPlaying(buffer) != true)
        {
            printf("Error: unable to pause source, source was not playing(..)\n");
        }
        else
        {
            printf("Error: unable to pause source playing(..)\n");
        }
    }
}

void OpenAL::rewindSource(int buffer)
{
    alSourceRewind(sources[buffer]);
}

bool OpenAL::isPlaying(int buffer)
{
    ALint play;
    alGetSourcei(sources[buffer], AL_SOURCE_STATE, &play);

    if (play == AL_PLAYING)
        return true;
    else
        return false;
}

bool OpenAL::isStopped(int buffer)
{
    ALint stop;
    alGetSourcei(sources[buffer], AL_SOURCE_STATE, &stop);

    if (stop == AL_STOPPED)
        return true;
    else
        return false;
}

bool OpenAL::isRewinded(int buffer)
{
    ALint rewind;
    alGetSourcei(sources[buffer], AL_SOURCE_STATE, &rewind);

    if (rewind == AL_INITIAL)
    {
        return true;
    }
    else
        return false;
}

bool OpenAL::isPaused(int buffer)
{
    ALint paused;
    alGetSourcei(sources[buffer], AL_SOURCE_STATE, &paused);

    if (paused == AL_PAUSED)
        return true;
    else
        return false;
}

void OpenAL::printALError(ALenum err)
{
    switch(err)
    {
        case AL_NO_ERROR:
            printf("AL_NO_ERROR\n");
        break;

        case AL_INVALID_NAME:
            printf("AL_INVALID_NAME\n");
        break;

        case AL_INVALID_ENUM:
            printf("AL_INVALID_ENUM\n");
        break;

        case AL_INVALID_VALUE:
            printf("AL_INVALID_VALUE\n");
        break;

        case AL_INVALID_OPERATION:
            printf("AL_INVALID_OPERATION\n");
        break;

        case AL_OUT_OF_MEMORY:
            printf("AL_OUT_OF_MEMORY\n");
        break;
    };
}
