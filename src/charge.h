#ifndef CHARGE_H
#define CHARGE_H

#include <QPoint>


#define COULOMB_CONSTANT (8.9875517923e9)
#define ELECTRON_MASS    (9.1093837e-31)

class Charge;
struct environment {
    std::vector<Charge> listOfCharge;
    float deltaT;
};


class Vector;


class Charge
{
private:
    struct environment& env;
    Vector position;
    Vector velocity;
    Vector force;
    float q;
    float mass;
    bool mobile;


public:
    Charge(struct environment& env, int px, int py, int vx, int vy, float q, float mass, bool mobile);

    void updateForce();
    void updatePosition();

    QPoint getPosition() const;
    bool getSign() const;
};

#endif // CHARGE_H
