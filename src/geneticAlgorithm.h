#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>
#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;




double randomDouble();
bool comparator( pair<vector<double>,double> p1,pair<vector<double>,double> p2);
void print_vector(vector <double>  a);
void print_generation(vector<pair<vector <double>,double>>  a);
vector<double> mutateGene(vector<double>* gene);
template <typename T> T geneticAlg(std::function<T(vector<double>)>incubator, std::function<double(T)>costFunction,int maxGenes,int maxGenrations);
