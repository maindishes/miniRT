#ifndef TRACE.H
#define TRACE.H

# include "structers.h"
# include "utils.h"

t_ray	ray(t_point3 orig, t_vec3 dir);
t_point3	ray_at(t_ray *ray, double t);

# endif




