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

// using namespace std;

/*
 * 
 */
int
main( int argc, char** argv )
{
    CatchAtAge<double> caa_obj_func;
    
    caa_obj_func.Initialize();

    atl::LBFGS<double> func_min;

    func_min.SetObjectiveFunction(&caa_obj_func);
    func_min.Run();

    caa_obj_func.Report();
    caa_obj_func.GetVarCovar();
    
    return 0;
}
