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
    ui->renderArea->addCharge(ui->doubleSpinBox_px->value(),
                              ui->doubleSpinBox_py->value(),
                              ui->doubleSpinBox_vx->value(),
                              ui->doubleSpinBox_vy->value(),
                              ui->doubleSpinBox_q->value(),
                              ui->doubleSpinBox_mass->value(),
                              ui->checkBox_mobile->isChecked()
                              );
}


void Coulosim::on_pushButton_play_clicked()
{
    ui->renderArea->setEnv(ui->doubleSpinBox_magnetic->value(),
                           ui->doubleSpinBox_electric_x->value(),
                           ui->doubleSpinBox_electric_y->value(),
                           ui->doubleSpinBox_speed->value(),
                           ui->doubleSpinBox_deltaT->value(),
                           ui->doubleSpinBox_refresh->value()
                           );
    ui->renderArea->play();
}


void Coulosim::on_pushButton_pause_clicked()
{
    ui->renderArea->pause();
}


void Coulosim::on_pushButton_reset_clicked()
{
    ui->renderArea->reset();
}


void Coulosim::on_pushButton_sample_1_clicked()
{
    ui->doubleSpinBox_electric_x->setValue(0);
    ui->doubleSpinBox_electric_y->setValue(0);
    ui->doubleSpinBox_magnetic->setValue(0);
    ui->doubleSpinBox_speed->setValue(1);

    ui->renderArea->addCharge(0,0,0,0,0.001,1,0);
    ui->renderArea->addCharge(-50,20,15,0,-0.001,1,1);
}


void Coulosim::on_pushButton_sample_2_clicked()
{
    ui->doubleSpinBox_electric_x->setValue(0.10);
    ui->doubleSpinBox_electric_y->setValue(0);
    ui->doubleSpinBox_magnetic->setValue(0);
    ui->doubleSpinBox_speed->setValue(1);

    ui->renderArea->addCharge(0,0,0,0,-0.001,0.000001,1);
}


void Coulosim::on_pushButton_sample_3_clicked()
{
    ui->doubleSpinBox_electric_x->setValue(0);
    ui->doubleSpinBox_electric_y->setValue(0);
    ui->doubleSpinBox_magnetic->setValue(-0.01);
    ui->doubleSpinBox_speed->setValue(10);

    ui->renderArea->addCharge(0,0,1,0,0.000001,0.000001,1);
}


void Coulosim::on_pushButton_sample_4_clicked()
{
    ui->doubleSpinBox_electric_x->setValue(0);
    ui->doubleSpinBox_electric_y->setValue(0);
    ui->doubleSpinBox_magnetic->setValue(0);
    ui->doubleSpinBox_speed->setValue(0.01);

    ui->renderArea->addCharge(0,0,0,0,-1,1,0);
    ui->renderArea->addCharge(0,100,9480,0,1,1,1);
}

