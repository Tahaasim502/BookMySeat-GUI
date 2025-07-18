#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QBoxLayout>

class MainWindow : public QWidget
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
    private slots:
        void openBookingWindow();
    private:
        QLabel *title;
};
#endif // MAINWINDOW_H
