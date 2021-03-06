//
//  Mesh.hpp
//  Walls
//
//  Created by Emily Atlee on 8/15/16.
//  Copyright © 2016 Emily Atlee. All rights reserved.
//

#ifndef Mesh_hpp
#define Mesh_hpp

#include "Headers.hpp"
#include "Vertex.hpp"


enum CompileStatus{
    noRender,
    needsMake,
    making,
    needsCompile,
    canRender,
    needsReset,
    needsRemoval
};

struct Mesh{
    
    CompileStatus status = noRender;
    
    vector<Vertex> vertices;
    vector<unsigned int> indices;
    
    GLsizei elementCount;
    
    GLuint vbo;
    GLuint ibo;
    
    thread makeThread;
    
    vec3 radii = vec3(0, 0, 0);
    
    Mesh();
    virtual ~Mesh(){}
    
    void draw(bool drawShadows);
    virtual void make(){}
    void calculateRadii();
    void compile();
    void render();
    void renderShadows();
    void cleanup();
    
};

void makeMesh(Mesh* mesh);

#endif /* Mesh_hpp */
