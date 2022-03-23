#ifndef OPENALWITHQT_H
#define OPENALWITHQT_H

#include <QMainWindow>

// forward declaration of openAL to be able to create object
class OpenAL;

namespace Ui {
class OpenALwithQT;
}

class OpenALwithQT : public QMainWindow
{
    Q_OBJECT

public:
    explicit OpenALwithQT(QWidget *parent = 0);
    ~OpenALwithQT();

    void init();

private:
    Ui::OpenALwithQT *ui;
    OpenAL *oal;

private slots:
    void on_PlayBattleButton_clicked();
    void on_PauseBattleButton_clicked();
    void on_StopBattleButton_clicked();
    void on_PlayGunOneButton_clicked();
    void on_PauseGunOneButton_clicked();
    void on_StopGunOneButton_clicked();
    void on_PlayGunTwoButton_clicked();
    void on_PauseGunTwoButton_clicked();
    void on_StopGunTwoButton_clicked();
};

#endif // OPENALWITHQT_H
