#include "vector.h"
#include "charge.h"
#include "renderarea.h"


RenderArea::RenderArea(QWidget *parent)
    : QWidget{parent}
{
    timer = new QTimer(this);
    isPlay = false;
}


QSize RenderArea::minimumSizeHint() const
{
    return QSize(200,200);
}


QSize RenderArea::sizeHint() const
{
    return QSize(400,400);
}


// TODO add charge object into dynamic memory
void RenderArea::addCharge(int px, int py, int vx, int vy, float q, float mass, bool mobile)
{
    if (q == 0)
        return;
    listOfCharge.push_back(Charge(px, py, vx, vy, q, mass, mobile));
    update();
}


void RenderArea::play(float s)
{
    speed = s;
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(16); // 16ms = 62.5 FPS
    isPlay = true;
}


void RenderArea::pause()
{
    timer->stop();
    // TODO just stop timer
    disconnect(timer, SIGNAL(timeout()), this, SLOT(update()));
    isPlay = false;
}


void RenderArea::reset()
{
    pause();
    listOfCharge.clear();
    update();
}


// TODO add vector field
void RenderArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(event->rect(), QBrush(Qt::white));

    // Transformations based on real world cordinate system
    painter.translate(width() / 2, height() / 2);
    painter.scale(1,-1);

    drawCoordinates(painter);

    if (isPlay)
        // 160 * 0.0001 = 0.016ms
        for (unsigned long i = 0; i < (160 * speed); i++)
            updateCharges();

    drawCharges(painter);
}


void RenderArea::drawCoordinates(QPainter& painter)
{
    painter.setPen(Qt::red);

    painter.drawLine(-width() / 2, 0, width() / 2, 0);
    painter.drawLine(width() / 2 - 4, -4, width() / 2, 0);
    painter.drawLine(width() / 2 - 4, 4, width() / 2, 0);
    painter.drawText(width() / 2 - 10,-10, tr("x"));

    painter.drawLine(0, -height() / 2, 0, height() / 2);
    painter.drawLine(4, height() / 2 - 4, 0, height() / 2);
    painter.drawLine(-4, height() / 2 - 4, 0, height() / 2);
    painter.drawText(-10, height() / 2 - 10, tr("y"));
}


void RenderArea::drawCharges(QPainter& painter)
{
    //TODO add these QPen to class attribute
    QPen pcharge = QPen(Qt::blue,10,Qt::SolidLine,Qt::RoundCap);
    QPen ncharge = QPen(Qt::red,10,Qt::SolidLine,Qt::RoundCap);

    for (auto& charge : listOfCharge) {
        if (charge.getSign())
            painter.setPen(pcharge);
        else
            painter.setPen(ncharge);

        painter.drawPoint(charge.getPosition());
    }
}


void RenderArea::updateCharges()
{
    for (auto& charge : listOfCharge) {
        charge.updateForce(listOfCharge);
    }

    for (auto& charge : listOfCharge) {
        charge.updatePosition(0.0001); // deltaT = 0.0001
    }
}
