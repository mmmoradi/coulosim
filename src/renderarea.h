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
    void setEnv(float magnetic, float electric_x, float electric_y);

    void play(float s);
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

    float speed;
    QTimer* timer;
    bool isPlay;
    int elapsed;

};

#endif // RENDERAREA_H
