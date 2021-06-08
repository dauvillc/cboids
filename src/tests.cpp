/* A few test functions */
#include "tests.h"
#include <random>
#include <iostream>
#include <math.h>
#include "mathtools.h"

/** Tests the correct functionning of the average angle
 * function */
void test_avg_angle(Drawer* drawer) {
    std::random_device rd;
    std::mt19937 gen(rd());
    drawer->clear();

    /* Define a few angles */
    size_t nb_angles = 2;
    std::uniform_real_distribution<> dis(-M_PI, M_PI);
    float angles[nb_angles];
    float weights[nb_angles] = {1, 2};
    drawer->reset_color();
    SDL_Color color = {255, 255, 0, 255};
    for (int i = 0; i < nb_angles; i++) {
        angles[i] = dis(gen);
        drawer->draw_point(
            cos(angles[i]) * 40 + 300,
            sin(angles[i]) * 40 + 300,
            &color
            );
    }
    SDL_Color avg_color = {255, 0, 0, 255};
    float avg_angle = angular_mean(angles, nb_angles, weights);
    drawer->draw_point(
        cos(avg_angle) * 40 + 300,
        sin(avg_angle) * 40 + 300,
        &avg_color
    );

    drawer->reset_color();
    drawer->draw_point(300, 300, NULL);
    drawer->update();
}