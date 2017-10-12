//
//  main.cpp
//  informaticaGrafica
//
//  Created by Iván Rodríguez Millán on 28/9/17.
//  Copyright © 2017 Iván Rodríguez Millán. All rights reserved.
//

#include <vector>
#include "stdio.h"
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "vertex.h"
#include "objeto.h"
#include "triangulos.h"
#include "cubo.h"
#include "piramide.h"
#include "figura_ply.h"

#if defined(__APPLE__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

rendering_mode mode = VERTICES;
object_type obj = CUBE;
object_ply obj_ply = TUBE;

vector<_vertex3f> tubo ={{5,-5,0},{5,5,0}};
vector<_vertex3f> cono ={{5,-5,0},{0,-5,0},{0,5,0}};
vector<_vertex3f> vaso ={{2.5,-5,0},{5,5,0},{0,-5,0}};
vector<_vertex3f> vasoI ={{5,-5,0},{2.5,5,0},{0,5,0}};
vector<_vertex3f> cilindro ={{5,-5,0},{5,5,0},{0,-5,0},{0,5,0}};

Cubo cubo(4);
Piramide piramide(10, 10);
FiguraPly objeto_ply ("/Users/Ivanovic/Documents/Graphic-Computer/informaticaGrafica/beethoven.ply");

FiguraPly tuboRevolucion(tubo);
FiguraPly coneRevolucion(cono);
FiguraPly vasoRevolucion(vaso);
FiguraPly vasoRevolucionI(vasoI);
FiguraPly cilindroRevolucion(cilindro);

// tamaño de los ejes
const int AXIS_SIZE=5000;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Window_width,Window_height,Front_plane,Back_plane;

// variables que determninan la posicion y tamaño de la ventana X
int UI_window_pos_x=50,UI_window_pos_y=50,UI_window_width=500,UI_window_height=500;

//**************************************************************************
//
//***************************************************************************

void clear_window()
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void change_projection()
{
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	// formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
	//  Front_plane>0  Back_plane>PlanoDelantero)
	glFrustum(-Window_width,Window_width,-Window_height,Window_height,Front_plane,Back_plane);
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void change_observer()
{
	
	// posicion del observador
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0,0,-Observer_distance);
	glRotatef(Observer_angle_x,1,0,0);
	glRotatef(Observer_angle_y,0,1,0);
}

//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void draw_axis()
{
	glBegin(GL_LINES);
	// eje X, color rojo
	glColor3f(1,0,0);
	glVertex3f(-AXIS_SIZE,0,0);
	glVertex3f(AXIS_SIZE,0,0);
	// eje Y, color verde
	glColor3f(0,1,0);
	glVertex3f(0,-AXIS_SIZE,0);
	glVertex3f(0,AXIS_SIZE,0);
	// eje Z, color azul
	glColor3f(0,0,1);
	glVertex3f(0,0,-AXIS_SIZE);
	glVertex3f(0,0,AXIS_SIZE);
	glEnd();
}


//**************************************************************************
// Funcion que dibuja los objetos
//***************************************************************************

void draw_objects()
{
	switch(obj){
		case CUBE:
			switch (mode) {
				case VERTICES:
					cubo.draw_points();
					break;
				case ARISTAS:
					cubo.draw_edges();
					break;
					
				case SOLID:
					cubo.draw_solid();
					break;
					
				case CHESS:
					cubo.draw_chess();
					break;
					
				case P_A:
					cubo.draw_circulos(0.5, 50, GL_FILL);
					break;
			}
		break;
		case PYRAMID:
			switch (mode) {
				case VERTICES:
					piramide.draw_points();
					break;
				case ARISTAS:
					piramide.draw_edges();
					break;
					
				case SOLID:
					piramide.draw_solid();
					break;
					
				case CHESS:
					piramide.draw_chess();
					break;
					
				case P_A:
					piramide.draw_circulos(0.5, 50, GL_FILL);
					break;
			}
			break;
            
        case OBJECT_PLY:
            switch (mode) {
                case VERTICES:
                    objeto_ply.draw_points();
                    break;
                case ARISTAS:
                    objeto_ply.draw_edges();
                    break;
                    
                case SOLID:
                    objeto_ply.draw_solid();
                    break;
                    
                case CHESS:
                    objeto_ply.draw_chess();
                    break;
            }
            break;
            
        case OBJECT_REV:
            
            switch (obj_ply) {
                    
                case CYLINDER:
                    
                    switch (mode) {
                            
                        case VERTICES:
                            cilindroRevolucion.draw_points();
                            break;
                        case ARISTAS:
                            cilindroRevolucion.draw_edges();
                            break;
                            
                        case SOLID:
                            cilindroRevolucion.draw_solid();
                            break;
                            
                        case CHESS:
                            cilindroRevolucion.draw_chess();
                            break;
                            
                        case REVOLUTION:
                            cilindroRevolucion.revolution(20);
                            break;
                    }
                    break;
                    
                case TUBE:
                    
                    switch (mode) {
                            
                        case VERTICES:
                            tuboRevolucion.draw_points();
                            break;
                        case ARISTAS:
                            tuboRevolucion.draw_edges();
                            break;
                            
                        case SOLID:
                            tuboRevolucion.draw_solid();
                            break;
                            
                        case CHESS:
                            tuboRevolucion.draw_chess();
                            break;
                            
                        case REVOLUTION:
                            tuboRevolucion.revolution(20);
                            break;
                    }
                    break;
                    
                case CONE:
                    
                    switch (mode) {
                            
                        case VERTICES:
                            coneRevolucion.draw_points();
                            break;
                        case ARISTAS:
                            coneRevolucion.draw_edges();
                            break;
                            
                        case SOLID:
                            coneRevolucion.draw_solid();
                            break;
                            
                        case CHESS:
                            coneRevolucion.draw_chess();
                            break;
                            
                        case REVOLUTION:
                            coneRevolucion.revolution(20);
                            break;
                    }
                    break;
                    
                case GLASS:
                    
                    switch (mode) {
                            
                        case VERTICES:
                            vasoRevolucion.draw_points();
                            break;
                            
                        case ARISTAS:
                            vasoRevolucion.draw_edges();
                            break;
                            
                        case SOLID:
                            vasoRevolucion.draw_solid();
                            break;
                            
                        case CHESS:
                            vasoRevolucion.draw_chess();
                            break;
                            
                        case REVOLUTION:
                            vasoRevolucion.revolution(20);
                            break;
                    }
                    break;
                    
                case GLASS_I:
                    
                    switch (mode) {
                            
                        case VERTICES:
                            vasoRevolucionI.draw_points();
                            break;
                        case ARISTAS:
                            vasoRevolucionI.draw_edges();
                            break;
                            
                        case SOLID:
                            vasoRevolucionI.draw_solid();
                            break;
                            
                        case CHESS:
                            vasoRevolucionI.draw_chess();
                            break;
                            
                        case REVOLUTION:
                            vasoRevolucionI.revolution(20);
                            break;
                    }
                    break;
                    
            }
            break;
	}
}


//**************************************************************************
//
//***************************************************************************

void draw_scene(void)
{
	
	clear_window();
	change_observer();
	draw_axis();
	draw_objects();
	glutSwapBuffers();
}



//***************************************************************************
// Funcion llamada cuando se produce un cambio en el tamaño de la ventana
//
// el evento manda a la funcion:
// nuevo ancho
// nuevo alto
//***************************************************************************

void change_window_size(int Ancho1,int Alto1)
{
	change_projection();
	glViewport(0,0,Ancho1,Alto1);
	glutPostRedisplay();
}


//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla normal
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton
//***************************************************************************

void normal_keys(unsigned char Tecla1,int x,int y)
{
	
	switch (toupper(Tecla1)) {
		case 'Q':
			exit(0);
			break;
		case 'P':
			mode = VERTICES;
			break;
			
		case 'S':
			mode = SOLID;
			break;
			
		case 'A':
			mode = ARISTAS;
			break;
			
		case 'C':
			mode = CHESS;
			break;
			
		case 'N':
			mode = P_A;
			break;
            
        case 'R':
            mode = REVOLUTION;
            break;
            
        case '1':
            obj_ply = TUBE;
            break;
            
        case '2':
            obj_ply = CYLINDER;
            break;
            
        case '3':
            obj_ply = CONE;
            break;
            
        case '4':
            obj_ply = GLASS;
            break;
            
        case '5':
            obj_ply = GLASS_I;
            break;
	}
	
	glutPostRedisplay();
}

//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla especial
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton

//***************************************************************************

void special_keys(int Tecla1,int x,int y)
{
	
	switch (Tecla1){
		case GLUT_KEY_LEFT:Observer_angle_y--;break;
		case GLUT_KEY_RIGHT:Observer_angle_y++;break;
		case GLUT_KEY_UP:Observer_angle_x--;break;
		case GLUT_KEY_DOWN:Observer_angle_x++;break;
		case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
		case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
            
        case GLUT_KEY_F1:
            obj = PYRAMID;
            break;
        case GLUT_KEY_F2:
            obj = CUBE;
            break;
        case GLUT_KEY_F3:
            obj = OBJECT_PLY;
            break;
            
        case GLUT_KEY_F4:
            obj = OBJECT_REV;
            break;
	}
	
	glutPostRedisplay();
}



//***************************************************************************
// Funcion de incializacion
//***************************************************************************

void initialize(void)
{
	// se inicalizan la ventana y los planos de corte
	Window_width=5;
	Window_height=5;
	Front_plane=10;
	Back_plane=1000;
	
	// se inicia la posicion del observador, en el eje z
	Observer_distance=2*Front_plane;
	Observer_angle_x=0;
	Observer_angle_y=0;
	
	// se indica cual sera el color para limpiar la ventana	(r,v,a,al)
	// blanco=(1,1,1,1) rojo=(1,0,0,1), ...
	glClearColor(1,1,1,1);
	
	// se habilita el z-bufer
	glEnable(GL_DEPTH_TEST);
	//
	change_projection();
	//
	glViewport(0,0,UI_window_width,UI_window_height);
}


//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************

int main(int argc, char **argv)
{
	
	// se llama a la inicialización de glut
	glutInit(&argc, argv);
	
	// se indica las caracteristicas que se desean para la visualización con OpenGL
	// Las posibilidades son:
	// GLUT_SIMPLE -> memoria de imagen simple
	// GLUT_DOUBLE -> memoria de imagen doble
	// GLUT_INDEX -> memoria de imagen con color indizado
	// GLUT_RGB -> memoria de imagen con componentes rojo, verde y azul para cada pixel
	// GLUT_RGBA -> memoria de imagen con componentes rojo, verde, azul y alfa para cada pixel
	// GLUT_DEPTH -> memoria de profundidad o z-bufer
	// GLUT_STENCIL -> memoria de estarcido
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	
	// posicion de la esquina inferior izquierdad de la ventana
	glutInitWindowPosition(UI_window_pos_x,UI_window_pos_y);
	
	// tamaño de la ventana (ancho y alto)
	glutInitWindowSize(UI_window_width,UI_window_height);
	
	// llamada para crear la ventana, indicando el titulo (no se visualiza hasta que se llama
	// al bucle de eventos)
	glutCreateWindow("Práctica 1");
	
	// asignación de la funcion llamada "dibujar" al evento de dibujo
	glutDisplayFunc(draw_scene);
	// asignación de la funcion llamada "cambiar_tamanio_ventana" al evento correspondiente
	glutReshapeFunc(change_window_size);
	// asignación de la funcion llamada "tecla_normal" al evento correspondiente
	glutKeyboardFunc(normal_keys);
	// asignación de la funcion llamada "tecla_Especial" al evento correspondiente
	glutSpecialFunc(special_keys);
	
	// funcion de inicialización
	initialize();
	
	// inicio del bucle de eventos
	glutMainLoop();
	return 0;
}



void Circle (GLfloat radio, GLfloat cx, GLfloat cy,  GLfloat cz, GLint n, GLenum modo)
{
	int i;
	if (modo==GL_LINE) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else if (modo==GL_FILL) glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	else glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	glBegin( GL_POLYGON );
	for (i=0;i<n;i++)
		glVertex3f( cx+radio*cos(2.0*M_PI*i/n), cy+radio*sin(2.0*M_PI*i/n),cz);
	glEnd();
}



