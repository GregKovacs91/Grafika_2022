#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Scene
{
    Model map_model;
	Model map_floor_model;
	Model ghost_1_model;
	Model ghost_2_model;
	Model ghost_3_model;
	Model the_ghost_model;
	Model balls_model;
    Material material;
    GLuint map_texture_id;
	GLuint map_floor_texture_id;
	GLuint ghost_1_texture_id;
	GLuint ghost_2_texture_id;
	GLuint ghost_3_texture_id;
	GLuint the_ghost_texture_id;
	GLuint balls_texture_id;
	GLuint help_texture_id;
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting();

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Draw the scene objects.
 */
void draw_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

void ghostrotate(double time);

#endif /* SCENE_H */
