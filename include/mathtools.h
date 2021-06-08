#ifndef _MATHTOOLS_H_
#define _MATHTOOLS_H_
#include <ctype.h>

/* Defines useful tools */

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
    float const* weights);

#endif