//Tariff class
#ifndef TARIFF_H
#define TARIFF_H
#include <fstream>
#include <iostream>
#include <map>
class Tariff
{
    std::map<int, double> rateSlabs;
    std::string filename;
    public:

    Tariff(std::string fname)
    {
        std::ofstream fout;
        filename = fname;
        fout.open(fname, std::ios::app);
        fout.close();
    }
    void modifySlab()
    {
        int n;
        int slabUp;
        double slabUnits;
        std::cout<<"Enter number of slabs: ";
        std::cin>>n;
        for(int i = 0; i < n; i++)
        {
            std::cout<<"Enter upper limit of slab";
            std::cin>>slabUp;
            std::cout<<"Enter rate per unit of slab: ";
            std::cin>> slabUnits;
            rateSlabs[slabUp] = slabUnits;
        }
    }
    void displaySlab()
    {
        for(const auto& [key, val] : rateSlabs)
        {
            std::cout<<key<<"\t"<<val<<std::endl;
        }
    }
    void readKVpairs()
    {
        std::ifstream fin;
        fin.open(filename);
        int upperLim;
        double rate;
        while(fin >> upperLim >> rate)
        {
            rateSlabs[upperLim] = rate;
        }
        fin.close();
    }
    void writeKVpairs()
    {
        std::ofstream fout;
        fout.open(filename);
        for(const auto& [key, val] : rateSlabs)
        {
            fout<<key<<" "<<val<<"\n";
        }
        fout.close();
    }

    std::map<int, double> pair()
    {
        return rateSlabs;
    }
};

#endif