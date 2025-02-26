#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mainLabel = ui->label_MainText;
    gameControlButton = ui->button_startGame;
    switchButton = ui->button_switchPlayer;
    gameTime = ui->dSpinBox_gameTime;
    player1Bar = ui->bar_player1;
    player2Bar = ui->bar_player2;

    WriteMainLabelText("Tseting");
    switchButton->setVisible(false);
    timer = new QTimer();

    connect(gameControlButton, &QPushButton::clicked, this, &MainWindow::GameControlButtonPressed);
    connect(switchButton, &QPushButton::clicked, this, &MainWindow::SwitchPlayer);
    connect(timer, &QTimer::timeout, this, &MainWindow::UpdateTime);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::StartGame()
{
    gameRunning = true;
    player1Turn = true;
    gameControlButton->setText("Stop Game");
    WriteMainLabelText("Player 1 Turn");
    switchButton->setVisible(true);
    gameTime->setVisible(false);

    player1Time = GetGameTime();
    player2Time = GetGameTime();
    player1Bar->setMaximum(GetGameTime());
    player2Bar->setMaximum(GetGameTime());
    player1Bar->setValue(player1Bar->maximum());
    player2Bar->setValue(player2Bar->maximum());

    timer->start(100);
}

void MainWindow::StopGame(GameStopType type)
{
    gameRunning = false;
    timer->stop();
    gameControlButton->setText("Start Game");
    switchButton->setVisible(false);
    gameTime->setVisible(true);

    switch (type){
    case manual:
        WriteMainLabelText("Manual Restart!");
        break;
    case player1Win:
        WriteMainLabelText("Player 1 Wins!");
        break;
    case player2Win:
        WriteMainLabelText("Player 2 Wins!");
        break;
    }

    player1Bar->setValue(player1Bar->maximum());
    player2Bar->setValue(player2Bar->maximum());
}

void MainWindow::SwitchPlayer()
{
    timer->stop();
    player1Turn = !player1Turn;
    timer->start(100);
}

int MainWindow::GetGameTime()
{
    int seconds = 0;
    double time = gameTime->value();

    while (time >= 1){
        time--;
        seconds += 60;
    }

    if (time < 1)
        seconds += time * 60;

    return seconds*10;
}

void MainWindow::UpdateProgressBars()
{
    player1Bar->setValue(player1Time);
    player2Bar->setValue(player2Time);
}

void MainWindow::UpdateTime()
{
    if(player1Turn)
        player1Time--;
    else
        player2Time--;

    UpdateProgressBars();
    WriteMainLabelText(player1Turn ? "Player 1 Turn!" : "Player 2 Turn!");
    if(player1Time <= 0 || player2Time <= 0)
        StopGame(player1Time <= 0 ? player2Win : player1Win);
}
void MainWindow::WriteMainLabelText(QString text)
{
    mainLabel->setText("<html><head/><body><p><span style=font-weight:700;>" + text + "</span></p></body></html>");
}

void MainWindow::GameControlButtonPressed()
{
    if (gameRunning)
        StopGame(manual);
    else
        StartGame();
}

