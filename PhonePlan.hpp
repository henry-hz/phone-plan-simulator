/* 
 * File:   PhonePlan.hpp
 * Author: henry
 *
 * Created on August 17, 2011, 12:50 AM
 */

#ifndef PHONEPLAN_HPP
#define	PHONEPLAN_HPP

class PhonePlan {
    double base_fee;
    double included_minutes;
    double aditional_minutes;
    double long_distance_fee;
    bool   unlimited_included_minutes;
public:
    PhonePlan(const bool&, const double&, const double&, const double&, const double&);
    PhonePlan(const PhonePlan& orig);
    double TotalCost(const int& , const double& );
    virtual ~PhonePlan();
private:

};

#endif	/* PHONEPLAN_HPP */

