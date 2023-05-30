#ifndef COULOSIM_H
#define COULOSIM_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Coulosim; }
QT_END_NAMESPACE

class Coulosim : public QMainWindow
{
    Q_OBJECT

public:
    Coulosim(QWidget *parent = nullptr);
    ~Coulosim();

private slots:
    void on_btn_add_charge_clicked();

    void on_pushButton_play_clicked();

    void on_pushButton_pause_clicked();

    void on_pushButton_reset_clicked();

    void on_pushButton_sample_1_clicked();

    void on_pushButton_sample_2_clicked();

    void on_pushButton_sample_3_clicked();

    void on_pushButton_sample_4_clicked();

private:
    Ui::Coulosim *ui;
};
#endif // COULOSIM_H
