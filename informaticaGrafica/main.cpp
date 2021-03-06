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
#include "baseMJ.h"
#include "stickMJ.h"
#include "baseStickMJ.h"
#include "branchMJ.h"
#include "handMJ.h"
#include "branchHandMJ.h"
#include "balanceTrade.h"
#include "luz.h"
#include "material.h"

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
vector<_vertex3f> peonza ={{5,-5,0},{2.5,-2.5,0},{2,0,0},{2.5,2.5,0},{5,5,0}};

float translacion_y = 20.8;
float angle1 = 0;
float angle2 = 0;
bool bajar = true;

GLfloat alfa = 0;
GLfloat beta = 0;

Luz luz0;
Luz luz1;
Material material;

Cubo cubo(4);
Piramide piramide(10, 10);
FiguraPly objeto_ply ("/Users/Ivanovic/Documents/Graphic-Computer/informaticaGrafica/lata-pcue.ply");

FiguraPly tuboRevolucion(tubo);
FiguraPly coneRevolucion(cono);
FiguraPly vasoRevolucion(vaso);
FiguraPly vasoRevolucionI(vasoI);
FiguraPly cilindroRevolucion(cilindro);
FiguraPly peonzaRevolucion(peonza);

/*BaseStickMJ bsmj = BaseStickMJ();
BranchHandMJ branchhandmj = BranchHandMJ();
BalanceTrade balancetrademj = BalanceTrade();*/

// tamaño de los ejes
const int AXIS_SIZE=5000;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Window_width,Window_height,Front_plane,Back_plane;

// variables que determninan la posicion y tamaño de la ventana X
int UI_window_pos_x=50,UI_window_pos_y=50,UI_window_width=1000,UI_window_height=1000;

//**************************************************************************
//Function figure rotation and translation.
//***************************************************************************

void animation(){
    
    if (translacion_y >= 20.8) {
        bajar = true;
    }
    
    if (translacion_y <= 14.8)
        bajar = false;
    
    angle1 += 1;
    angle2 += 1;
    
    glutPostRedisplay();
}

//**************************************************************************
//
//***************************************************************************

void clear_window()
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}


//***************************************************************************
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
                    
                case NORMALFACES:
                    cubo.draw_normal_faces();
                    break;
                    
                case NORMALVERTEX:
                    cubo.draw_normal_vertex();
                    break;
                    
                case FLAT:
                    cubo.dibujar_suavizado_plano();
                    break;
                    
                case SMOOTH:
                    cubo.dibujar_suavizado_gouraud();
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
            
        /*case BRANCHHANDMJ:
            switch (mode) {
                case VERTICES:
                    branchhandmj.drawPointsBH(0, 0);
                    break;
                case ARISTAS:
                    branchhandmj.drawEdgeBH(0, 0);
                    break;
                    
                case SOLID:
                    branchhandmj.drawSolidBH(0, 0);
                    break;
                    
                case CHESS:
                    branchhandmj.drawChessBH(0, 0);
                    break;
            }
            break;
            
        case BASESTICKMJ:
            switch (mode) {
                case VERTICES:
                    bsmj.drawPointsBS();
                    break;
                case ARISTAS:
                    bsmj.drawEdgeBS();
                    break;
                    
                case SOLID:
                    bsmj.drawSolidBS();
                    break;
                    
                case CHESS:
                    bsmj.drawChessBS();
                    break;
            }
            break;
            
        case BALANCETRADE:
            switch (mode) {
                case VERTICES:
                    balancetrademj.drawPointsBT(angle1, angle2, translacion_y);
                    break;
                case ARISTAS:
                    balancetrademj.drawEdgeBT(angle1, angle2, translacion_y);
                    break;
                    
                case SOLID:
                    balancetrademj.drawSolidBT(angle1, angle2, translacion_y);
                    break;
                    
                case CHESS:
                    balancetrademj.drawChessBT(angle1, angle2, translacion_y);
                    break;
            }
            break;*/
            
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
                    
                case REVOLUTION:
                    objeto_ply.revolution(20);
                    break;
                    
                case NORMALFACES:
                    objeto_ply.draw_normal_faces();
                    break;
                    
                case NORMALVERTEX:
                    objeto_ply.draw_normal_vertex();
                    break;
                    
                case FLAT:
                    objeto_ply.dibujar_suavizado_plano();
                    break;
                    
                case SMOOTH:
                    objeto_ply.dibujar_suavizado_gouraud();
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
                            
                        case NORMALFACES:
                            cilindroRevolucion.draw_normal_faces();
                            break;
                            
                        case NORMALVERTEX:
                            cilindroRevolucion.draw_normal_vertex();
                            break;
                            
                        case FLAT:
                            material.activar();
                            cilindroRevolucion.dibujar_suavizado_plano();
                            break;
                            
                        case SMOOTH:
                            material.activar();
                            cilindroRevolucion.dibujar_suavizado_gouraud();
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
                            
                        case NORMALFACES:
                            tuboRevolucion.draw_normal_faces();
                            break;
                            
                        case NORMALVERTEX:
                            tuboRevolucion.draw_normal_vertex();
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
                            
                        case NORMALFACES:
                            coneRevolucion.draw_normal_faces();
                            break;
                            
                        case NORMALVERTEX:
                            coneRevolucion.draw_normal_vertex();
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
                            vasoRevolucion.revolution(70);
                            break;
                            
                        case NORMALFACES:
                            vasoRevolucion.draw_normal_faces();
                            break;
                            
                        case NORMALVERTEX:
                            vasoRevolucion.draw_normal_vertex();
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
                            
                        case NORMALFACES:
                            vasoRevolucionI.draw_normal_faces();
                            break;
                            
                        case NORMALVERTEX:
                            vasoRevolucionI.draw_normal_vertex();
                            break;
                    }
                    break;
                    
                case PEONZA:
                    
                    switch (mode) {
                            
                        case VERTICES:
                            peonzaRevolucion.draw_points();
                            break;
                        case ARISTAS:
                            peonzaRevolucion.draw_edges();
                            break;
                            
                        case SOLID:
                            peonzaRevolucion.draw_solid();
                            break;
                            
                        case CHESS:
                            peonzaRevolucion.draw_chess();
                            break;
                            
                        case REVOLUTION:
                            peonzaRevolucion.revolution(20);
                            break;
                            
                        case REVOLUTION_PARCIAL:
                            peonzaRevolucion.parcialRevolution(20);
                            break;
                    }
                    break;
                    
            }
            break;
	}
}


//**************************************************************************
// Luces
//**************************************************************************

void draw_lights(void)
{
    glDisable(GL_LIGHT0);
    luz0.encenderLuz();
    luz1.encenderLuz();
}


//**************************************************************************
//
//***************************************************************************

void draw_scene(void)
{
	clear_window();
	change_observer();
    draw_lights();
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
            
        case 'H':
            mode = NORMALFACES;
            break;
            
        case 'J':
            mode = NORMALVERTEX;
            break;
			
		case 'S':
			mode = SOLID;
			break;
            
        case 'X':
            mode = FLAT;
            break;
            
        case 'V':
            mode = SMOOTH;
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
            
        case 'T':
            mode = REVOLUTION_PARCIAL;
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
            
        case '6':
            obj_ply = PEONZA;
            break;
            
        /*case 'E':
            luz0.activar();
            luz1.activar();
            break;
            
        case 'D':
            luz0.desactivar();
            luz1.desactivar();
            break;*/
            
            // Cambiar angulos luz direccional, alfa es girar(rotar sobre eje y) y beta es subir/bajar (rotar sobre eje x).
        case 'U':
            beta += 20;
            luz1.setDireccion(alfa, beta);
            break;
            
        case 'I':
            beta -= 20;
            luz1.setDireccion(alfa, beta);
            break;
            
        case 'K':
            alfa += 20;
            luz1.setDireccion(alfa, beta);
            break;
            
        case 'L':
            alfa -= 20;
            luz1.setDireccion(alfa, beta);
            break;
            
        case 'W':
            objeto_ply.cambiarMaterial(_vertex4f(0.24725, 0.1995, 0.0745, 1.0), _vertex4f(0.75164, 0.60648, 0.22648,1.0)
                                       , _vertex4f(0.628281, 0.555802, 0.366065,1.0), 51.2);
            break;
            
        case 'D':
            objeto_ply.cambiarMaterial(_vertex4f(0.0215, 0.1745, 0.0215, 0.55), _vertex4f(0.07568, 0.61424, 0.07568,0.55)
                                       , _vertex4f(0.633, 0.727811, 0.633,0.55), 76.8);
            break;
         /*
        case 'D':
            if (bajar) {
                translacion_y -= 0.1;
            }
            break;
            
        case 'L':
            if (!bajar) {
                translacion_y += 0.1;
            }
            break;*/
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
		//case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
		//case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
            
        case GLUT_KEY_F10:
            Observer_distance*=1.02;
            break;
            
        case GLUT_KEY_F9:
            Observer_distance/=1.02;
            break;
            
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
            
        case GLUT_KEY_F5:
            obj = BASESTICKMJ;
            break;
            
        case GLUT_KEY_F6:
            obj = BRANCHHANDMJ;
            break;
            
        case GLUT_KEY_F7:
            obj = BALANCETRADE;
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
    
    luz0.setID(GL_LIGHT1);
    luz0.setDireccional(false);
    luz0.setPosicion(_vertex3f(15,-10,7));
    luz0.setAmbiental(_vertex4f(0.1,0.1,0.1,1));
    luz0.setDifusa(_vertex4f(0.8,0.8,0.8,1));
    luz0.setEspecular(_vertex4f(0.8,0.8,0.8,1));
    
    luz1.setID(GL_LIGHT2);
    luz1.setDireccional(true);
    luz1.setPosicion(_vertex3f(0,1,1));
    luz1.setDireccion(alfa,beta);
    luz1.setAmbiental(_vertex4f(0.1,0.1,0.1,1.0));
    luz1.setDifusa(_vertex4f(1.0,1.0,1.0,1.0));
    luz1.setEspecular(_vertex4f(1.0,1.0,1.0,1.0));
    
    
    objeto_ply.cambiarMaterial(_vertex4f(0.2,0.4,0.1,1.0), _vertex4f(0.1,0.7,1.0,1.0), _vertex4f(0.2,0.7,0.3,1.0), 5);
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
	glutCreateWindow("GRAPHIC-COMPUTER");
	
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
    
    //glutIdleFunc(animation);
	
	// inicio del bucle de eventos
	glutMainLoop();
	return 0;
}



