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


//produce a number between -100 and 100 aka a gene
double randomDouble(){
  //have to seed in time to ACTUALLY make it random
  double f=(rand()/(double)RAND_MAX);

  return f * 200 - 100;

}
vector<double> makeGenes(int maxGenes){
  vector<double> animal;
  for(int i=0;i<maxGenes;i++){

    double random=randomDouble();
    animal.push_back(random);

  }

  //cast to pointer to double
  return animal;



}


bool comparator( pair<vector<double>,double> p1,pair<vector<double>,double> p2){
  return p1.second < p2.second;
}


//---Debuggin functions
//print vector
void print_vector(vector <double>  a) {
   std::cout << "[";

   for(int i=0; i < a.size(); i++){
   std::cout << a.at(i) << " , ";
   }

  std::cout<<"]";
}
//print vector
void print_generation(vector<pair<vector <double>,double>>  a) {
   std::cout << "{ "<<endl;

   for(int i=0; i < a.size(); i++){
   std::cout << "{ ";


   print_vector(a.at(i).first);
   std::cout <<", " <<a.at(i).second << " } "<<endl;
   }

  std::cout<<" } "<<endl;
}
//---Debuggin functions

vector<double> mutateGene(vector<double>* gene){

  vector<double>newVector=*gene;
  
  int amountToReplace=ceil(newVector.size()*.25);
  //copy over overctor





  //generate random index and random numbers
  for (int e=0;e < amountToReplace;e++){

    double value=randomDouble();
    int index= rand() % newVector.size();

    newVector[index]=value;
  }

  return newVector;


}
//the geneticAlgorithm will take two functions in which we will define depending on what we want to use the algorithm for :
//The incubator: takes a double* and returns a Generic Type
//The costFunction:take a GenericType and convert it to a double to represent it's cost(how wrong it is)
template <typename T> T geneticAlg(std::function<T(vector<double>)>incubator, std::function<double(T)>costFunction,int maxGenes,int maxGenrations){ 
  //function ptr for sorting of map

  //maps animal genes ->cost 
  std::vector< pair<vector<double>,double>> generation;

  int genCount=1;
  
  vector<double> bestGenes;
  double bestCost;


  //have to seed in time to ACTUALLY make it random
  srand(time(0));
  //make inital generation
  
  for(int i=0;i<10;i++){

    //genes of animal
    vector<double> genes=makeGenes(maxGenes);

    T animal=incubator(genes);
    double cost=costFunction(animal);

    //get animal genes and cost 
    pair<vector<double>,double> p;
    p.first=genes;
    p.second=cost;
    generation.push_back(p);


  }
  
  //sort the generation
  sort(generation.begin(),generation.end(),comparator);

  //keep track of best genes
  bestGenes=generation[0].first;
  bestCost=generation[0].second;

  cout<<"inital generation"<<endl;
  print_generation(generation);

  while(bestCost > 0.01 && genCount < maxGenrations){
    srand(time(0)+genCount);
    //get two best 
    while(generation.size() > 2){
      generation.pop_back();

    }
    //fill generation back up with mutate copies of best animal
    for(int i=2;i<10;i++){
      vector<double> genes=mutateGene(&bestGenes);


      pair<vector<double>,double> mutatedPair;
      mutatedPair.first=genes;
      mutatedPair.second=costFunction(incubator(genes));

      generation.push_back(mutatedPair);



    }
    //sort the generation
    sort(generation.begin(),generation.end(),comparator);
    cout<<"mutated generation"<<endl;

    print_generation(generation);


    //keep track of best genes
    bestGenes=generation[0].first;
    bestCost=generation[0].second;
    genCount++;


  }
  cout<<"took: "<<genCount<<" generations"<<endl;
  return incubator(bestGenes);

}

double sampleCostFunc(vector<double> head){

  return sqrt( (pow( (2 - head[0]) , 2)) + (pow((2 - head[1]),2)) );

}


vector<double> sampleIncubator(vector<double> input){
  return input;
}



int main(){

  vector<double> x= geneticAlg<vector<double>>(sampleIncubator, sampleCostFunc, 2, 1000);

  cout << "("<<x[0]<<","<< x[1] <<")"<< endl;


  vector<double> y;
  y.push_back(2.0);
  y.push_back(2.0);
  vector<double> z=mutateGene(&y);


  print_vector(z);
  return 0;
}



//template<typename name>ret_type func_name(paramaters){




//function body...
//}







