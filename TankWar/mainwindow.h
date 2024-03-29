#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "main.h"
#include "map.h"
#include "boss.h"
#include "tank.h"


#include <QMainWindow>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include <QMessageBox>
#include <QCloseEvent>
#include <QLabel>


#define TIME_INTERVAL 25


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    enum GameStatus{gaming,pause,over};

    void initGame();

    void loadCell();

    bool isEnemyAllDisappeared() const;

    void missileMeet();

    void isOver();

    GameStatus getGameStatus() const;

    void showPlayerInfo();

private slots:
  void timeFun();

  void paintEvent(QPaintEvent* event);

  void keyPressEvent(QKeyEvent* event);

  void keyReleaseEvent(QKeyEvent* event);

  void showLunchInfo();

  void showTips();

  void showPauseInfo();

  void showLoss();

  void showEnd();

  void showResume();

private:

    void setGameStatus(GameStatus status);
    GameStatus status;
    Map map;

    QTimer* timer;

    QPainter paint;

    QLabel *score1, *score2;
    QLabel *tankLife1,*tankLife2;
    QLabel *gamepause;

    int playerTanksNumTmp;

};

#endif // MAINWINDOW_H
