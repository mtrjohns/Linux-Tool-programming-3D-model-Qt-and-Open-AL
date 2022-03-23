#include "OpenALWithQT.h"
#include "ui_OpenALWithQT.h"
#include "OpenAL.h"

#include <ctime>
#include <iostream>

OpenALwithQT::OpenALwithQT(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OpenALwithQT)
{
    ui->setupUi(this);

    // set OpenAL Object to null
    oal = NULL;
    init();
}

// initialiser (used to create objects that could fail in constructor)
void OpenALwithQT::init()
{
    // number of (buffers, sources)
        oal = new OpenAL(3,3);
        oal->init();
        oal->setListenerPos(0.0f,0.0f,0.0f);
        oal->setListenerOri(0.0f,0.0f,-1.0f,0.0f,0.0f,1.0f);

        int battleBuffer = oal->addBuffer("wavData/Battle.wav");

        float pos[] = {1.0f,0.0f,0.0f};
        float vel[] = {0.0f,1.0f,0.0f};

        int battleSource = oal->addSources(battleBuffer,pos,vel,true);

        int gunOneBuffer = oal->addBuffer("wavData/Gun1.wav");
        float pos1[] = {1.0f,1.0f,1.0f};
        float vel1[] = {0.0f,1.0f,0.0f};
        int gunOneSource = oal->addSources(gunOneBuffer,pos1,vel1,false);

        int gunTwoBuffer = oal->addBuffer("wavData/Gun2.wav");
        float pos2[] = {1.0f,1.0f,1.0f};
        float vel2[] = {2.0f,2.0f,0.0f};
        int gunTwoSource = oal->addSources(gunTwoBuffer,pos2,vel2,false);

        // Do the looping and fade away stuff
        oal->getListenerPos();
}

void OpenALwithQT::on_PlayBattleButton_clicked()
{
    // check to ensure oal has been created
    if(oal != NULL)
    {
      //printf("In Play Button Clicked");
      oal->playSource(0);
    }
}

void OpenALwithQT::on_PauseBattleButton_clicked()
{
    // check to ensure oal has been created
    if(oal != NULL)
    {
      oal->pauseSource(0);
    }
}

void OpenALwithQT::on_StopBattleButton_clicked()
{
    // check to ensure oal has been created
    if(oal != NULL)
    {
      oal->stopSource(0);
    }
}

void OpenALwithQT::on_PlayGunOneButton_clicked()
{
    // check to ensure oal has been created
    if(oal != NULL)
    {
      oal->playSource(1);
    }
}

void OpenALwithQT::on_PauseGunOneButton_clicked()
{
    // check to ensure oal has been created
    if(oal != NULL)
    {
      oal->pauseSource(1);
    }
}

void OpenALwithQT::on_StopGunOneButton_clicked()
{
    // check to ensure oal has been created
    if(oal != NULL)
    {
      oal->stopSource(1);
    }
}

void OpenALwithQT::on_PlayGunTwoButton_clicked()
{
    // check to ensure oal has been created
    if(oal != NULL)
    {
      oal->playSource(2);

      ALint time = clock();
      ALint elapse = 0;
      std::cout << "NOT in while loop" << std::endl;

      //while(!oal->isStopped(2))
      for(int i = 0; i < 150; i++)
          {
           std::cout << "in while loop" << std::endl;
              elapse += clock() - time;
              time += elapse;

              if(elapse > 50)
              {
                  std::cout << "Elapsed time: " << elapse << std::endl;
                  elapse = 0;

                  oal->setListenerPos(oal->getListenerPos()[0] + oal->getListenerVel()[0],
                                      oal->getListenerPos()[1] + oal->getListenerVel()[1],
                                      oal->getListenerPos()[2] + oal->getListenerVel()[2]);

                 alSourcefv(oal->getSource(), AL_POSITION, oal->getListenerPos());
              }
          }
      }
}

void OpenALwithQT::on_PauseGunTwoButton_clicked()
{
    // check to ensure oal has been created
    if(oal != NULL)
    {
      oal->pauseSource(2);
    }
}

void OpenALwithQT::on_StopGunTwoButton_clicked()
{
    // check to ensure oal has been created
    if(oal != NULL)
    {
      oal->stopSource(2);

    }
}



OpenALwithQT::~OpenALwithQT()
{
    delete ui;
    delete oal;
}
