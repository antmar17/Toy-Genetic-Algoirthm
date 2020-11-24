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
using namespace std;

//produce a number between -100 and 100 aka a gene
double randomDouble(){
  //have to seed in time to ACTUALLY make it random
  double f=(rand()/(double)RAND_MAX);

  return f * 200 - 100;

}
vector<double> makeGenes(int maxGenes){
  vector<double> animal;
  cout<<"[";
  for(int i=0;i<maxGenes;i++){
    double random=randomDouble();
    animal.push_back(random);
    cout<<random<<",";
  }
  cout<<"]"<<endl;

  //cast to pointer to double
  return animal;



}


template<typename T>bool comparator( pair<T,double> p1,pair<T,double> p2){
  return p1.second < p2.second;
}

bool x( pair<char,double> p1,pair<char,double> p2){
  return p1.second < p2.second;
}





//the geneticAlgorithm will take two functions in which we will define depending on what we want to use the algorithm for :
//The incubator: takes a double* and returns a Generic Type
//The costFunction:take a GenericType and convert it to a double to represent it's cost(how wrong it is)

int operation2(int x, int y,std::function<int(int, int)> function){return function(x,y);}


template <typename T> T geneticAlg(std::function<T(vector<double>)>incubator, std::function<double(T)>costFunction,int maxGenes,int maxGnerations){ 
  //function ptr for sorting of map
  

  //maps animal->cost 
  std::vector<pair<T,double>> generation;
  int genCount=0;
  
  T bestAnimal;
  double bestCost;
  

  //have to seed in time to ACTUALLY make it random
  srand(time(0));

  //make inital generation
  for(int i=0;i<10;i++){
    cout<<"animal: "<<i<<endl;
    
    //genes of animal
    vector<double> genes=makeGenes(maxGenes);
    
    
    T animal=incubator(genes);
    double cost=costFunction(animal);
     
    //get animal and cost 
    pair<T,double> p;
    p.first=animal;
    p.second=cost;

    generation.push_back(p);

  }

  //sort the generation
  sort(generation.begin(),generation.end(),comparator);
  
  
  bestAnimal=generation.begin().first;
  bestCost=generation.begin().second;

while(bestCost < 0.01 && genCount < 1000){

//TODO: set up mutation and logic to make more generations!


}



  return incubator(generation.begin()->second);

}


int main(){
  
   vector<pair<char,double>> pV;
   pair<char,double> one;
  one.first='b';
  one.second=10.0;

  pair<char,double> two;
  two.first='a';
  two.second=20.0;


   pV.push_back(one);
   pV.push_back(two);


   std :: sort(pV.begin(),pV.end(),x);








  return 0;
}



//template<typename name>ret_type func_name(paramaters){




//function body...
//}







