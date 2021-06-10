#ifndef _BOID_H_
#define _BOID_H_
#include <memory>
#include <cstdlib>

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

/**
 * Element of a Boid_list
 */
class Boid_list_cell
{
private:
    std::shared_ptr<Boid> boid;
    std::shared_ptr<Boid_list_cell> next;
    std::shared_ptr<Boid_list_cell> prev;
public:
    Boid_list_cell(std::shared_ptr<Boid> boid,
                   std::shared_ptr<Boid_list_cell> next = NULL,
                   std::shared_ptr<Boid_list_cell> prev = NULL);
    /** Sets the pointer to the next boid cell. */
    void set_next(std::shared_ptr<Boid_list_cell> cell);
};

/**
 * Chained list of boids.
 */
class Boid_list
{
private:
    size_t size;
    std::shared_ptr<Boid_list_cell> head;
    std::shared_ptr<Boid_list_cell> tail;
public:
    Boid_list();
    void add_head(std::shared_ptr<Boid> boid);
    void add_tail(std::shared_ptr<Boid> boid);
};


#endif