//
//  material.cpp
//  informaticaGrafica
//
//  Created by Iván Rodríguez Millán on 25/11/17.
//  Copyright © 2017 Iván Rodríguez Millán. All rights reserved.
//

#include "material.h"

Material::Material(){
    tieneTextura = false;
}

void Material::setAmbiental(const _vertex4f &a) {
    ambiental = a;
}

void Material::setDifusa(const _vertex4f &d) {
    difusa = d;
}

void Material::setEspecular(const _vertex4f &e) {
    especular = e;
}

void Material::setBrillo(const GLfloat &b) {
    brillo = b;
}

void Material::activar() {
    
    
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    glMaterialfv(GL_FRONT,GL_AMBIENT,(GLfloat *) &ambiental);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,(GLfloat *) &difusa);
    glMaterialfv(GL_FRONT,GL_SPECULAR,(GLfloat *) &especular);
    glMaterialf(GL_FRONT,GL_SHININESS,brillo);
    
    glPopMatrix();
}
