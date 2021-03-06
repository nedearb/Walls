//
//  Mesh.cpp
//  Walls
//
//  Created by Emily Atlee on 8/15/16.
//  Copyright © 2016 Emily Atlee. All rights reserved.
//

#include "Mesh.hpp"


void makeMesh(Mesh* mesh){
    mesh->make();
    mesh->calculateRadii();
    mesh->status = needsCompile;
}

Mesh::Mesh(){
    
}

void Mesh::calculateRadii(){
    for(Vertex vert : vertices){
        if(abs(vert.Position.x) > radii.x){
            radii.x = abs(vert.Position.x);
        }
        if(abs(vert.Position.y) > radii.y){
            radii.y = abs(vert.Position.y);
        }
        if(abs(vert.Position.z) > radii.z){
            radii.z = abs(vert.Position.z);
        }
    }
}


void Mesh::draw(bool drawShadows){
    switch (status) {
        case noRender:
            break;
        case needsMake:
            status = making;
            makeThread = thread(makeMesh, this);
            break;
        case making:
            break;
        case needsCompile:
            makeThread.join();
            compile();
            status = canRender;
            break;
        case canRender:
            if(drawShadows){
                renderShadows();
            } else {
                render();
            }
            break;
        case needsReset:
            cleanup();
            status = needsMake;
            break;
        case needsRemoval:
            cleanup();
            status = noRender;
            break;
    }
}

void Mesh::compile(){
    
    elementCount = (GLsizei)indices.size();
    
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, Vertex::strideToEnd * vertices.size(), &vertices[0], GL_STATIC_DRAW);
    
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * elementCount, &indices[0], GL_STATIC_DRAW);
    
    //vertices.clear();
    //indices.clear();
    
    //To Fix glEnableVertexAttribArray() returning error:
    GLuint vaoId = 0;
    glGenVertexArrays(1, &vaoId);
    glBindVertexArray(vaoId);
    //
}


void Mesh::render(){
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    CHECK_ERROR
    
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glEnableVertexAttribArray(3);
    CHECK_ERROR
    
    glVertexAttribPointer(0, 3, GL_FLOAT, false, Vertex::strideToEnd, (void *)Vertex::strideToPosition);
    glVertexAttribPointer(1, 4, GL_FLOAT, false, Vertex::strideToEnd, (void *)Vertex::strideToColor);
    glVertexAttribPointer(2, 3, GL_FLOAT, false, Vertex::strideToEnd, (void *)Vertex::strideToNormal);
    glVertexAttribPointer(3, 2, GL_FLOAT, false, Vertex::strideToEnd, (void *)Vertex::strideToUV);
    CHECK_ERROR
    
    glDrawElements(GL_TRIANGLES, elementCount, GL_UNSIGNED_INT, 0);
    CHECK_ERROR
}

void Mesh::renderShadows(){
    CHECK_ERROR
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    CHECK_ERROR
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    CHECK_ERROR
    
    glEnableVertexAttribArray(0);
    CHECK_ERROR
    
    glVertexAttribPointer(0, 3, GL_FLOAT, false, Vertex::strideToEnd, (void *)Vertex::strideToPosition);
    CHECK_ERROR
    
    glDrawElements(GL_TRIANGLES, elementCount, GL_UNSIGNED_INT, 0);
    CHECK_ERROR
}

void Mesh::cleanup(){
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ibo);
}

