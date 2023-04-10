#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>

#include "vector.h"
#include "charge.h"


class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

    void addCharge(int px, int py, int vx, int vy, float q, float mass, bool mobile);
    void setEnv(float magnetic, float electric_x, float electric_y, float speed, float deltaT, float refresh);

    void play();
    void pause();
    void reset();

signals:

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    void drawCoordinates(QPainter& painter);
    void drawCharges(QPainter& painter);
    void updateCharges();


    struct environment env;

    QTimer* timer;
    float speed;   // refresh rate coefficient
    float refresh; // refresh rate of RenderArea widget in milliseconds
    float repeat;  // the number of repetition required for the updateCharges function based on speed and refresh
    bool isPlay;
    int elapsed;

};

#endif // RENDERAREA_H
