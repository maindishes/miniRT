#ifndef SCENE_H
# define SCENE_H

#include "strictures.h"
#include "utils.h"

t_canvas	canvas(int widht, int height);
t_camera	camera(t_canvas *canvas, t_point3 origin);
#endif



