/* 
 * File:   Simulator.cpp
 * Author: henry
 * 
 * Created on August 19, 2011, 7:41 AM
 */

#include "Simulator.hpp"

Simulator::Simulator() {
}

Simulator::Simulator(const Simulator& orig) {
}

Simulator::~Simulator() {
}

double* Simulator::GenerateNormalDistribution(const double& mean,const double& sigma,const int& size) {
    boost::mt19937 rng;
    boost::normal_distribution<> nd(0.0, 1.0);

    boost::variate_generator<boost::mt19937&,
            boost::normal_distribution<> > var_nor(rng, nd);    
    double *result = new double[size];
    for (int i = 0; i < size; i++) {
        double d = var_nor();
        result[i] = mean + (sigma * d);
        //std::cout << result[i] << std::endl
    }

    return result;
}

double* Simulator::GenerateTriangularDistribution(const double& min, const double& most_likely, 
        const double& max, const int& size) {
    //this->size = size;
    boost::triangle_distribution<> tr(min, most_likely, max);
    //boost::mt19937 gen;
    boost::random::random_device gen;
    double *result = new double[size];
    for (int i = 0; i < size; i++) {
        double d = tr(gen);
        result[i] = d;
    }
    //this->triangular_dist = result;
    return result;   
}


void Simulator::PrintDistribution() {
   // std::string chars("123456789");
//    boost::random::random_device rng;
    //boost::random::random_device rng;
    //boost::random::uniform_int_distribution<> index_dist(0, chars.size() -1);

//	std::string line;
//	boost::regex pat( "^Subject: (Re: |Aw: )*(.*)");
//
//	while (std::cin) {
//		std::getline(std::cin, line);
//		boost::smatch matches;
//		if(boost::regex_match(line, matches, pat))
//			std::cout << matches[2] << std::endl;
//	}    
}

