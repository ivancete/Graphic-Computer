//
//  triangulos.cpp
//  informaticaGrafica
//
//  Created by Iván Rodríguez Millán on 28/9/17.
//  Copyright © 2017 Iván Rodríguez Millán. All rights reserved.
//

#include "triangulos.h"

Triangulos::Triangulos()
{
	
}

void Triangulos::draw_edges()
{
	glColor3f(255,0,0);
	glPointSize(4);
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	
	int vertice1, vertice2, vertice3;
	
	glBegin(GL_TRIANGLES);
	for (int i=0;i<triangulos.size();i++){
		
		vertice1 = triangulos[i]._0;
		vertice2 = triangulos[i]._1;
		vertice3 = triangulos[i]._2;
		
		glVertex3fv((GLfloat *) &vertices[vertice1]);
		glVertex3fv((GLfloat *) &vertices[vertice2]);
		glVertex3fv((GLfloat *) &vertices[vertice3]);
	}
	glEnd();
	
}

void Triangulos::draw_solid()
{
	glColor3f(1,0,0);
	glPointSize(4);
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	
	int vertice1, vertice2, vertice3;
	
	glBegin(GL_TRIANGLES);
	for (int i=0;i<triangulos.size();i++){
		
		vertice1 = triangulos[i]._0;
		vertice2 = triangulos[i]._1;
		vertice3 = triangulos[i]._2;
		
		glVertex3fv((GLfloat *) &vertices[vertice1]);
		glVertex3fv((GLfloat *) &vertices[vertice2]);
		glVertex3fv((GLfloat *) &vertices[vertice3]);
	}
	glEnd();
	
}

void Triangulos::draw_chess()
{
	glPointSize(4);
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	
	int vertice1, vertice2, vertice3;
	
	glBegin(GL_TRIANGLES);
	for (int i=0;i<triangulos.size();i++){
		
		if(i%2 == 0)
			glColor3f(0,1,0);
		else
			glColor3f(0,0,1);
		
		vertice1 = triangulos[i]._0;
		vertice2 = triangulos[i]._1;
		vertice3 = triangulos[i]._2;
		
		glVertex3fv((GLfloat *) &vertices[vertice1]);
		glVertex3fv((GLfloat *) &vertices[vertice2]);
		glVertex3fv((GLfloat *) &vertices[vertice3]);
	}
	glEnd();
	
}

void Triangulos::Circle (GLfloat radio, GLfloat cx, GLfloat cy,  GLfloat cz, GLint n, GLenum modo)
{
	int i;
	if (modo == GL_LINE) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else if (modo == GL_FILL) glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	else glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	glBegin( GL_POLYGON );
	for (i=0;i<n;i++)
		glVertex3f( cx+radio*cos(2.0*M_PI*i/n), cy+radio*sin(2.0*M_PI*i/n),cz);
	glEnd();
}

void Triangulos::draw_circulos(float radio, int n, GLenum mo)
{
	draw_edges();
	for (int i = 0; i<vertices.size(); i++) {
		glColor3f(colores[i].r,colores[i].g,colores[i].b);
		Circle (radio, vertices[i].x, vertices[i].y, vertices[i].z, n, mo);
	}
}
