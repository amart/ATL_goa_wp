/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: z
 *
 * Created on September 10, 2015, 3:25 PM
 */

#include <cstdlib>

#include "CatchAtAge.hpp"

using namespace std;

/*
 * 
 */
int
main( int argc, char** argv )
{
    CatchAtAge<double> caa;
    
    caa.InitArgs( argc, argv );
    caa.Initialize();
    caa.Run();
    caa.Report();
    
    return 0;
}