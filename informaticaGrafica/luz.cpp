//
//  luz.cpp
//  informaticaGrafica
//
//  Created by Iván Rodríguez Millán on 25/11/17.
//  Copyright © 2017 Iván Rodríguez Millán. All rights reserved.
//

#include "luz.h"

Luz::Luz()
{
    
}
void Luz::activar() {
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
    
    glEnable(GL_LIGHTING);
    glEnable(id);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    if(direccional) {
        glRotatef(alfa,0,1,0);
        glRotatef(beta,1,0,0);
    }
    glLightfv(GL_LIGHT1,GL_POSITION,(GLfloat *) &posicion);
    glLightfv(GL_LIGHT1,GL_AMBIENT,(GLfloat *) &ambiental);
    glLightfv(GL_LIGHT1,GL_SPECULAR,(GLfloat *) &especular);
    glLightfv(GL_LIGHT1,GL_DIFFUSE,(GLfloat *) &difuso);
    glPopMatrix();
    glDisable(GL_LIGHTING);
}

void Luz::desactivar() {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glDisable(GL_LIGHTING);
    glDisable(id);
    glPopMatrix();
}

void Luz::setID(const GLenum &i) {
    id = i;
}

//Sirve para poner la luz como direccional o ambiental.
void Luz::setDireccional(const bool &d) {
    if(d) {
        direccional = true;
        posicion[3] = 0;
    } else {
        direccional = false;
        posicion[3] = 1;
    }
}

//Sirve para especificar la posición de la luz en modo direccional.
void Luz::setPosicion(const _vertex3f &p) {
    posicion._0 = p._0;
    posicion._1 = p._1;
    posicion._2 = p._2;
}

//Sirve para especificar la direccion de la luz en modo direccional.
void Luz::setDireccion(const GLfloat &a, const GLfloat &b) {
    alfa = a;
    beta = b;
}

//Valores de la componente Ambiental.
void Luz::setAmbiental(const _vertex4f &a) {
    ambiental = a;
}

//Valores de la componente Difusa.
void Luz::setDifusa(const _vertex4f &d) {
    difuso = d;
}

//Valores de la componente Especular.
void Luz::setEspecular(const _vertex4f &e) {
    especular = e;
}
