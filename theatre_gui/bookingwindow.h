#ifndef BOOKINGWINDOW_H
#define BOOKINGWINDOW_H
#include<QWidget>
#include<QPushButton>
#include<QLabel>
#include<QBoxLayout>

class BookingWindow : public QWidget
{
    Q_OBJECT
public:
    explicit BookingWindow(QWidget *parent = nullptr);
    QGridLayout *gridLayout;
    QVector<QPushButton*> seats;
    ~BookingWindow();
private:
    const int row = 5;
    const int columns = 10;
    int totalseats = row * columns;
    int seatstaken = 0;
    int price = 0;
    const int seatperprice = 3;

    QLabel *title;
    QLabel *green;
    QLabel *red;
    QLabel *totalSeats;
    QLabel *seatsTaken;
    QLabel *priceperseat;
    QLabel *totalprice;
};

#endif // BOOKINGWINDOW_H
