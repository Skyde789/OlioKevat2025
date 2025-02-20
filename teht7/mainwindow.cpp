#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    result = ui->result;
    param1 = ui->param1;
    param2 = ui->param2;

    QList<QPushButton*> buttons = findChildren<QPushButton*>();

    for (QPushButton *button : buttons) {
        if (button->objectName().contains("num"))
            connect(button, &QPushButton::clicked, this, &MainWindow::NumberPressed);
        else if (button->objectName().contains("op"))
             connect(button, &QPushButton::clicked, this, &MainWindow::OperationPressed);
        else if (button->objectName().contains("action"))
             connect(button, &QPushButton::clicked, this, &MainWindow::ActionPressed);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Clear()
{
    currentParam = 1;

    param1->setText("");
    param2->setText("");
    result->setText("");

}

void MainWindow::Enter()
{
    float x = param1->text().toInt();
    float y = param2->text().toInt();

    switch (savedOperation) {
    case Add:
        result->setText(QString::number(x+y));
        break;
    case Subs:
        result->setText(QString::number(x-y));
        break;
    case Mult:
        result->setText(QString::number(x*y));
        break;
    case Div:
        result->setText(QString::number(x/y));
        break;
    default:
        break;
    }

}

void MainWindow::Operation(enum Operation x)
{
    if (currentParam != 1)
        return;

    currentParam = 2;
    savedOperation = x;
}

void MainWindow::AddNum(QString x)
{
    switch (currentParam)
    {
        case 1:
            param1->setText(param1->text() + x);
            break;
        case 2:
            param2->setText(param2->text() + x);
            break;
    }
}

void MainWindow::NumberPressed()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QString buttonID = button->objectName().right(1);
        //QMessageBox::information(this, "Number Button Clicked", "Button " + buttonID + " was clicked!");
        AddNum(buttonID);
    }
}

void MainWindow::OperationPressed()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QString buttonID = button->objectName();

        if (buttonID.contains("add"))
            Operation(Add);
        else if (buttonID.contains("sub"))
            Operation(Subs);
        else if (buttonID.contains("mult"))
            Operation(Mult);
        else if (buttonID.contains("div"))
            Operation(Div);
        //QMessageBox::information(this, "Operation Button Clicked", "Button " + buttonID + " was clicked!");
    }
}

void MainWindow::ActionPressed()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QString buttonID = button->objectName();

        if  (buttonID.contains("enter"))
            Enter();
        else if (buttonID.contains("clear"))
            Clear();
        //QMessageBox::information(this, "Action Button Clicked", "Button " + buttonID + " was clicked!");
    }
}

