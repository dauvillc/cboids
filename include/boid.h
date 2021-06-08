#ifndef _BOID_H_
#define _BOID_H_

/* In this simulation, a boid is an individual which
moves at a fixed speed and only decides of its direction.
The decision is taken according to a set of rules (including
the original rules of boids).
Each boid attributes its own weights to every rule, which
in the end leads to various behaviors within the group.
*/
class Boid
{
private:
    int x, y;
    float direction;
public:
    Boid(int x0, int y0, float initial_direction);

    /* Updates the boid location following the boid's direction
     and the given speed */
    void update_location(float speed);
};


#endif