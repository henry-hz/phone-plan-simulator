/* 
 * File:   Simulator.hpp
 * Author: henry
 *
 * Created on August 19, 2011, 7:41 AM
 */
#include <boost/random/normal_distribution.hpp>
#include <boost/random.hpp>
#include <fstream>
#include <boost/random/random_device.hpp>
#include <iostream>
#include <boost/regex.hpp>
#include <string>

#ifndef SIMULATOR_HPP
#define	SIMULATOR_HPP

class Simulator {
public:
    Simulator();
    Simulator(const Simulator& orig);
    void PrintDistribution();
    double* GenerateNormalDistribution(const double& , const double& , const int& );
    double* GenerateTriangularDistribution(const double&, const double&, const double&, const int&);
    virtual ~Simulator();
private:

};

#endif	/* SIMULATOR_HPP */

