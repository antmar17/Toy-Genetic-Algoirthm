#include <algorithm>
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
//the geneticAlgorithm will take two functions in which we will define depending on what we want to use the algorithm for :
//The incubator: takes a double* and returns a Generic Type
//The costFunction:take a GenericType and convert it to a double to represent it's cost(how wrong it is)



template <typename T> T geneticAlg(std::function<T(vector<double>)>incubator, std::function<double(T)>costFunction,int maxGenes,int maxGenrations){ 
  //function ptr for sorting of map


  //maps animal genes ->cost 
  std::vector< pair<vector<double>,double>> generation;

  int genCount=0;
  
  vector<double> bestGenes;
  double bestCost;


  //have to seed in time to ACTUALLY make it random
  srand(time(0));

  //make inital generation
  for(int i=0;i<maxGenrations;i++){

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

    cout<< "Cost: "<<bestCost<<endl;
  //sort the generation
  sort(generation.begin(),generation.end(),comparator);

  //keep track of best genes
  bestGenes=generation[0].first;
  bestCost=generation[0].second;

  while(bestCost < 0.01 && genCount < maxGenrations){

    //get two best 
    while(generation.size() > 2){
      generation.pop_back();
      
    }

    
    //fill generation back up with mutated copies of best animal
    for(int i=2;i<10;i++){
      vector<double> genes;
      //create copy
      for(int e = 0;e<maxGenes;e++){
        genes[e]=bestGenes[e];
      }

      //mutate the copy


      
      //ratio of how many genes to replace in each animal-
      int amountToReplace=floor( (maxGenes*(1/4)));
      
      //generate random index and random numbers
      for (int e=0;e < amountToReplace;e++){
       
        double value=randomDouble();
        int index= rand() % maxGenes;

        genes[index]=value;
      }
      
     pair<vector<double>,double> mutatedPair;
      mutatedPair.first=genes;
      mutatedPair.second=bestCost;

      generation.push_back(mutatedPair);
      
      }
    }
  return incubator(bestGenes);

}

double sampleCostFunc(pair<double,double> head){

  return sqrt(pow( (2 - head.first) , 2) + pow((2 - head.second),2));

}


pair<double,double> sampleIncubator(vector<double> input){
  pair<double,double> ret;
  ret.first=input[0];
  ret.second=input[1];
  return ret;
}
int main(){
  
 pair<double,double> x= geneticAlg<pair<double,double>>(sampleIncubator, sampleCostFunc, 2, 1000);







  return 0;
}



//template<typename name>ret_type func_name(paramaters){




//function body...
//}







