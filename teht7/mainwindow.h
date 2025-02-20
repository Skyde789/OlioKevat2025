#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qlineedit.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

enum Operation { Add, Subs, Mult, Div };
class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private:
        QString currentNums = "";

        int currentParam = 1;

        QLineEdit *param1;
        QLineEdit *param2;
        QLineEdit *result;
        Ui::MainWindow *ui;
        Operation savedOperation;
        void Clear();
        void Enter();
        void Operation(Operation x);
        void AddNum(QString x);

    private slots:
        void NumberPressed();
        void OperationPressed();
        void ActionPressed();
};
#endif // MAINWINDOW_H
