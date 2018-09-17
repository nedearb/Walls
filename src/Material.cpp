//
//  Material.cpp
//  Walls
//
//  Created by Braeden Atlee on 5/20/17.
//  Copyright © 2017 Braeden Atlee. All rights reserved.
//

#include "Material.hpp"


Material::Material(string filename, vec3 ambient, vec3 diffuse, vec3 specular, float shininess) : name(filename), diffuse(diffuse), ambient(ambient), specular(specular), shininess(shininess){
    
    
}
namespace Materials{
    
    Material* defaultMaterial;
    
    void initMaterials(){
        defaultMaterial = new Material("default", vec3(.1, .1, .1), vec3(1, 1, 1), vec3(1, 1, 1), 1);
    }
}