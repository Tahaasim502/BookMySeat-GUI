#include "mainwindow.h"
#include "bookingwindow.h"
#include <QColorDialog>
#include <QPushButton>
#include <QLinearGradient>
#include <QColor>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent): QWidget(parent) //constructor
{
    //Setting the Gradient:
    QPalette backgroundpalete = this->palette();
    backgroundpalete.setColor(QPalette :: Window, QColor(20, 129, 132));
    setAutoFillBackground(true);
    setPalette(backgroundpalete);

    //Setting the title:
    title = new QLabel("Theatre Booking System", this); //this is a pointer for the main window

    //font:
    QFont font("Montserrat SemiBold", 18, QFont ::Bold );
    font.setLetterSpacing(QFont :: PercentageSpacing, 110);
    title -> setFont(font);
    title ->setAlignment(Qt :: AlignCenter); //this is used for setting the text to center

    QPalette titlePalette;
    titlePalette.setColor(QPalette :: WindowText, QColor(245, 245, 245));
    title -> setPalette(titlePalette);


    //Setting the buttons:
    QPushButton *startButton = new QPushButton("Start Booking", this);
    QPushButton *exitButton = new QPushButton("Exit", this);
    startButton ->setFixedSize(180, 50);
    exitButton -> setFixedSize(180, 50);
    connect(exitButton, &QPushButton :: clicked, this, &QWidget :: close);
    connect(startButton, &QPushButton :: clicked, this, &MainWindow :: openBookingWindow);
    //Setting Buttons Color:
    startButton->setStyleSheet(
            "QPushButton {"
            "background-color: rgb(255, 193, 7);"
            "color: black;"
            "border-radius: 5px;"
            "padding: 10px;"
            "}"
            "QPushButton:hover {"
            "background-color: rgb(225, 213, 50);"
            "}"
            );
    exitButton -> setStyleSheet(
        "QPushButton {"
        "background-color: rgb(130, 20, 20);"
        "color: white;"
        "border-radius: 5px;"
        "padding: 10px;"
        "}"
        "QPushButton:hover {"
        "background-color: rgb(180, 40, 40);"
        "}"
        );
    QVBoxLayout  *layout = new QVBoxLayout(this); //vertical box layout, again this for the main window
    layout ->addWidget(title);
    layout -> addWidget(startButton, 0, Qt :: AlignCenter);
    layout -> addWidget(exitButton, 0, Qt :: AlignCenter);
    layout -> setSpacing(15); //spacing between buttons
    setLayout(layout); //setting the layout for the window
}
void MainWindow::openBookingWindow()
{
    BookingWindow *bookingwindow = new BookingWindow();
    bookingwindow -> show();
}

MainWindow::~MainWindow()
{

}
