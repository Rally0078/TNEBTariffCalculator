#include <iostream>
#include <map>
#include "tariff.h"

void printBill(double units, Tariff belowThres, Tariff aboveThres)
{

}

int main(void)
{
    Tariff belowThres("belowThres.dat");
    Tariff aboveThres("aboveThres.dat");
    
    belowThres.readKVpairs();
    aboveThres.readKVpairs();

    double units;
    double totalBill = 0.0;
    std::cout<<"Enter unit consumption (2 months): ";
    std::cin>>units;

    if(units <=500.0)
    {
        double diff;
        int prevKey = 0;
        for(const auto& [key, value] : belowThres.pair())
        {
            if(prevKey < units)
            {
                diff = units - prevKey;
                totalBill = totalBill + value * diff;
                prevKey = key;
            }
            else
            break;
        }
    }
    else
    {
        double diff;
        int prevKey = 0;
        for(const auto& [key, value] : aboveThres.pair())
        {
            if(prevKey < units)
            {
                diff = units - prevKey;
                totalBill = totalBill + value * diff;
                prevKey = key;
            }
        }
    }
    std::cout<<"Bill is "<<totalBill;
}