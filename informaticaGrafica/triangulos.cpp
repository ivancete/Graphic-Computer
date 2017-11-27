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

void Triangulos::normal_faces()
{
    normalFaces.resize(triangulos.size());
    dibujar_normales_triangulo.resize(triangulos.size());
    
    _vertex3f B, A;
    
    for (int i = 0; i < triangulos.size(); i++) {
        
        //En primer lugar calculamos el vector -A> = V1 - V0.
        A.x = vertices[triangulos[i]._1].x - vertices[triangulos[i]._0].x;
        A.y = vertices[triangulos[i]._1].y - vertices[triangulos[i]._0].y;
        A.z = vertices[triangulos[i]._1].z - vertices[triangulos[i]._0].z;
        
        //En segundo lugar calculamos el vector -B> = V2 - V0.
        B.x = vertices[triangulos[i]._2].x - vertices[triangulos[i]._0].x;
        B.y = vertices[triangulos[i]._2].y - vertices[triangulos[i]._0].y;
        B.z = vertices[triangulos[i]._2].z - vertices[triangulos[i]._0].z;
        
        //En tercer lugar calculamos la normal a esos dos vectores calculados previamente.
        /*
         Nx = Ay * Bz - Az * By
         Ny = Az * Bx - Ax * Bz
         Nz = Ax * By - Ay * Bx
         */
        normalFaces[i].x = A.y * B.z - A.z * B.y;
        normalFaces[i].y = A.z * B.x - A.x * B.z;
        normalFaces[i].z = A.x * B.y - A.y * B.x;
        
        /*if (normalFaces[i].x < 0) {
            normalFaces[i].x *= (-1);
        }
        else if(normalFaces[i].y < 0){
            normalFaces[i].y *= (-1);
        }
        else if(normalFaces[i].z < 0){
            normalFaces[i].z *= (-1);
        }*/
        
        normalFaces[i].normalize();
        
        dibujar_normales_triangulo[i].first.x = (vertices[triangulos[i]._0].x + vertices[triangulos[i]._1].x + vertices[triangulos[i]._2].x)/3;
        dibujar_normales_triangulo[i].first.y = (vertices[triangulos[i]._0].y + vertices[triangulos[i]._1].y + vertices[triangulos[i]._2].y)/3;
        dibujar_normales_triangulo[i].first.z = (vertices[triangulos[i]._0].z + vertices[triangulos[i]._1].z + vertices[triangulos[i]._2].z)/3;
        
        dibujar_normales_triangulo[i].second.x = dibujar_normales_triangulo[i].first.x + 2 * normalFaces[i].x;
        dibujar_normales_triangulo[i].second.y = dibujar_normales_triangulo[i].first.y + 2 * normalFaces[i].y;
        dibujar_normales_triangulo[i].second.z = dibujar_normales_triangulo[i].first.z + 2 * normalFaces[i].z;
    }
}

void Triangulos::normal_vertex()
{
    normalVertex.resize(vertices.size());
    dibujar_normales_vertices.resize(vertices.size());
    
    _vertex3f B, A;
    int contador;
    float x = 0, y = 0, z = 0;
    
    for (int i = 0; i < vertices.size(); i++) {
        
        contador = 0;
        x = 0;
        y = 0;
        z = 0;
        for (int j = 0; j < triangulos.size(); j++) {
            
            if (triangulos[j]._0 == i || triangulos[j]._1 == i || triangulos[j]._2 == i) {
                x += normalFaces[j].x;
                y += normalFaces[j].y;
                z += normalFaces[j].z;
                contador++;
            }
        }
        
        //Almacenamos el vector normal del vertice j-esimo.
        normalVertex[i].x = x / contador;
        
        normalVertex[i].y = y / contador;
        
        normalVertex[i].z = z / contador;
        
        /*if (normalVertex[i].x < 0) {
            normalVertex[i].x *= (-1);
        }
        else if(normalVertex[i].y < 0){
            normalVertex[i].y *= (-1);
        }
        else if(normalVertex[i].z < 0){
            normalVertex[i].z *= (-1);
        }*/
        
        //Normalizamos el vector normal de los vertices.
        normalVertex[i].normalize();
        
        dibujar_normales_vertices[i].first.x = vertices[i].x;
        dibujar_normales_vertices[i].first.y = vertices[i].y;
        dibujar_normales_vertices[i].first.z = vertices[i].z;
        
        dibujar_normales_vertices[i].second.x = dibujar_normales_vertices[i].first.x + 2 * normalVertex[i].x;
        dibujar_normales_vertices[i].second.y = dibujar_normales_vertices[i].first.y + 2 * normalVertex[i].y;
        dibujar_normales_vertices[i].second.z = dibujar_normales_vertices[i].first.z + 2 * normalVertex[i].z;
    }
}

void Triangulos::draw_normal_faces()
{
    glColor3f(0,1,0);
    
    glBegin(GL_LINES);
    for (int i=0;i<dibujar_normales_triangulo.size();i++){
        glVertex3f(dibujar_normales_triangulo[i].first.x,
                   dibujar_normales_triangulo[i].first.y,
                   dibujar_normales_triangulo[i].first.z);
        
        glVertex3f(dibujar_normales_triangulo[i].second.x,
                   dibujar_normales_triangulo[i].second.y,
                   dibujar_normales_triangulo[i].second.z);
    }
    glEnd();
    
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

void Triangulos::draw_normal_vertex()
{
    glColor3f(0,1,0);
    
    glBegin(GL_LINES);
    for (int i=0;i<dibujar_normales_vertices.size();i++){
        glVertex3f(dibujar_normales_vertices[i].first.x,
                   dibujar_normales_vertices[i].first.y,
                   dibujar_normales_vertices[i].first.z);
        
        glVertex3f(dibujar_normales_vertices[i].second.x,
                   dibujar_normales_vertices[i].second.y,
                   dibujar_normales_vertices[i].second.z);
    }
    glEnd();
    
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

void Triangulos::dibujar_suavizado_plano() {
    material.activar();
    //glColor3f(0.5, 0.7, 0.3);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glShadeModel(GL_FLAT);
    
    glBegin(GL_TRIANGLES);
    for(unsigned int i=0;i< triangulos.size();i++){
        
        glNormal3f(normalFaces[i].x, normalFaces[i].y, normalFaces[i].z);
        
        glVertex3f(vertices[triangulos[i]._0].x, vertices[triangulos[i]._0].y, vertices[triangulos[i]._0].z);
        
        glVertex3f(vertices[triangulos[i]._1].x, vertices[triangulos[i]._1].y, vertices[triangulos[i]._1].z);
        
        glVertex3f(vertices[triangulos[i]._2].x, vertices[triangulos[i]._2].y, vertices[triangulos[i]._2].z);
    }
    glEnd();
}

void Triangulos::dibujar_suavizado_gouraud() {
    material.activar();
    //glColor3f(0.5, 0.7, 0.3);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glShadeModel(GL_SMOOTH);
    
    glBegin(GL_TRIANGLES);
    for(unsigned int i=0;i< triangulos.size();i++){

        glNormal3f(normalVertex[triangulos[i]._0].x, normalVertex[triangulos[i]._0].y, normalVertex[triangulos[i]._0].z);
        glVertex3f(vertices[triangulos[i]._0].x, vertices[triangulos[i]._0].y, vertices[triangulos[i]._0].z);

        glNormal3f(normalVertex[triangulos[i]._1].x, normalVertex[triangulos[i]._1].y, normalVertex[triangulos[i]._1].z);
        glVertex3f(vertices[triangulos[i]._1].x, vertices[triangulos[i]._1].y, vertices[triangulos[i]._1].z);

        glNormal3f(normalVertex[triangulos[i]._2].x, normalVertex[triangulos[i]._2].y, normalVertex[triangulos[i]._2].z);
        glVertex3f(vertices[triangulos[i]._2].x, vertices[triangulos[i]._2].y, vertices[triangulos[i]._2].z);
    }
    glEnd();
}

void Triangulos::cambiarMaterial(_vertex4f ambiental, _vertex4f difusa, _vertex4f especular, GLfloat brillo)
{
    material.setAmbiental(ambiental);
    material.setDifusa(difusa);
    material.setEspecular(especular);
    material.setBrillo(brillo);
    material.activar();
}
