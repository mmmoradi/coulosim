#include "coulosim.h"
#include "ui_coulosim.h"

Coulosim::Coulosim(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Coulosim)
{
    ui->setupUi(this);
}

Coulosim::~Coulosim()
{
    delete ui;
}


void Coulosim::on_btn_add_charge_clicked()
{
    int px = ui->spinBox_px->value();
    int py = ui->spinBox_py->value();

    int vx = ui->spinBox_vx->value();
    int vy = ui->spinBox_vy->value();

    float q = ui->doubleSpinBox_q->value();

    float mass = ui->doubleSpinBox_mass->value();

    bool mobile = ui->checkBox_mobile->isChecked();

    ui->renderArea->addCharge(px, py, vx, vy, q, mass, mobile);
}


void Coulosim::on_pushButton_play_clicked()
{
    ui->renderArea->play(ui->doubleSpinBox_speed->value());
}


void Coulosim::on_pushButton_pause_clicked()
{
    ui->renderArea->pause();
}


void Coulosim::on_pushButton_reset_clicked()
{
    ui->renderArea->reset();
}
