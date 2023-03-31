#ifndef CHARGE_H
#define CHARGE_H

#include <QPoint>


#define COULOMB_CONSTANT (8.9875517923e9)
#define ELECTRON_MASS    (9.1093837e-31)


class Vector;


class Charge
{
private:
    Vector position;
    Vector velocity;
    Vector force;
    float q;
    float mass;
    bool mobile;

public:
    Charge();
    Charge(int px, int py, int vx, int vy, float q, float mass, bool mobile);

    void updateForce(std::vector<Charge>& charges);
    void updatePosition(float deltaT);

    QPoint getPosition() const;
    bool getSign() const;
};

#endif // CHARGE_H
