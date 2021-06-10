#include <math.h>
#include "boid.h"


Boid::Boid(int x0, int y0, float initial_direction) :
x(x0), y(y0), direction(initial_direction)
{}

/** Updates the boid's location according to its direction
    and the given speed. */
void Boid::update_location(float speed) {

    /* Because the grid's vertical axis increases downwards,
       we need to substract the sin of the direction */
    this->x += cos(this->direction);
    this->y -= sin(this->direction);
}


/* BOID LIST CELL -------------------------------------------------- */

Boid_list_cell::Boid_list_cell(std::shared_ptr<Boid> boid,
                               std::shared_ptr<Boid_list_cell> next,
                               std::shared_ptr<Boid_list_cell> prev)
{
    boid = boid;
    next = next;
    prev = prev;
}

/** Sets the pointer to the next boid cell */
void Boid_list_cell::set_next(std::shared_ptr<Boid_list_cell> cell) {
    next = cell;
}

/* BOID LIST -------------------------------------------------------- */

Boid_list::Boid_list(): size(0), head(NULL), tail(NULL) {}

void Boid_list::add_head(std::shared_ptr<Boid> boid) {
    size++;
    head = std::shared_ptr<Boid_list_cell>(new Boid_list_cell(boid, head));
}

void Boid_list::add_tail(std::shared_ptr<Boid> boid) {
    size++;
    tail->set_next(std::shared_ptr<Boid_list_cell>(new Boid_list_cell(boid)));
}