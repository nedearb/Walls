//
//  Settings.hpp
//  Walls
//
//  Created by Emily Atlee on 8/15/16.
//  Copyright © 2016 Emily Atlee. All rights reserved.
//

#ifndef Settings_hpp
#define Settings_hpp

#include "Headers.hpp"
#include "Geometry.hpp"

struct Settings{
    
    string filename;
    
    Point2 windowSize = Point2(640, 480);
    double lookSpeed = 0.01;
    double fov = 90;

    int shadowResolution = 1024;
    
    void init();
    bool load();
    bool save();
    
};


#endif /* Settings_hpp */
