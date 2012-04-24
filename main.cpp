
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/random/normal_distribution.hpp>
#include "Simulator.hpp"
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <limits>

#include "PhonePlan.hpp"
#include <boost/io/ios_state.hpp>

using namespace std;
boost::random::mt19937 gen;

int sim_size = 10000;

void Print(double* d, string name) {
    std::ofstream myFile;
    myFile.open("dist.txt");
    myFile << name << endl;
    for (int i = 0; i < sim_size; i++) {
        std::cout << d[i] << endl;
        myFile << d[i] << endl;
    }
    myFile.close();
};

int main() {
    // celular world -> ilimitado, 39.99 base fee, include 400, adicional min 0.40, longDistance = 0
    PhonePlan cellularWorld(false, 39.99, 400, 0.40, 0);// = new PhonePlan(true)
    PhonePlan freedomCell(true, 35.00, 0,0, 0.08);
    
    Simulator sim;
    double *gaussian;
    double *triangular;
    gaussian = sim.GenerateNormalDistribution(400.0,20.0,sim_size);
    //Print(r, "CONSUMO");
    triangular = sim.GenerateTriangularDistribution(10,30,40,sim_size);
    //Print(r,"tri");
    double result[sim_size];
    for (int i = 0; i < sim_size; i++) {
        result[i] = freedomCell.TotalCost(gaussian[i], triangular[i]) - 
                    cellularWorld.TotalCost(gaussian[i], triangular[i]);
    }
    
    Print(result,"econ");
    
    return 0;
};

void test() {
    PhonePlan cellularWorld(false, 39.99, 400, 0.40, 0);// = new PhonePlan(true)
    PhonePlan freedomCell(true, 35.00, 0,0, 0.08);
    //cout.setf(ios::fixed,ios::floatfield);
    // boost::io::ios_flags_saver  ifs( ios );
    //cout << ios::fixed;
    //cout.precision(2);
    double result = cellularWorld.TotalCost(426.00,30);
    double result2 = freedomCell.TotalCost(426.00, 30);
    cout << "result " << result2 << endl;
    cout << "result " << result << endl;
    //cout << fixed << setprecision (numeric_limits<double>::digits10 + 1) << f << std::endl;
    //printf("%.90d", f);
    cout << endl;
};






