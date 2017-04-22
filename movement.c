#include "wolf3d.h"

void move_forward(t_connection *obj, double move_speed)
{
  if(worldMap[(int)(obj->pos.x + obj->pos.dir_x * move_speed)][(int)(obj->pos.y)] == 0)
        obj->pos.x += obj->pos.dir_x * move_speed;
  if(worldMap[(int)(obj->pos.x)][(int)(obj->pos.y + obj->pos.dir_y * move_speed)] == 0)
        obj->pos.y += obj->pos.dir_y * move_speed;
}

void move_backwards(t_connection *obj, double move_speed)
{
  if(!worldMap[(int)(obj->pos.x - obj->pos.dir_x * move_speed)][(int)(obj->pos.y)])
    obj->pos.x -= obj->pos.dir_x * move_speed;
  if(!worldMap[(int)(obj->pos.x)][(int)(obj->pos.y - obj->pos.dir_y * move_speed)])
    obj->pos.y -= obj->pos.dir_y * move_speed;
}

void rotate_left(t_connection *obj, double rotation_speed)
{
  double oldDirX;
  double oldPlaneX;

      oldDirX = obj->pos.dir_x;
      obj->pos.dir_x = obj->pos.dir_x * cos(rotation_speed) - obj->pos.dir_y * sin(rotation_speed);
      obj->pos.dir_y = oldDirX * sin(rotation_speed) + obj->pos.dir_y * cos(rotation_speed);
      oldPlaneX = obj->pos.plane_x;
      obj->pos.plane_x = obj->pos.plane_x * cos(rotation_speed) - obj->pos.plane_y * sin(rotation_speed);
      obj->pos.plane_y = oldPlaneX * sin(rotation_speed) + obj->pos.plane_y * cos(rotation_speed);

}

void rotate_right(t_connection *obj, double rotation_speed)
{
    double oldDirX;
    double oldPlaneX;

      oldDirX = obj->pos.dir_x;
      obj->pos.dir_x = obj->pos.dir_x * cos(-rotation_speed) - obj->pos.dir_y * sin(-rotation_speed);
      obj->pos.dir_y = oldDirX * sin(-rotation_speed) + obj->pos.dir_y * cos(-rotation_speed);
      oldPlaneX = obj->pos.plane_x;
      obj->pos.plane_x = obj->pos.plane_x * cos(-rotation_speed) - obj->pos.plane_y * sin(-rotation_speed);
      obj->pos.plane_y = oldPlaneX * sin(-rotation_speed) + obj->pos.plane_y * cos(-rotation_speed);
}

void move_check(t_connection *obj)
{
  double move_speed;
  double rotation_speed;
  
  rotation_speed = 0.1;
  move_speed = 0.15;
  if (obj->key.w == 1)
        move_forward(obj, move_speed);
  if (obj->key.s == 1)
        move_backwards(obj, move_speed);
  if (obj->key.a == 1)
        rotate_left(obj, rotation_speed);
  if (obj->key.d == 1)
    rotate_right(obj, rotation_speed);
}
