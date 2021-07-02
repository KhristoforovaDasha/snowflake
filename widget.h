#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMessageBox>;
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void paintEvent(QPaintEvent * event);
    void do_paint(double x1,double y1,double x2,double y2,double x3,double y3,int num);
    void fractal(double x1,double y1,double x2,double y2,int num);
private slots:

    void on_forward_clicked();

    void on_back_clicked();

private:
    Ui::Widget *ui;
    int number = 0;
    int size = 100;
};
#endif // WIDGET_H
