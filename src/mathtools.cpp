#include "mathtools.h"
#include <math.h>

/* Returns the average of the angles given.
   -- angles: Tab containing the angles in radiants
   -- nb_angles: Number of angles
   -- weights: If not NULL, a tab of values of the same
        size as angles, indicating the weights which should
        be used to ponderate the averaged sum.

   The average is the angular mean and is defined
   as the angle of the center of mass of the points on
   the unit circle defined by the given angles. All angles
   are in radiants and are taken from the horizontal axis.
*/
float angular_mean(float const* angles, int nb_angles, 
    float const* weights)
{
    /* First, we convert the angles to points on the unit
       circle and compute the average of those points */
    float avg_cosine = 0;
    float avg_sine = 0;
    if (weights == NULL) {
        for (int i = 0; i < nb_angles; i++) {
            avg_cosine += cos(angles[i]);
            avg_sine += sin(angles[i]);
        }
    } else {
        for (int i = 0; i < nb_angles; i++) {
            avg_cosine += cos(angles[i]) * weights[i];
            avg_sine += sin(angles[i]) * weights[i];
        }
    }
    avg_cosine /= nb_angles;
    avg_sine /= nb_angles;

    /* Now, we take the arctan2 of the obtained average point
       to obtain an intuitive mean angle */
    return atan2(avg_sine, avg_cosine);
}