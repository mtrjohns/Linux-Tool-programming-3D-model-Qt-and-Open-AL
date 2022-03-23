#ifndef OPENAL_H
#define OPENAL_H

#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alut.h>

class OpenAL
{
private:
    int NUMBER_OF_BUFFERS;		//Holds number of sources
    int NUMBER_OF_SOURCES;		//Holds number of buffers



    ALuint *buffers;			// Buffers hold sound data.
    ALuint *sources;			// Sources are points of emitting sound.

    int countBuffers;
    int countSources;


    ALfloat listenerPos[3]; // Position of the listener.
    ALfloat listenerVel[3];// Velocity of the listener.


    ALfloat listenerOri[6]; // Orientation of the listener (and up vector)

    ALboolean contextInit();

public:
    OpenAL(void);

    OpenAL(int, int);

    ALboolean init();

    //mutator methods
    void setListenerPos(float, float, float);
    float* getListenerPos();

    void setListenerVel(float, float, float);
    float* getListenerVel();

    void setListenerOri(float, float, float,float, float, float);
    float* getListenerOri();

    void setListenerUp(float, float, float);
    float* getListenerUp();



    int addBuffer(char*);

    ALuint getSource();


    void playSource(int buffer);

    // used to stop playing source
    void stopSource(int buffer);
    void pauseSource(int buffer);
    void rewindSource(int buffer);

    bool isPlaying(int buffer);
    bool isStopped(int buffer);
    bool isRewinded(int buffer);
    bool isPaused(int buffer);


    int addSources(int buffer, float* SourcePos, float* SourceVel, bool loop);

    static void printALError(ALenum err);


    ~OpenAL(void);
};

#endif // OPENAL_H
