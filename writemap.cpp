//Program to read and write tariff into .dat files
#include "tariff.h"

int main(void)
{
    Tariff belowThres("belowThres.dat");
    Tariff aboveThres("aboveThres.dat");

    std::cout<<"Enter option: 1 - read slab, 2 - write slab: ";
    int n;
    std::cin>>n;
    if(n == 1)
    {
        belowThres.readKVpairs();
        aboveThres.readKVpairs();
        std::cout<<"Below 500 units slab:\n";
        belowThres.displaySlab();
        std::cout<<"Above 500 units slab:\n";
        aboveThres.displaySlab();
    }
    else if(n == 2)
    {
        belowThres.modifySlab();
        aboveThres.modifySlab();
        belowThres.writeKVpairs();
        aboveThres.writeKVpairs();
    }
    else
        std::cout<<"Invalid choice!";
}