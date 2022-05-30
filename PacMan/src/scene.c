#include "scene.h"

#include <GL/glut.h>
#include <stdio.h> 
#include "SOIL/SOIL.h"  
#define TRUE 1 
#define FALSE 0  
#define INVALID_VERTEX_INDEX 0
#include "GL/glut.h"

#include <obj/load.h>
#include <obj/draw.h>

double rotate;
double a = 0;



void ghostrotate(double time)
{
	rotate += time*a;
}

void init_scene(Scene* scene)
{
	load_model(&(scene->map_model), "models/map.obj");
    scene->map_texture_id = load_texture("textures/map_texture.png");
	
	load_model(&(scene->map_floor_model), "models/map_floor.obj");
    scene->map_floor_texture_id = load_texture("textures/map_floor_texture.png");
	
	load_model(&(scene->ghost_1_model), "models/ghost_1.obj");
    scene->ghost_1_texture_id = load_texture("textures/ghost_1_texture.png");
	
	load_model(&(scene->ghost_2_model), "models/ghost_2.obj");
    scene->ghost_2_texture_id = load_texture("textures/ghost_2_texture.png");
	
	load_model(&(scene->ghost_3_model), "models/ghost_3.obj");
    scene->ghost_3_texture_id = load_texture("textures/ghost_3_texture.png");
	
	load_model(&(scene->the_ghost_model), "models/the_ghost.obj");
    scene->the_ghost_texture_id = load_texture("textures/the_ghost_texture.png");
	
	load_model(&(scene->balls_model), "models/balls.obj");
    scene->balls_texture_id = load_texture("textures/balls_texture.png");
	
	scene->help_texture_id = load_texture("textures/help.png");

    scene->material.ambient.red = 0.2;
    scene->material.ambient.green = 0.2;
    scene->material.ambient.blue = 0.2;

    scene->material.diffuse.red = 1;
    scene->material.diffuse.green = 1;
    scene->material.diffuse.blue = 1;

    scene->material.specular.red = 0.3;
    scene->material.specular.green = 0.3;
    scene->material.specular.blue = 0.3;

    scene->material.shininess = 10;
	
	set_lighting();
}


void set_lighting()
{
    float ambient_light[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    float diffuse_light[] = { 0.5f, 0.5f, 0.5, 1.0f };
    float specular_light[] = { 3.0f, 3.0f, 3.0f, 3.0f };
    float position[] = { 70.0f, 20.0f, 80.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void draw_scene(const Scene* scene)
{
	glEnable(GL_TEXTURE_2D);
	
	glPushMatrix();
    set_material(&(scene->material));
	draw_origin();
	glPopMatrix();
	
    glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->map_texture_id);
    draw_model(&(scene->map_model));
	glPopMatrix();
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->map_floor_texture_id);
	draw_model(&(scene->map_floor_model));
	glPopMatrix();
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->balls_texture_id);
	draw_model(&(scene->balls_model));
	glPopMatrix();
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->ghost_1_texture_id);
	glTranslatef(0, 8.0, 1);
	glRotatef(0+rotate,0,0,1);
	draw_model(&(scene->ghost_1_model));
	glPopMatrix();
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->ghost_2_texture_id);
	glTranslatef(0, -1.5, 1);
	glRotatef(0+rotate,0,0,1);
	draw_model(&(scene->ghost_2_model));
	glPopMatrix();
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->ghost_3_texture_id);
	glTranslatef(0, 1.5, 1);
	glRotatef(0+rotate,0,0,1);
	draw_model(&(scene->ghost_3_model));
	glPopMatrix();
	
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->the_ghost_texture_id);
	glTranslatef(0, -10.0, 1);
	glRotatef(0+rotate,0,0,1);
	draw_model(&(scene->the_ghost_model));
	glPopMatrix();
	
	glBindTexture(GL_TEXTURE_2D, scene->help_texture_id);
	
	glEnd();
}


void set_ghostrotate(int x)
{
	a = x;
}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}
