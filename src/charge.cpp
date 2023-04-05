#include <QPoint>

#include "vector.h"
#include "charge.h"


Charge::Charge(environment &env, int px, int py, int vx, int vy, float q, float mass, bool mobile)
    : env(env), position(px,py), velocity(vx, vy), q(q), mass(mass), mobile(mobile)
{ }


// TODO add friction force
// TODO add magntic field
void Charge::updateForce()
{
    force = Vector(0, 0);

    for (const auto& otherCharge : env.listOfCharge) {

        if (&otherCharge == this)
            continue;

        Vector r = this->position - otherCharge.position;

        force = force + ( r.normalize() * this->q * otherCharge.q / r.magnitudeSquerd() );
    }
    force = force * COULOMB_CONSTANT;
}


void Charge::updatePosition()
{
    if (!mobile)
        return;

    Vector acceleration = force / mass;

    position = (acceleration * env.deltaT * env.deltaT * 0.5) +
            (velocity * env.deltaT) + position;

    velocity = velocity + acceleration * env.deltaT;

    // TODO change the range for x and y
    if (position.getX() < -300 || position.getX() > 300) {
        velocity.setX(-velocity.getX());
    }

    if (position.getY() < -300 || position.getY() > 300) {
        velocity.setY(-velocity.getY());
    }
}


QPoint Charge::getPosition() const
{
    return QPoint(position.getX(), position.getY());
}


bool Charge::getSign() const
{
    return q > 0 ? true : false;
}
