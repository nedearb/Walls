//
//  Shader.hpp
//  Walls
//
//  Created by Emily Atlee on 8/15/16.
//  Copyright © 2016 Emily Atlee. All rights reserved.
//

#ifndef Shader_hpp
#define Shader_hpp

#include "Headers.hpp"


struct Shader{
    
    string filename;
    string code;
    string log;
    
    GLuint pointer;
    GLenum type;
    
    Shader(string filename, GLenum type) : filename(filename), type(type){}
    
    bool loadFile();
    bool compile();
    
    
};

struct ShaderProgram{
    
    GLuint pointer;
    
    void addShader(Shader shader);
    bool link();
    void use();
    
    map<string, int> uniformLocations;
    
    int getUniformLocation(string s);
    
private:
    vector<GLuint> shaders;
    
};

#endif /* Shader_hpp */
