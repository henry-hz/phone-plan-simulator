/* 
 * File:   PhonePlan.cpp
 * Author: henry
 * 
 * Created on August 17, 2011, 12:50 AM
 */

#include "PhonePlan.hpp"
// unlimited_i_m = se eh plano ilimitado
// base_fee = mensalidade
// in_min   = minutos inclusos
// add_min  = minutos adicionais
PhonePlan::PhonePlan(const bool& unlimited_i_m, const double& base_fee, const double& in_min, const double& add_min, const double& ld) {
    
    this->unlimited_included_minutes = unlimited_i_m;
    this->aditional_minutes = add_min;
    this->base_fee = base_fee;
    this->included_minutes = in_min;
    this->long_distance_fee = ld;
}

PhonePlan::PhonePlan(const PhonePlan& orig) {
}

double PhonePlan::TotalCost(const int& actualMinutes, const double& longDistancePerc) {
    double minutes2longDist = (longDistancePerc/100) * actualMinutes;
    double longDistance = minutes2longDist * long_distance_fee;
   
        if (actualMinutes < included_minutes) {
            double total = base_fee + longDistance;
            return total;
        } else {
            double extra = aditional_minutes * (actualMinutes - included_minutes);
            double total = base_fee + extra + longDistance;
            return total;
        }
    return 0;
}

PhonePlan::~PhonePlan() {
}

