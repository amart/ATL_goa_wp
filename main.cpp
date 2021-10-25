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
    typedef double REAL;

    CatchAtAge<REAL> caa_obj_func;

    caa_obj_func.Initialize();

    // atl::LBFGS<REAL> func_min;

    //create an instance of a L-BFGS minimizer
    atl::PortMinimizer<REAL> fm;
    // atl::LBFGS<REAL> fm;

    // set options
    fm.SetTolerance(static_cast<REAL>(1e-5));

    fm.max_iterations    = 5000;
    fm.max_line_searches = 50;
    fm.print_interval    = 10;

    fm.SetPrintWidth(3);

    //set the objective function
    fm.SetObjectiveFunction(&caa_obj_func);

    //run the minimizer
    fm.Run();


    // caa_obj_func.Finalize();
    caa_obj_func.Report();


    std::cout << std::endl << "Optimization completed" << std::endl << std::endl;


    caa_obj_func.OutputOptimInfo();


    caa_obj_func.OutputVarCovar();


    std::cout << std::endl << "Done" << std::endl << std::endl;


    return 0;
}
