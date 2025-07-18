#include "bookingwindow.h"
#include "mainwindow.h"
#include <QColor>
#include <QWidget>
#include <QLayout>
#include <QFont>
#include <QMessageBox>

const int row = 5;
const int columns = 10;

BookingWindow::BookingWindow(QWidget *parent): QWidget(parent) //constructor
{
    title = new QLabel("Please select the seats, you want", this);
    QFont font("Arial Black", 14, QFont :: Bold);
    title -> setFont(font);
    title -> setAlignment(Qt :: AlignCenter);
    green = new QLabel("GREEN: Available", this);
    QFont greenfont("Arial Black", 10, QFont :: Bold);
    green -> setFont(greenfont);
    green -> setAlignment(Qt :: AlignCenter);
    red = new QLabel("RED: Taken", this);
    QFont redfont("Arial Black", 10, QFont :: Bold);
    red -> setFont(redfont);
    red -> setAlignment(Qt :: AlignCenter);
    totalSeats = new QLabel(QString("Total Seats Available:%1 ").arg(totalseats));
    QFont font2("Arial Black", 10, QFont :: Bold);
    totalSeats -> setFont(font2);
    totalSeats -> setAlignment(Qt :: AlignCenter);
    seatsTaken = new QLabel(QString("Seats Taken:%1").arg(seatstaken));
    QFont font3("Arial Black", 10, QFont :: Bold);
    seatsTaken -> setFont(font3);
    seatsTaken -> setAlignment(Qt :: AlignCenter);
    priceperseat = new QLabel(QString("Price Per Seat: $%1 ").arg(seatperprice));
    QFont font4("Airal Black", 10, QFont :: Bold);
    priceperseat -> setFont(font4);
    priceperseat -> setAlignment(Qt :: AlignCenter);
    totalprice = new QLabel(QString("Total Price: $%1").arg(price));
    QFont font5("Arial Black", 10, QFont :: Bold);
    totalprice -> setFont(font5);
    totalprice -> setAlignment(Qt :: AlignCenter);


    //Setting the window title and size:
    setWindowTitle("Select Your Seats");
    resize(800, 600);


    //Background color:
    QPalette backgroundpalette;
    backgroundpalette.setColor(QPalette :: Window, QColor(30, 30, 40));
    setPalette(backgroundpalette);

    QGridLayout *gridLayout = new QGridLayout();
    gridLayout -> setSpacing(5); //space between the seats

    QPushButton *confirmButton = new QPushButton("Confirm Button", this);
    QPushButton *endButton = new QPushButton("Exit", this);
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            QPushButton *seatButton = new QPushButton(QString("R%1C%2").arg(i + 1).arg(j +1 ));
            seatButton-> setCheckable(true);
            seatButton-> setStyleSheet("QPushButton {"
                                    "background-color: green; color: black;"
                                    "}");
            seatButton-> setFixedSize(60, 60);
            gridLayout->addWidget(seatButton, i, j);
            connect(seatButton, &QPushButton :: clicked, this, [=]() mutable //mutable allows to modify values.
            {
                if(seatButton -> isChecked())
                {
                    seatButton -> setStyleSheet("background-color: red;");
                    seatstaken++;
                    price+=seatperprice;
                }
                else
                {
                    seatButton -> setStyleSheet("background-color: green;");
                    seatstaken--;
                    price-=seatperprice;
                }
                totalSeats -> setText(QString("Total Seats Available:%1").arg(totalseats - seatstaken));
                seatsTaken -> setText(QString("Seats Taken:%1").arg(seatstaken));
                totalprice -> setText(QString("Total Price: $%1").arg(price));
            });
        }
    }
    confirmButton -> setFixedSize(200, 50);
    endButton -> setFixedSize(200, 50);
    confirmButton -> setStyleSheet("QPushButton {"
                                 "background-color: rgb(76,175,80);"
                                 "color: white;"
                                 "border-radius: 5px;"
                                 "padding: 10px;"
                                 "}"
                                 "QPushButton:hover {"
                                 "background-color: rgb(56,142,60);"
                                 "}");
    endButton -> setStyleSheet("QPushButton {"
                             "background-color: rgb(211,47,47);"
                             "color: white;"
                             "border-radius: 5px;"
                             "padding: 10px;"
                             "}"
                             "QPushButton:hover {"
                             "background-color: rgb(198, 40, 40);"
                             "}");

    connect(endButton, &QPushButton :: clicked, this, &QWidget :: close);
    connect(confirmButton, &QPushButton :: clicked, this, [=](){
        QMessageBox messageBox;
        messageBox.setWindowTitle("Confirmation");
        QFont font5("Arial Black", 10, QFont :: Bold);
        messageBox.setFont(font5);
        messageBox.setText(QString("Youn have confirmed %1 seats for total price: $%2").arg(seatstaken).arg(price));
        messageBox.setStandardButtons(QMessageBox :: Ok);
        if(messageBox.exec() == QMessageBox :: Ok)
        {
            this -> close();
        }
    });
    QVBoxLayout *mainlayout = new QVBoxLayout(this);


    QHBoxLayout  *buttonlayout = new QHBoxLayout();
    buttonlayout -> addWidget(endButton);
    buttonlayout -> addWidget(confirmButton);
    buttonlayout -> setSpacing(20);
    buttonlayout -> setAlignment(Qt :: AlignCenter);

    QHBoxLayout *legendlayout = new QHBoxLayout();
    legendlayout -> addWidget(green);
    legendlayout -> addWidget(red);


    mainlayout -> addWidget(title);
    mainlayout -> addWidget(totalSeats);
    mainlayout -> addWidget(seatsTaken);
    mainlayout -> addWidget(priceperseat);
    mainlayout -> addWidget(totalprice);
    mainlayout -> addLayout(legendlayout);
    mainlayout -> addLayout(gridLayout);
    mainlayout -> addLayout(buttonlayout);

    setLayout(mainlayout);

}

BookingWindow::~BookingWindow()
{

}
