#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QTimer>
#include <QProgressBar>

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
enum GameStopType { player1Win, player2Win, manual };
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void StartGame();
    void StopGame(GameStopType);
    void WriteMainLabelText(QString text);
    void GameControlButtonPressed();
    void SwitchPlayer();
    int GetGameTime();
    void UpdateProgressBars();
    void UpdateTime();

private:
    bool player1Turn = true;
    bool gameRunning = false;

    QLabel* mainLabel;
    QDoubleSpinBox *gameTime;
    QPushButton *switchButton;
    QPushButton *gameControlButton;

    QTimer *timer;

    int player1Time;
    QProgressBar *player1Bar;
    int player2Time;
    QProgressBar *player2Bar;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
