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
        std::cout << "File read correctly" << std::endl;
    }
    
    else std::cout << "File can't be opened" << std::endl;
    
}

FiguraPly::FiguraPly(vector<_vertex3f> v)
{
    vertices = v;
    
    cout << "Número de vértices: " << vertices.size() << endl;
}

void FiguraPly::revolution(int n)
{
    float x, z;
    
    bool tapaArriba = false, tapaAbajo = false;
    
    int final;
    
    if(vertices[vertices.size() - 1].x == 0 && vertices[vertices.size() - 2].x == 0)
    {
        tapaArriba = true;
        tapaAbajo = true;
        final = vertices.size() - 2;
        
        vertices.resize(n*(vertices.size() - 2) + 2);
        
        //Reubicamos las tapas
        vertices[vertices.size() - 1] = vertices[final + 1];
        vertices[vertices.size() - 2] = vertices[final];
    }
    else if(vertices[vertices.size() - 1].x == 0 && vertices[vertices.size() - 2].x != 0)
    {
        if(vertices[vertices.size()-1].y > 0){
            tapaArriba = true;
        }
        else
            tapaAbajo = true;
        
        final = vertices.size() - 1;
        
        vertices.resize(n*(vertices.size() - 1) + 1);
        
        //Reubicamos la tapa
        vertices[vertices.size() - 1] = vertices[final];
    }
    else
    {
        final = vertices.size();
        
        vertices.resize(n*vertices.size());
    }
    
    int k = final;
    
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < final; j++)
        {
            x = vertices[j].x * cos((i*2*M_PI)/n);
            z = vertices[j].x * sin((i*2*M_PI)/n);
            
            vertices[k] = (_vertex3f(x,vertices[j].y,z));
            
            k++;
            
        }
    }
    
    //Triangulos del Cuerpo
    for(int i = 0; i < final - 1; i++)
    {
        for(int j = i; j < (n*final); j += final)
        {
            triangulos.push_back((_vertex3i(j+1, j , (j+final)%(final*n))));
             
            triangulos.push_back((_vertex3i(j+1, (j+final)%(final*n) , ((j+final+1)%(final*n)))));
             
        }
        
    }
    
    if(tapaArriba && tapaAbajo)
    {
        for(int i = final-1; i < n*final; i+=final)
        {
            triangulos.push_back(_vertex3i(vertices.size()-1, i, (i+final)%(final*n)));
        }
        
        for(int i = 0; i < n*final; i+=final)
        {
            triangulos.push_back(_vertex3i(i,(i+final)%(final*n), vertices.size()-2));
        }
        
    }
    
    else if(tapaArriba)
    {
        for(int i = final-1; i < n*final; i+=final)
        {
            triangulos.push_back(_vertex3i(vertices.size()-1, i, (i+final)%(final*n)));
        }
    }
    
    else if(tapaAbajo)
    {
        for(int i = 0; i < n*final; i+=final)
        {
            triangulos.push_back(_vertex3i(i,(i+final)%(final*n), vertices.size()-1));
        }
    }
}

void FiguraPly::parcialRevolution(int n)
{
    float x, z;
    
    bool tapaArriba = false, tapaAbajo = false;
    
    int final;
    
    if(vertices[vertices.size() - 1].x == 0 && vertices[vertices.size() - 2].x == 0)
    {
        tapaArriba = true;
        tapaAbajo = true;
        final = vertices.size() - 2;
        
        vertices.resize(n*(vertices.size() - 2) + 2);
        
        //Reubicamos las tapas
        vertices[vertices.size() - 1] = vertices[final + 1];
        vertices[vertices.size() - 2] = vertices[final];
    }
    else if(vertices[vertices.size() - 1].x == 0 && vertices[vertices.size() - 2].x != 0)
    {
        if(vertices[vertices.size()-1].y > 0){
            tapaArriba = true;
        }
        else
            tapaAbajo = true;
        
        final = vertices.size() - 1;
        
        vertices.resize(n*(vertices.size() - 1) + 1);
        
        //Reubicamos la tapa
        vertices[vertices.size() - 1] = vertices[final];
    }
    else
    {
        final = vertices.size();
        
        vertices.resize(n*vertices.size());
    }
    
    int k = final;
    
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < final; j++)
        {
            x = vertices[j].x * cos((i*2*M_PI)/n);
            z = vertices[j].x * sin((i*2*M_PI)/n);
            
            vertices[k] = (_vertex3f(x,vertices[j].y,z));
            
            k++;
            
        }
    }
    
    int aux = 0;
    
    //Triangulos del Cuerpo
    for(int i = 0; i < final - 1; i++)
    {
        for(int j = i; j < (n*final); j += final)
        {
            
            if (j%2 == aux && vertices[j].y >= 0 && vertices[j+1].y >= 0 && vertices[(j+final)%(final*n)].y >= 0
                && vertices[(j+final)%(final*n)].y >= 0 && vertices[((j+final+1)%(final*n))].y >= 0) {
                
                triangulos.push_back((_vertex3i(j+1, j , (j+final)%(final*n))));
                
                triangulos.push_back((_vertex3i(j+1, (j+final)%(final*n) , ((j+final+1)%(final*n)))));
            }
            
            else if (j%2 != aux  && vertices[j].y <= 0 && vertices[j+1].y <= 0 && vertices[(j+final)%(final*n)].y <= 0
                     && vertices[(j+final)%(final*n)].y <= 0 && vertices[((j+final+1)%(final*n))].y <= 0) {
                
                triangulos.push_back((_vertex3i(j+1, j , (j+final)%(final*n))));
                
                triangulos.push_back((_vertex3i(j+1, (j+final)%(final*n) , ((j+final+1)%(final*n)))));
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
        for(int i = final-1; i < n*final; i+=final)
        {
            triangulos.push_back(_vertex3i(vertices.size()-1, i, (i+final)%(final*n)));
        }
        
        for(int i = 0; i < n*final; i+=final)
        {
            triangulos.push_back(_vertex3i(i,(i+final)%(final*n), vertices.size()-2));
        }
        
    }
    
    else if(tapaArriba)
    {
        for(int i = final-1; i < n*final; i+=final)
        {
            triangulos.push_back(_vertex3i(vertices.size()-1, i, (i+final)%(final*n)));
        }
    }
    
    else if(tapaAbajo)
    {
        for(int i = 0; i < n*final; i+=final)
        {
            triangulos.push_back(_vertex3i(i,(i+final)%(final*n), vertices.size()-1));
        }
    }
}

