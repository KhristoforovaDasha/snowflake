#include "widget.h"
#include "ui_widget.h"
#include <cmath>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(800,800);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::FlatCap));
        double x1,y1,x2,y2,x3,y3;
        x1 = 150,y1= 150,x2 = 600,y2 = 150,y3 = 225*(std::sqrt(3)) + 150, x3 = 375;
        fractal(x2,y2,x1,y1,number);
        fractal(x3,y3,x2,y2,number);
        fractal(x1,y1,x3,y3,number);
        /*painter.drawLine(x1,y1,x2,y2);
        painter.drawLine(x1,y1,x3,y3);
        painter.drawLine(x2,y2,x3,y3);
        if(number >= 1) {
            do_paint(x1,y1,x2,y2,x3,y3,number);
            do_paint(x3,y3,x1,y1,x2,y2,number);
            do_paint(x2,y2,x3,y3,x1,y1,number);
         }*/
}
void Widget::do_paint(double x1,double y1,double x2,double y2,double x3,double y3,int num){
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::FlatCap));
    if(num > 0){
       double x4 = (x2 + 2*x1)/3;
       double y4 = (y2 + 2*y1)/3;
       double x5 = (2*x2 + x1)/3;
       double y5 = (2*y2 + y1)/3;
       double x_new = (2*(x1 + x2) - x3)/3;
       double y_new = (2*(y1 + y2) - y3)/3;
       painter.drawLine(x4,y4,x_new,y_new);
       painter.drawLine(x5,y5,x_new,y_new);
       painter.setPen(QPen(Qt::white,3, Qt::SolidLine, Qt::FlatCap));
       painter.drawLine(x4+1,y4,x5-1,y5);
       do_paint(x4,y4,x_new,y_new,x5,y5,num - 1);
       do_paint(x5,y5,x_new,y_new,x4,y4,num - 1);
       do_paint(x1,y1,x4,y4,(2*x1 + x3)/3,(2*y1 + y3)/3,num - 1);
       do_paint(x5,y5,x2,y2,(2*x2 + x3)/3,(2*y2 + y3)/3,num - 1);
    }
}
void Widget::fractal(double x1,double y1,double x2,double y2,int num){
     QPainter painter(this);
     painter.setPen(QPen(Qt::black, 0.8, Qt::SolidLine, Qt::RoundCap));
     if(num == 0){
         painter.drawLine(x1,y1,x2,y2);
     }
     else{
         fractal(x1,y1,(x2 + 2*x1)/3,(y2 + 2*y1)/3,num - 1);
         fractal((x2 + 2*x1)/3,(y2 + 2*y1)/3,(x2 - x1)/6 - (y2 - y1)/6*(std::sqrt(3))+ (2*x1+x2)/3,(x2 - x1)/6*(std::sqrt(3)) + (y2 - y1)/6 +(2*y1+y2)/3,num - 1);
         fractal((x2 - x1)/6 - (y2 - y1)/6*(std::sqrt(3))+ (2*x1+x2)/3,(x2 - x1)/6*(std::sqrt(3)) + (y2 - y1)/6 +(2*y1+y2)/3,(2*x2 + x1)/3,(2*y2 + y1)/3,num - 1);
         fractal((2*x2 + x1)/3,(2*y2 + y1)/3,x2,y2,num - 1);
     }
}
void Widget::on_forward_clicked()
{
    if(number <= 6) number++,repaint();
    else {
        QMessageBox msg;
        msg.setText("Снежинка и так уже слишком большая!");
        msg.exec();
    }
}

void Widget::on_back_clicked()
{
    if(number > 0) number--,repaint();
}
