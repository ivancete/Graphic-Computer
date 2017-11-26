//
//  figura_ply.cpp
//  informaticaGrafica
//
//  Created by Iván Rodríguez Millán on 9/10/17.
//  Copyright © 2017 Iván Rodríguez Millán. All rights reserved.
//

#include "figura_ply.h"

FiguraPly::FiguraPly()
{
    
}

FiguraPly::FiguraPly(string ubicacion)
{
    
    if (File_ply.open(ubicacion)){
        File_ply.read(vertices,triangulos);
        this->normal_faces();
        this->normal_vertex();
        
        material.setAmbiental(_vertex4f(0.2,0.4,0.1,1.0));
        material.setDifusa(_vertex4f(0.1,0.7,1.0,1.0));
        material.setEspecular(_vertex4f(0.2,0.7,0.3,1.0));
        material.setBrillo(5);
        
        std::cout << "File read correctly" << std::endl;
    }
    
    else std::cout << "File can't be opened" << std::endl;
    
}

FiguraPly::FiguraPly(vector<_vertex3f> v)
{
    vertices = v;
}

void FiguraPly::revolution(int n)
{
    float x, z;
    
    bool tapaArriba = false, tapaAbajo = false;
    
    int fin;
    
    if(vertices[vertices.size() - 1].x == 0 && vertices[vertices.size() - 2].x == 0)
    {
        tapaArriba = true;
        tapaAbajo = true;
        fin = vertices.size() - 2;
        
        vertices.resize(n*(vertices.size() - 2) + 2);
        
        //Reubicamos las tapas
        vertices[vertices.size() - 1] = vertices[fin + 1];
        vertices[vertices.size() - 2] = vertices[fin];
    }
    else if(vertices[vertices.size() - 1].x == 0 && vertices[vertices.size() - 2].x != 0)
    {
        if(vertices[vertices.size()-1].y > 0){
            tapaArriba = true;
        }
        else
            tapaAbajo = true;
        
        fin = vertices.size() - 1;
        
        vertices.resize(n*(vertices.size() - 1) + 1);
        
        //Reubicamos la tapa
        vertices[vertices.size() - 1] = vertices[fin];
    }
    else
    {
        fin = vertices.size();
        
        vertices.resize(n*vertices.size());
    }
    
    int k = fin;
    
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < fin; j++)
        {
            x = vertices[j].x * cos((i*2*M_PI)/n);
            z = vertices[j].x * sin((i*2*M_PI)/n);
            
            vertices[k] = (_vertex3f(x,vertices[j].y,z));
            
            k++;
            
        }
    }
    
    //Triangulos del Cuerpo
    for(int i = 0; i < fin - 1; i++)
    {
        for(int j = i; j < (n*fin); j += fin)
        {
            
            triangulos.push_back((_vertex3i(j+1, j , (j+fin)%(fin*n))));
            
            triangulos.push_back((_vertex3i(j+1, (j+fin)%(fin*n) , ((j+fin+1)%(fin*n)))));
        }
    }
    
    if(tapaArriba && tapaAbajo)
    {
        for(int i = fin-1; i < n*fin; i+=fin)
        {
            triangulos.push_back(_vertex3i(vertices.size()-1, i, (i+fin)%(fin*n)));
        }
        
        for(int i = 0; i < n*fin; i+=fin)
        {
            triangulos.push_back(_vertex3i(i,(i+fin)%(fin*n), vertices.size()-2));
        }
        
    }
    
    else if(tapaArriba)
    {
        for(int i = fin-1; i < n*fin; i+=fin)
        {
            triangulos.push_back(_vertex3i(vertices.size()-1, i, (i+fin)%(fin*n)));
        }
    }
    
    else if(tapaAbajo)
    {
        for(int i = 0; i < n*fin; i+=fin)
        {
            triangulos.push_back(_vertex3i(i,(i+fin)%(fin*n), vertices.size()-1));
        }
    }
    
    normal_faces();
    normal_vertex();
}

void FiguraPly::parcialRevolution(int n)
{
    float x, z;
    
    bool tapaArriba = false, tapaAbajo = false;
    
    int fin;
    
    if(vertices[vertices.size() - 1].x == 0 && vertices[vertices.size() - 2].x == 0)
    {
        tapaArriba = true;
        tapaAbajo = true;
        fin = vertices.size() - 2;
        
        vertices.resize(n*(vertices.size() - 2) + 2);
        
        //Reubicamos las tapas
        vertices[vertices.size() - 1] = vertices[fin + 1];
        vertices[vertices.size() - 2] = vertices[fin];
    }
    else if(vertices[vertices.size() - 1].x == 0 && vertices[vertices.size() - 2].x != 0)
    {
        if(vertices[vertices.size()-1].y > 0){
            tapaArriba = true;
        }
        else
            tapaAbajo = true;
        
        fin = vertices.size() - 1;
        
        vertices.resize(n*(vertices.size() - 1) + 1);
        
        //Reubicamos la tapa
        vertices[vertices.size() - 1] = vertices[fin];
    }
    else
    {
        fin = vertices.size();
        
        vertices.resize(n*vertices.size());
    }
    
    int k = fin;
    
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < fin; j++)
        {
            x = vertices[j].x * cos((i*2*M_PI)/n);
            z = vertices[j].x * sin((i*2*M_PI)/n);
            
            vertices[k] = (_vertex3f(x,vertices[j].y,z));
            
            k++;
            
        }
    }
    
    int aux = 0;
    
    //Triangulos del Cuerpo
    for(int i = 0; i < fin - 1; i++)
    {
        for(int j = i; j < (n*fin); j += fin)
        {
            
            if (j%2 == aux && vertices[j].y >= 0 && vertices[j+1].y >= 0 && vertices[(j+fin)%(fin*n)].y >= 0
                && vertices[(j+fin)%(fin*n)].y >= 0 && vertices[((j+fin+1)%(fin*n))].y >= 0) {
                
                triangulos.push_back((_vertex3i(j+1, j , (j+fin)%(fin*n))));
                
                triangulos.push_back((_vertex3i(j+1, (j+fin)%(fin*n) , ((j+fin+1)%(fin*n)))));
            }
            
            else if (j%2 != aux  && vertices[j].y <= 0 && vertices[j+1].y <= 0 && vertices[(j+fin)%(fin*n)].y <= 0
                     && vertices[(j+fin)%(fin*n)].y <= 0 && vertices[((j+fin+1)%(fin*n))].y <= 0) {
                
                triangulos.push_back((_vertex3i(j+1, j , (j+fin)%(fin*n))));
                
                triangulos.push_back((_vertex3i(j+1, (j+fin)%(fin*n) , ((j+fin+1)%(fin*n)))));
            }
        }
        
        if (aux == 0) {
            aux = 1;
        }
        else
            aux = 0;
        
    }
    
    if(tapaArriba && tapaAbajo)
    {
        for(int i = fin-1; i < n*fin; i+=fin)
        {
            triangulos.push_back(_vertex3i(vertices.size()-1, i, (i+fin)%(fin*n)));
        }
        
        for(int i = 0; i < n*fin; i+=fin)
        {
            triangulos.push_back(_vertex3i(i,(i+fin)%(fin*n), vertices.size()-2));
        }
        
    }
    
    else if(tapaArriba)
    {
        for(int i = fin-1; i < n*fin; i+=fin)
        {
            triangulos.push_back(_vertex3i(vertices.size()-1, i, (i+fin)%(fin*n)));
        }
    }
    
    else if(tapaAbajo)
    {
        for(int i = 0; i < n*fin; i+=fin)
        {
            triangulos.push_back(_vertex3i(i,(i+fin)%(fin*n), vertices.size()-1));
        }
    }
}

