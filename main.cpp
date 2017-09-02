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

    // atl::LBFGS<double> func_min;

    //create an instance of a L-BFGS minimizer
    atl::PortMinimizer<double> fm;

    //set the objective function
    fm.SetObjectiveFunction(&caa_obj_func);

    //run the minimizer
    fm.Run();


    // caa_obj_func.Finalize();
    caa_obj_func.Report();


    std::cout << std::endl << "Optimization completed. Calculating variance-covariance matrix" << std::endl << std::endl;


    caa_obj_func.OutputVarCovar();


    std::cout << std::endl << "Done" << std::endl << std::endl;


    return 0;
}
