/*
 * File:   CatchAtAge.hpp
 * Author: z
 *
 * Created on September 10, 2015, 3:26 PM
 *
 * based on the GOA walleye pollock model from 2013
 *
 */

#ifndef CATCHATAGE_HPP
#    define CATCHATAGE_HPP

#include "../../ATL/ATL.hpp"

template<class T>
class CatchAtAge : public atl::FunctionMinimizer<T>
{
    int nages = 10;
    atl::Vector<T> ages = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // starts in 1964
    int nyrs = 50;
    atl::Vector<T> obs_catch = { 1126, 2749, 8932, 6276, 6164, 17553, 9343, 9458, 34081, 36836, 61880, 59512, 86527, 118356, 96935, 105748, 114622, 147744, 168740, 215608, 307401, 284826, 87809, 69751, 65739, 78392, 90744, 100488, 90857, 108908, 107335, 72618, 51263, 90130, 125098, 95590, 73080, 72076, 51937, 50666, 63934, 80846, 71976, 53062, 52500, 44003, 76860, 81307, 103991, 113099 };
    atl::Vector<T> obs_fsh_N = { 0, 0, 0, 0, 0, 0, 0, 0, 20, 20, 20, 20, 60, 60, 200, 200, 200, 200, 200, 200, 200, 200, 84, 40, 18, 171, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200 };
    atl::Matrix<T> obs_fsh_prop_at_age = {
        // 1    2    3    4    5    6    7   8   9   10
        // 1964
        { 0, 0.13917, 0.10736, 0.42823, 0.29583, 0.00358, 0.00557, 0.01193, 0.00477, 0.00358 },
        // 1965
        { 0, 0.11082, 0.36791, 0.3227, 0.16312, 0.03546, 0, 0, 0, 0 },
        // 1966
        { 0, 0.03551, 0.11083, 0.28133, 0.31745, 0.05116, 0.11469, 0.0273, 0.04427, 0.01745 },
        // 1967
        { 0, 0.0001, 0.04079, 0.3881, 0.13209, 0.05636, 0.11798, 0.08352, 0.07632, 0.10474 },
        // 1968
        { 0, 0.00353, 0, 0.45541, 0.3267, 0.03491, 0.0549, 0.04016, 0.03374, 0.05065 },
        // 1969
        { 0, 0.02005, 0.02254, 0.28232, 0.59182, 0.01602, 0.02269, 0.01341, 0.02299, 0.00816 },
        // 1970
        { 0, 0.02389, 0.27124, 0.58161, 0.04843, 0.06405, 0.00177, 0.004, 0.00437, 0.00065 },
        // 1971
        { 0, 0.29665, 0.46724, 0.12528, 0.11082, 0, 0, 0, 0, 0 },
        // 1972
        { 0, 0.0042, 0.02553, 0.08652, 0.26337, 0.21787, 0.35184, 0.05064, 0.00004, 0 },
        // 1973 (copied from 1974, since the data are missing)
        { 0, 0, 0.02947, 0.28761, 0.49601, 0.1235, 0.05465, 0.00876, 0, 0 },
        // 1974
        { 0, 0, 0.02947, 0.28761, 0.49601, 0.1235, 0.05465, 0.00876, 0, 0 },
        // 1975
        { 0, 0, 0.3285, 0.20608, 0.34301, 0.02296, 0.03706, 0.0384, 0.02259, 0.00141 },
        // 1976
        { 0, 0.00963, 0.1221, 0.54827, 0.19711, 0.08258, 0.01774, 0.01134, 0.00965, 0.00156 },
        // 1977
        { 0.00006, 0.01653, 0.04224, 0.14255, 0.53647, 0.18154, 0.04983, 0.01275, 0.01068, 0.00734 },
        // 1978
        { 0.00043, 0.06851, 0.27328, 0.1033, 0.14928, 0.2933, 0.07258, 0.02364, 0.00769, 0.00799 },
        // 1979
        { 0.00002, 0.01438, 0.27776, 0.43437, 0.08048, 0.05762, 0.095, 0.02856, 0.00721, 0.00458 },
        // 1980
        { 0.00142, 0.10899, 0.15192, 0.33431, 0.21001, 0.06484, 0.04937, 0.04584, 0.02229, 0.011 },
        // 1981
        { 0.00075, 0.01367, 0.16676, 0.39065, 0.25354, 0.10726, 0.02576, 0.02553, 0.01443, 0.00165 },
        // 1982
        { 0.00003, 0.03483, 0.18133, 0.32899, 0.23417, 0.1771, 0.03416, 0.00434, 0.00302, 0.00203 },
        // 1983
        { 0, 0.00933, 0.05291, 0.28208, 0.35202, 0.17282, 0.10771, 0.01891, 0.00318, 0.00105 },
        // 1984
        { 0.00074, 0.00523, 0.07277, 0.08555, 0.26635, 0.37642, 0.13791, 0.04258, 0.01194, 0.00052 },
        // 1985
        { 0.00012, 0.03505, 0.0152, 0.09134, 0.1161, 0.23654, 0.3546, 0.11327, 0.02982, 0.00797 },
        // 1986
        { 0.00748, 0.09847, 0.23215, 0.11549, 0.21841, 0.08352, 0.09933, 0.11167, 0.02435, 0.00913 },
        // 1987
        { 0, 0.13087, 0.20798, 0.1186, 0.10223, 0.09542, 0.10647, 0.06219, 0.14756, 0.02869 },
        // 1988
        { 0.00215, 0.03978, 0.27148, 0.35171, 0.15581, 0.06659, 0.04498, 0.02118, 0.00442, 0.04188 },
        // 1989
        { 0.01232, 0.00309, 0.01675, 0.22096, 0.32915, 0.19318, 0.09222, 0.0542, 0.0193, 0.05883 },
        // 1990
        { 0, 0.03537, 0.03067, 0.03828, 0.12136, 0.51652, 0.16698, 0.06264, 0.01379, 0.0144 },
        // 1991
        { 0, 0.00732, 0.12117, 0.06818, 0.03571, 0.06675, 0.33381, 0.0391, 0.20153, 0.12643 },
        // 1992
        { 0.00049, 0.02971, 0.05095, 0.46256, 0.12914, 0.03678, 0.08015, 0.1787, 0.00933, 0.02218 },
        // 1993
        { 0.00014, 0.01598, 0.07648, 0.17711, 0.38511, 0.12755, 0.05313, 0.05106, 0.06913, 0.04431 },
        // 1994
        { 0.00049, 0.01107, 0.03962, 0.0849, 0.31682, 0.2763, 0.10763, 0.04268, 0.04054, 0.07995 },
        // 1995
        { 0, 0.00096, 0.01559, 0.07909, 0.17836, 0.39979, 0.18707, 0.04627, 0.02357, 0.0693 },
        // 1996
        { 0.00009, 0.02921, 0.03158, 0.02569, 0.08048, 0.11762, 0.2961, 0.24368, 0.07213, 0.10343 },
        // 1997
        { 0, 0.01554, 0.09753, 0.05471, 0.04753, 0.0958, 0.14635, 0.23962, 0.17759, 0.12533 },
        // 1998
        { 0.00233, 0.00202, 0.19594, 0.27, 0.11159, 0.04927, 0.05559, 0.08419, 0.11084, 0.11824 },
        // 1999
        { 0, 0.00416, 0.02215, 0.22756, 0.36133, 0.08999, 0.06896, 0.03726, 0.05711, 0.13149 },
        // 2000
        { 0.00117, 0.01467, 0.04266, 0.05222, 0.22042, 0.37043, 0.09385, 0.07602, 0.03465, 0.09391 },
        // 2001
        { 0.0102, 0.14039, 0.09131, 0.10172, 0.13052, 0.17447, 0.20011, 0.06552, 0.03745, 0.0483 },
        // 2002
        { 0.00239, 0.1806, 0.30401, 0.09921, 0.06563, 0.12833, 0.07883, 0.08887, 0.01946, 0.03268 },
        // 2003
        { 0.00211, 0.03968, 0.31673, 0.33854, 0.07856, 0.04801, 0.0687, 0.05545, 0.03811, 0.01411 },
        // 2004
        { 0.00966, 0.07115, 0.13501, 0.36079, 0.28428, 0.06773, 0.02755, 0.02983, 0.00869, 0.00532 },
        // 2005
        { 0.01323, 0.01409, 0.06199, 0.07972, 0.48013, 0.2529, 0.07103, 0.00866, 0.01055, 0.00771 },
        // 2006
        { 0.03279, 0.11588, 0.06191, 0.04089, 0.08878, 0.40737, 0.19036, 0.03641, 0.01233, 0.01328 },
        // 2007
        { 0.01502, 0.34553, 0.13641, 0.04594, 0.04231, 0.06555, 0.18643, 0.12248, 0.02909, 0.01122 },
        // 2008
        { 0.00624, 0.12369, 0.43107, 0.13284, 0.04231, 0.02274, 0.04465, 0.10994, 0.05583, 0.03068 },
        // 2009
        { 0.00529, 0.14023, 0.32617, 0.29596, 0.08387, 0.02607, 0.01585, 0.02092, 0.04177, 0.04386 },
        // 2010
        { 0.0001, 0.06931, 0.30603, 0.27942, 0.23765, 0.04817, 0.01456, 0.00954, 0.01203, 0.0232 },
        // 2011
        { 0, 0.03098, 0.15145, 0.33313, 0.25965, 0.16319, 0.03698, 0.00759, 0.00478, 0.01225 },
        // 2012
        { 0.00039, 0.00806, 0.05647, 0.16424, 0.36307, 0.26084, 0.10878, 0.02368, 0.00529, 0.00919 },
        // 2013 (copied from 2012, since the data weren't available at the time)
        { 0.00039, 0.00806, 0.05647, 0.16424, 0.36307, 0.26084, 0.10878, 0.02368, 0.00529, 0.00919 }
    };
    atl::Matrix<T> obs_wt_at_age = {
        // 1964
        { 0.125, 0.21, 0.33, 0.45, 0.56, 0.65, 0.74, 0.81, 0.88, 1.02 },
        // 1965
        { 0.125, 0.21, 0.33, 0.45, 0.56, 0.65, 0.74, 0.81, 0.88, 1.02 },
        // 1966
        { 0.125, 0.21, 0.33, 0.45, 0.56, 0.65, 0.74, 0.81, 0.88, 1.02 },
        // 1967
        { 0.125, 0.21, 0.33, 0.45, 0.56, 0.65, 0.74, 0.81, 0.88, 1.02 },
        // 1968
        { 0.125, 0.21, 0.33, 0.45, 0.56, 0.65, 0.74, 0.81, 0.88, 1.02 },
        // 1969
        { 0.125, 0.21, 0.33, 0.45, 0.56, 0.65, 0.74, 0.81, 0.88, 1.02 },
        // 1970
        { 0.125, 0.21, 0.33, 0.45, 0.56, 0.65, 0.74, 0.81, 0.88, 1.02 },
        // 1971
        { 0.125, 0.21, 0.33, 0.45, 0.56, 0.65, 0.74, 0.81, 0.88, 1.02 },
        // 1972
        { 0.125, 0.19, 0.38, 0.58, 0.76, 0.91, 1.03, 1.13, 1.2, 1.34 },
        // 1973
        { 0.125, 0.19, 0.38, 0.58, 0.76, 0.91, 1.03, 1.13, 1.2, 1.34 },
        // 1974
        { 0.125, 0.19, 0.38, 0.58, 0.76, 0.91, 1.03, 1.13, 1.2, 1.34 },
        // 1975
        { 0.125, 0.19, 0.38, 0.58, 0.76, 0.91, 1.03, 1.13, 1.2, 1.34 },
        // 1976
        { 0.125, 0.2, 0.32, 0.5, 0.6, 0.74, 0.85, 1, 0.93, 1 },
        // 1977
        { 0.125, 0.23, 0.43, 0.63, 0.8, 0.94, 1.06, 1.15, 1.22, 1.35 },
        // 1978
        { 0.125, 0.19, 0.39, 0.58, 0.76, 0.91, 1.04, 1.13, 1.21, 1.34 },
        // 1979
        { 0.125, 0.23, 0.42, 0.62, 0.79, 0.94, 1.06, 1.15, 1.22, 1.35 },
        // 1980
        { 0.125, 0.2, 0.39, 0.59, 0.77, 0.92, 1.04, 1.13, 1.21, 1.35 },
        // 1981
        { 0.125, 0.2, 0.4, 0.59, 0.77, 0.92, 1.04, 1.14, 1.21, 1.35 },
        // 1982
        { 0.125, 0.18, 0.37, 0.57, 0.75, 0.9, 1.03, 1.13, 1.2, 1.34 },
        // 1983
        { 0.125, 0.17, 0.36, 0.56, 0.74, 0.89, 1.02, 1.12, 1.2, 1.34 },
        // 1984
        { 0.125, 0.17, 0.36, 0.56, 0.74, 0.9, 1.02, 1.12, 1.2, 1.34 },
        // 1985
        { 0.125, 0.16, 0.34, 0.54, 0.73, 0.88, 1.01, 1.11, 1.19, 1.34 },
        // 1986
        { 0.125, 0.16, 0.35, 0.55, 0.73, 0.89, 1.02, 1.12, 1.19, 1.34 },
        // 1987
        { 0.125, 0.13, 0.41, 0.66, 0.88, 1.05, 1.2, 1.31, 1.39, 1.44 },
        // 1988
        { 0.125, 0.13, 0.41, 0.66, 0.88, 1.05, 1.2, 1.31, 1.39, 1.44 },
        // 1989
        { 0.125, 0.13, 0.41, 0.66, 0.88, 1.05, 1.2, 1.31, 1.39, 1.44 },
        // 1990
        { 0.125, 0.247, 0.599, 0.754, 0.966, 1.079, 1.23, 1.253, 1.291, 1.528 },
        // 1991
        { 0.125, 0.284, 0.466, 0.649, 0.844, 1.03, 1.104, 1.162, 1.26, 1.426 },
        // 1992
        { 0.125, 0.3, 0.43, 0.631, 0.714, 0.83, 1.117, 1.198, 1.234, 1.309 },
        // 1993
        { 0.125, 0.36, 0.579, 0.719, 0.808, 0.877, 1.052, 1.16, 1.211, 1.227 },
        // 1994
        { 0.125, 0.301, 0.548, 0.759, 0.955, 1.06, 1.091, 1.281, 1.315, 1.448 },
        // 1995
        { 0.125, 0.301, 0.652, 0.967, 1.056, 1.085, 1.209, 1.279, 1.335, 1.404 },
        // 1996
        { 0.125, 0.253, 0.354, 0.718, 1.034, 1.113, 1.175, 1.226, 1.307, 1.371 },
        // 1997
        { 0.125, 0.307, 0.473, 0.757, 1.024, 1.169, 1.205, 1.252, 1.281, 1.336 },
        // 1998
        { 0.125, 0.301, 0.493, 0.578, 0.792, 1.023, 1.219, 1.33, 1.385, 1.431 },
        // 1999
        { 0.125, 0.358, 0.594, 0.726, 0.77, 0.923, 1.079, 1.209, 1.331, 1.374 },
        // 2000
        { 0.125, 0.312, 0.434, 0.773, 0.991, 0.998, 1.202, 1.271, 1.456, 1.663 },
        // 2001
        { 0.125, 0.292, 0.442, 0.701, 1.003, 1.208, 1.286, 1.473, 1.54, 1.724 },
        // 2002
        { 0.125, 0.316, 0.48, 0.615, 0.898, 1.05, 1.146, 1.263, 1.363, 1.522 },
        // 2003
        { 0.125, 0.369, 0.546, 0.507, 0.715, 1.049, 1.242, 1.43, 1.511, 1.7 },
        // 2004
        { 0.125, 0.259, 0.507, 0.72, 0.677, 0.896, 1.123, 1.262, 1.338, 1.747 },
        // 2005
        { 0.125, 0.275, 0.446, 0.79, 1.005, 0.977, 0.921, 1.305, 1.385, 1.485 },
        // 2006
        { 0.125, 0.26, 0.566, 0.974, 1.229, 1.242, 1.243, 1.358, 1.424, 1.653 },
        // 2007
        { 0.125, 0.345, 0.469, 0.885, 1.195, 1.385, 1.547, 1.634, 1.749, 1.94 },
        // 2008
        { 0.125, 0.309, 0.649, 0.856, 1.495, 1.637, 1.894, 1.896, 1.855, 2.204 },
        // 2009
        { 0.125, 0.235, 0.566, 0.96, 1.249, 1.835, 2.002, 2.151, 2.187, 2.208 },
        // 2010
        { 0.125, 0.327, 0.573, 0.972, 1.267, 1.483, 1.674, 2.036, 2.329, 2.191 },
        // 2011
        { 0.125, 0.473, 0.593, 0.833, 1.107, 1.275, 1.409, 1.632, 1.999, 1.913 },
        // 2012
        { 0.125, 0.294, 0.793, 0.982, 1.145, 1.425, 1.6, 1.869, 2.051, 2.237 },
        // 2013 (copied from 2012 since the data weren't available at the time)
        { 0.125, 0.294, 0.793, 0.982, 1.145, 1.425, 1.6, 1.869, 2.051, 2.237 }
    };

    atl::Variable<T> yrfrac_sp = 0.21;  // fraction of the year for spawning

    int nsrvs = 3;
    atl::Vector<T> yrfrac_srv = { 0.209, 0.584, 0.60989 };

    int nyrs_srv1a = 1;
    atl::Vector<T> obs_srv_1a_biomass = { -1 };     // early EIT survey

    int nyrs_srv1b = 1;
    atl::Vector<T> obs_srv_1b_biomass = { -1 };     // middle EIT survey

    int nyrs_srv1 = 1;
    atl::Vector<T> obs_srv_1_biomass = { -1 };      // recent EIT survey

    int nyrs_srv2 = 3;
    atl::Vector<T> obs_srv_2_biomass = { 1, 1, 1 };         // NMFS bottom trawl survey

    int nyrs_srv3 = 1;
    atl::Vector<T> obs_srv_3_biomass = { -1 };      // ADF&G nearshore trawl survey


    atl::Vector<T> M = { 1.4, 0.7, 0.5, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3 };

    //Estimated(read only)
    atl::Variable<T> log_initial_R_dev;
    atl::Vector<atl::Variable<T> > init_pop_devs;
    atl::Vector<atl::Variable<T> > initial_population;

    atl::Variable<T> log_mean_recruits;
    atl::Vector<atl::Variable<T> > recruit_devs;
    atl::Vector<atl::Variable<T> > recruits;

    atl::Variable<T> log_h;
    atl::Variable<T> h;

    //selectivity model
    atl::Variable<T> log_fsh_sel_asc_alpha;
    atl::Variable<T> log_fsh_sel_asc_beta;
    atl::Variable<T> fsh_sel_asc_alpha;
    atl::Variable<T> fsh_sel_asc_beta;

    atl::Variable<T> log_fsh_sel_desc_alpha;
    atl::Variable<T> log_fsh_sel_desc_beta;
    atl::Variable<T> fsh_sel_desc_alpha;
    atl::Variable<T> fsh_sel_desc_beta;

    atl::Matrix<atl::Variable<T> > fsh_sel;


    atl::Vector<atl::Variable<T> > log_srv_sel_asc_alpha;
    atl::Vector<atl::Variable<T> > log_srv_sel_asc_beta;
    atl::Vector<atl::Variable<T> > srv_sel_asc_alpha;
    atl::Vector<atl::Variable<T> > srv_sel_asc_beta;

    atl::Vector<atl::Variable<T> > log_srv_sel_desc_alpha;
    atl::Vector<atl::Variable<T> > log_srv_sel_desc_beta;
    atl::Vector<atl::Variable<T> > srv_sel_desc_alpha;
    atl::Vector<atl::Variable<T> > srv_sel_desc_beta;

    atl::Matrix<atl::Variable<T> > srv_sel;

    //growth model
    atl::Variable<T> gr_Winf;
    atl::Variable<T> gr_k;
    atl::Variable<T> gr_a0;

    atl::Variable<T> log_mean_fsh_mort;
    atl::Vector<atl::Variable<T> > fsh_mort_devs;
    atl::Vector<atl::Variable<T> > fsh_mort;

    // catchability for srv 1 (EIT survey; 3 periods)
    atl::Variable<T> log_srv_1a_q;
    atl::Variable<T> srv_1a_q;

    atl::Variable<T> log_srv_1b_q;
    atl::Variable<T> srv_1b_q;

    atl::Variable<T> log_srv_1_q;
    atl::Variable<T> srv_1_q;

    // catchability for srv 2 (bottom trawl survey)
    atl::Variable<T> log_srv_2_q;
    atl::Variable<T> srv_2_q;

    // catchability for srv 3 (ADF&G survey)
    atl::Variable<T> log_srv_3_q;
    atl::Variable<T> srv_3_q;

    //Runtime(writable)
    atl::Matrix<atl::Variable<T> > wtAA;
    atl::Matrix<atl::Variable<T> > F;
    atl::Matrix<atl::Variable<T> > Z;
    atl::Matrix<atl::Variable<T> > expZ;
    atl::Matrix<atl::Variable<T> > expZ_sp;
    atl::Matrix<atl::Variable<T> > expZ_yrfrac_srv1;
    atl::Matrix<atl::Variable<T> > expZ_yrfrac_srv2;
    atl::Matrix<atl::Variable<T> > expZ_yrfrac_srv3;
    atl::Matrix<atl::Variable<T> > N;
    atl::Matrix<atl::Variable<T> > C;

    atl::Vector<atl::Variable<T> > est_catch;
    atl::Matrix<atl::Variable<T> > est_fsh_prop_at_age;
    atl::Vector<atl::Variable<T> > est_sp_biomass;
    atl::Vector<atl::Variable<T> > est_srv_1a_biomass;
    atl::Vector<atl::Variable<T> > est_srv_1b_biomass;
    atl::Vector<atl::Variable<T> > est_srv_1_biomass;
    atl::Vector<atl::Variable<T> > est_srv_2_biomass;
    atl::Vector<atl::Variable<T> > est_srv_3_biomass;

public:

    void Initialize()
    {
        srv_sel.Resize(nyrs, nages);
        wtAA.Resize(nyrs, nages);
        F.Resize(nyrs, nages);
        Z.Resize(nyrs, nages);
        expZ.Resize(nyrs, nages);
        expZ_sp.Resize(nyrs,nages);
        expZ_yrfrac_srv1.Resize(nyrs, nages);
        expZ_yrfrac_srv2.Resize(nyrs, nages);
        expZ_yrfrac_srv3.Resize(nyrs, nages);
        N.Resize((nyrs+1), nages);
        C.Resize(nyrs, nages);
        fsh_sel.Resize(nyrs,nages);
        srv_sel.Resize(nsrvs,nages);
        est_catch.Resize(nyrs);
        est_fsh_prop_at_age.Resize(nyrs,nages);
        est_sp_biomass.Resize(nyrs);
        est_srv_1a_biomass.Resize(nyrs_srv1a);
        est_srv_1b_biomass.Resize(nyrs_srv1b);
        est_srv_1_biomass.Resize(nyrs_srv1);
        est_srv_2_biomass.Resize(nyrs_srv2);
        est_srv_3_biomass.Resize(nyrs_srv3);


        this->Register(log_fsh_sel_asc_alpha,4,"log_fsh_sel_asc_alpha");
        this->Register(log_fsh_sel_asc_beta,4,"log_fsh_sel_asc_beta");
        this->Register(log_fsh_sel_desc_alpha,4,"log_fsh_sel_desc_alpha");
        this->Register(log_fsh_sel_desc_beta,4,"log_fsh_sel_desc_beta");

        log_fsh_sel_asc_alpha.SetBounds(0.0,2.0);
        log_fsh_sel_asc_beta.SetBounds(-5.0,5.0);
        log_fsh_sel_desc_alpha.SetBounds(1.0,3.0);
        log_fsh_sel_desc_beta.SetBounds(-5.0,5.0);

        log_fsh_sel_asc_alpha  = atl::Variable<T>(1.304078496);
        log_fsh_sel_asc_beta   = atl::Variable<T>(0.909366079);
        log_fsh_sel_desc_alpha = atl::Variable<T>(2.202837078);
        log_fsh_sel_desc_beta  = atl::Variable<T>(0.156959058);


        log_srv_sel_asc_alpha.Resize(nsrvs);
        log_srv_sel_asc_beta.Resize(nsrvs);
        srv_sel_asc_alpha.Resize(nsrvs);
        srv_sel_asc_beta.Resize(nsrvs);

        // this->Register(log_srv_sel_asc_alpha,1,"log_srv_sel_asc_alpha");
        // this->Register(log_srv_sel_asc_beta,1,"log_srv_sel_asc_beta");

        log_srv_sel_asc_alpha.SetBounds(0.0,5.0);
        log_srv_sel_asc_beta.SetBounds(-5.0,5.0);

        log_srv_sel_asc_alpha = atl::Variable<T>(0.0);
        log_srv_sel_asc_beta  = atl::Variable<T>(0.0);


        log_srv_sel_desc_alpha.Resize(nsrvs);
        log_srv_sel_desc_beta.Resize(nsrvs);
        srv_sel_desc_alpha.Resize(nsrvs);
        srv_sel_desc_beta.Resize(nsrvs);

        // this->Register(log_srv_sel_desc_alpha,1,"log_srv_sel_desc_alpha");
        // this->Register(log_srv_sel_desc_beta,1,"log_srv_sel_desc_beta");

        log_srv_sel_desc_alpha.SetBounds(1.0,5.0);
        log_srv_sel_desc_beta.SetBounds(-5.0,5.0);

        log_srv_sel_desc_alpha = atl::Variable<T>(0.0);
        log_srv_sel_desc_beta  = atl::Variable<T>(0.0);


        // this->Register(log_srv_1a_q,3,"log_srv_1a_q");
        // this->Register(log_srv_1b_q,3,"log_srv_1b_q");
        // this->Register(log_srv_1_q,3,"log_srv_1_q");

        log_srv_1a_q.SetBounds(-10.0,10.0);
        log_srv_1a_q = atl::Variable<T>(0.0);
        log_srv_1b_q.SetBounds(-10.0,10.0);
        log_srv_1b_q = atl::Variable<T>(0.0);
        log_srv_1_q.SetBounds(-10.0,10.0);
        log_srv_1_q = atl::Variable<T>(0.0);

        // this->Register(log_srv_2_q,3,"log_srv_2_q");
        log_srv_2_q.SetBounds(-10.0,10.0);
        log_srv_2_q = atl::Variable<T>(0.0);

        // this->Register(log_srv_3_q,3,"log_srv_3_q");
        log_srv_3_q.SetBounds(-10.0,10.0);
        log_srv_3_q = atl::Variable<T>(0.0);


        this->Register(log_mean_recruits,1,"log_mean_rec");

        log_mean_recruits.SetBounds(5.0, 35.0);
        log_mean_recruits = atl::Variable<T>(21.723265836946411156161923092159);


        this->Register(log_mean_fsh_mort,1,"log_mean_fsh_mort");

        log_mean_fsh_mort.SetBounds(-10.0,10.0);
        log_mean_fsh_mort = atl::Variable<T>(-1.6);

        this->Register(log_initial_R_dev, 2, "log_init_R_dev");

        log_initial_R_dev.SetBounds(-5.0, 5.0);
        log_initial_R_dev = atl::Variable<T>(0.0);


        init_pop_devs.Resize(nages-1);
        initial_population.Resize(nages);

        recruit_devs.Resize(nyrs);
        recruits.Resize(nyrs+1);

        fsh_mort_devs.Resize(nyrs);
        fsh_mort.Resize(nyrs);

        // this->Register(init_pop_devs, 3, "init_pop_devs");
        this->Register(recruit_devs, 3, "recruit_devs");
        this->Register(fsh_mort_devs, 2,"fsh_mort_devs");

        init_pop_devs.SetBounds(-15.0,15.0);
        init_pop_devs = atl::Variable<T>(0.0);

        recruit_devs.SetBounds(-15.0, 15.0);
        recruit_devs = atl::Variable<T>(0.0);

        fsh_mort_devs.SetBounds(-10.0, 10.0);
        fsh_mort_devs = atl::Variable<T>(0.0);
    }

    void Selectivity()
    {
        atl::Variable<T> max_sel;

        fsh_sel_asc_alpha  = atl::exp(log_fsh_sel_asc_alpha);
        fsh_sel_asc_beta   = atl::exp(log_fsh_sel_asc_beta);
        fsh_sel_desc_alpha = atl::exp(log_fsh_sel_desc_alpha);
        fsh_sel_desc_beta  = atl::exp(log_fsh_sel_desc_beta);

        for ( int j = 0; j < nages; j++ )
        {
            fsh_sel(0, j) = (1.0 / (1.0 + atl::exp(-fsh_sel_asc_beta * (T(j) - fsh_sel_asc_alpha)))) * (1.0 - (1.0 / (1.0 + atl::exp(-fsh_sel_desc_beta * (T(j) - fsh_sel_desc_alpha)))));
        }

        max_sel = atl::Max<T>(atl::Row(fsh_sel, 0));

        // can this operation be vectorized?
        for ( int j = 0; j < nages; j++ )
        {
            fsh_sel(0, j) /= max_sel;
        }

        // lots of explicit operations...
        atl::Vector<atl::Variable<T> > sel_row;
        sel_row.Resize(nages);
        sel_row = atl::Row(fsh_sel, 0);

        for ( int i = 1; i < nyrs; i++ )
        {
            // can this operation be vectorized?
            for ( int j = 0; j < nages; j++ )
            {
                fsh_sel(i, j) = sel_row(j);
            }
        }


        srv_sel_asc_alpha  = atl::exp(log_srv_sel_asc_alpha);
        srv_sel_asc_beta   = atl::exp(log_srv_sel_asc_beta);
        srv_sel_desc_alpha = atl::exp(log_srv_sel_desc_alpha);
        srv_sel_desc_beta  = atl::exp(log_srv_sel_desc_beta);

        for ( int k = 0; k < nsrvs; k++ )
        {
            for ( int j = 0; j < nages ; j++ )
            {
                // srv_sel(k, j) = (1.0 / (1.0 + atl::exp(-srv_sel_asc_beta(k) * (T(j) - srv_sel_asc_alpha(k))))) * (1.0 - (1.0 / (1.0 + atl::exp(-srv_sel_desc_beta(k) * (T(j) - srv_sel_desc_alpha(k))))));
            }

            // lots of explicit operations
            sel_row = atl::Row(srv_sel, k);
            max_sel = atl::Max<T>(sel_row);
            for ( int j = 0; j < nages ; j++ )
            {
                // srv_sel(k,j ) /= max_sel;
            }
        }
    }

    void Growth()
    {
        for ( int j = 0; j < nages ; j++ )
        {
            wtAA(0, j) = gr_Winf * (1.0 - atl::exp(-gr_k * (T(j) - gr_a0)));
        }

        for ( int i = 1; i < nyrs; i++ )
        {
            for ( int j = 0; j < nages; j++ )
            {
                wtAA(i, j) = wtAA(0, j);
            }
        }
    }

    void Mortality()
    {
         for (int i = 0; i < nyrs; i++)
        {
            fsh_mort(i) = atl::exp(log_mean_fsh_mort + fsh_mort_devs(i));

            for (int j = 0; j < nages; j++)
            {
                F(i, j) = fsh_mort(i) * fsh_sel(i, j);
            }
        }

        for (int i = 0; i < nyrs; i++) {
            for (int j = 0; j < nages; j++) {
                Z(i, j) = F(i, j) + M(j);
            }
        }
    }

    void Survivability()
    {
        for ( int i = 0; i < nyrs; i++ )
        {
            for ( int j = 0; j < nages; j++ )
            {
                expZ(i, j)    = atl::exp(-1.0 * Z(i, j));

                expZ_sp(i, j) = atl::exp(-yrfrac_sp * Z(i, j));

                expZ_yrfrac_srv1(i, j) = atl::exp(-yrfrac_srv(0) * Z(i, j));
                expZ_yrfrac_srv2(i, j) = atl::exp(-yrfrac_srv(1) * Z(i, j));
                expZ_yrfrac_srv3(i, j) = atl::exp(-yrfrac_srv(2) * Z(i, j));
            }
        }
    }

    void NumbersAtAge()
    {
        initial_population(0) = atl::exp(log_mean_recruits + log_initial_R_dev + recruit_devs(0));

        for ( int j = 1; j < nages; j++ )
        {
            initial_population(j) = initial_population(j-1) * atl::exp(atl::Variable<T>(-M(j-1)));
        }
        initial_population(nages-1) /= (1.0 - atl::exp(atl::Variable<T>(-M(nages-1))));

        for ( int j = 1; j < nages; j++ )
        {
            initial_population(j) *= atl::exp(init_pop_devs(j-1));
        }

        // std::cout << "init pop " << initial_population << std::endl;

        // can this operation be vectorized?
        for ( int j = 1; j < nages; j++ )
        {
            N(0, j) = initial_population(j);
        }

        // could put a S-R relationship here
        N(0, 0) = atl::exp(log_mean_recruits + log_initial_R_dev);

        // std::cout << "first year N-at-age " << atl::Row(N, 0) << std::endl;

        for ( int i = 0; i < nyrs; i++ )
        {
            N(i, 0) *= atl::exp(recruit_devs(i));

            // this assumes continuous fishing
            for ( int j = 1; j < nages; j++ )
            {
                N(i+1, j) = N(i, j-1) * expZ(i, j-1);
            }
            N(i+1, (nages-1)) = (N(i, (nages-1)) * expZ(i, (nages-1))) + (N(i, (nages-1)-1) * expZ(i, (nages-1)-1));

            N(i+1, 0) = atl::exp(log_mean_recruits);

            // std::cout << "N-at-age in year " << i << " " << atl::Row(N, i) << std::endl;

            // calculate spawning biomass here
        }

        recruits = atl::Column(N,0);
    }

    void FleetIndices()
    {
        // TODO
        srv_1a_q = atl::exp(log_srv_1a_q);
        srv_1b_q = atl::exp(log_srv_1b_q);
        srv_1_q  = atl::exp(log_srv_1_q);
        srv_2_q  = atl::exp(log_srv_2_q);
        srv_3_q  = atl::exp(log_srv_3_q);

    }

    void CalculateCatchAtAge()
    {
        atl::Variable<T> est_catch_num;

        for ( int i = 0; i < nyrs; i++ )
        {
            est_catch(i) = 0;

            for ( int j = 0; j < nages; j++ )
            {
                C(i, j) = (F(i, j) / Z(i, j)) * ((1.0 - expZ(i, j)) * N(i, j));
                est_catch(i) += (obs_wt_at_age(i, j) * C(i, j));
            }

            // convert from kg to mt
            est_catch(i) /= 1000.0;

            est_catch_num = atl::Sum(atl::Row(C,i));

            // can this operation be vectorized?
            for ( int j = 0; j < nages; j++ )
            {
                est_fsh_prop_at_age(i, j) = C(i, j) / est_catch_num;
            }
        }
    }

    void ObjectiveFunction(atl::Variable<T>& f)
    {
        atl::Variable<T> o = 0.00001;  // small value for proportions calculations

        this->Selectivity();
        this->Growth();
        this->Mortality();
        this->Survivability();
        this->NumbersAtAge();
        this->FleetIndices();
        this->CalculateCatchAtAge();

        f = 0;

        // NLL for catch
        for (int i = 0; i < nyrs; i++)
        {
            f += (1.0 / (2.0 * 0.1 * 0.1)) * (atl::log(obs_catch(i) + o) - atl::log(est_catch(i) + o)) * (atl::log(obs_catch(i) + o) - atl::log(est_catch(i) + o));
        }

        // NLL for fsh proportions at age
        for ( int i = 0; i < nyrs; i++ )
        {
            for ( int j = 0; j < nages; j++ )
            {
                f -= (obs_fsh_N(i) * (obs_fsh_prop_at_age(i,j) + o) * (log(est_fsh_prop_at_age(i,j) + o) - log(obs_fsh_prop_at_age(i,j) + o)));
            }
        }

        // penalty on initial population devs
        f +=  (1.0 / (2.0 * 1.0 * 1.0)) * atl::Norm2(init_pop_devs);

        // penalty on rec devs
        f +=  (1.0 / (2.0 * 1.0 * 1.0)) * atl::Norm2(recruit_devs);

        // penalty to ensure that N(1964,0) and N(1965,0) are close
        f += 1000.0 * (atl::log(N(0,0)) - atl::log(N(1,0))) * (atl::log(N(0,0)) - atl::log(N(1,0)));

    }

    void Report()
    {
        atl::Variable<T> one_meeellion = 1000000.0;	// conversion factor

        std::cout << std::endl;

        std::cout << "log initial_R " << (log_mean_recruits + log_initial_R_dev) << std::endl;
        std::cout << "init devs " << init_pop_devs << std::endl;
        std::cout << "init N-at-age " << initial_population << std::endl;
        std::cout << "ratios " << (initial_population / initial_population(0)) << std::endl;
        std::cout << std::endl;

        std::cout << "log mean_recruits " << log_mean_recruits << std::endl;
        std::cout << "recruit_devs " << recruit_devs << std::endl;
        std::cout << "recruits " << recruits << std::endl;
        std::cout << std::endl;

        std::cout << "log mean_fsh_mort " << log_mean_fsh_mort << std::endl;
        std::cout << "fsh_mort_devs " << fsh_mort_devs << std::endl;
        std::cout << "fsh_mort " << fsh_mort << std::endl;
        std::cout << std::endl;

        std::cout << "log fsh_sel_asc_alpha " << log_fsh_sel_asc_alpha << std::endl;
        std::cout << "log fsh_sel_asc_beta " << log_fsh_sel_asc_beta << std::endl;
        std::cout << "log fsh_sel_desc_alpha " << log_fsh_sel_desc_alpha << std::endl;
        std::cout << "log fsh_sel_desc_beta " << log_fsh_sel_desc_beta << std::endl;
        std::cout << "fsh_sel_asc_alpha " << fsh_sel_asc_alpha << std::endl;
        std::cout << "fsh_sel_asc_beta " << fsh_sel_asc_beta << std::endl;
        std::cout << "fsh_sel_desc_alpha " << fsh_sel_desc_alpha << std::endl;
        std::cout << "fsh_sel_desc_beta " << fsh_sel_desc_beta << std::endl;
        std::cout << "fsh sel" << std::endl;
        std::cout << fsh_sel << std::endl;
        std::cout << std::endl;

        std::cout << "observed catch " << obs_catch << std::endl;
        std::cout << "estimated catch " << est_catch << std::endl;
        std::cout << std::endl;

        std::cout << "srv_1a_q " << srv_1a_q << std::endl;
        std::cout << "srv_1b_q " << srv_1b_q << std::endl;
        std::cout << "srv_1_q " << srv_1_q << std::endl;
        std::cout << "srv_2_q " << srv_2_q << std::endl;
        std::cout << "srv_3_q " << srv_3_q << std::endl;
        std::cout << "srv_sel_asc_alpha " << srv_sel_asc_alpha << std::endl;
        std::cout << "srv_sel_asc_beta " << srv_sel_asc_beta << std::endl;
        std::cout << "srv_sel_desc_alpha " << srv_sel_desc_alpha << std::endl;
        std::cout << "srv_sel_desc_beta " << srv_sel_desc_beta << std::endl;

        for ( int k = 0; k < nsrvs; k++ )
        {
            std::cout << "srv_sel " << k << " " << atl::Row(srv_sel, k) << std::endl;
        }
        std::cout << std::endl;

        std::cout << "observed srv 1a " << obs_srv_1a_biomass << std::endl;
        std::cout << "estimated srv 1a " << est_srv_1a_biomass << std::endl;
        std::cout << "observed srv 1b " << obs_srv_1b_biomass << std::endl;
        std::cout << "estimated srv 1b " << est_srv_1b_biomass << std::endl;
        std::cout << "observed srv 1 " << obs_srv_1_biomass << std::endl;
        std::cout << "estimated srv 1 " << est_srv_1_biomass << std::endl;
        std::cout << "observed srv 2 " << obs_srv_2_biomass << std::endl;
        std::cout << "estimated srv 2 " << est_srv_2_biomass << std::endl;
        std::cout << "observed srv 3 " << obs_srv_3_biomass << std::endl;
        std::cout << "estimated srv 3 " << est_srv_3_biomass << std::endl;
        std::cout << std::endl;

        std::cout << "N at age" << std::endl;
        std::cout << (N/one_meeellion) << std::endl;

        std::cout << std::endl;
    }
};



#endif /* CATCHATAGE_HPP */
