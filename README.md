### Here was what we were given as an assignment:
 
_Write a program that uses a genetic algorithm to find a function that approximates the buddabrot set from the first assignment.  Include a short report on the experience.  This report must include a comparison of the image produced by your genetic algorithm and the image produced by the first assignment._

 

_The genetic algorithm must include, mutation, crossover and migration between populations that are simulated on separate compute nodes._

It wasn't very detailed but I think I accomplished all the genetic algorithm features.

I got this running locally  but never finished setting up MPI to run on the schools Beowolf Cluster.




Genetic Algorithm
=======

The basic idea is:

* Initialization - Create an initial population, this population is usually generated randomly and can be any size desired, from just a few individuals to thousands.

* Evaluation - Each member of the population is then evaluated and we calculate a 'fitness' for that individual. The fitness is calculated by how well it fits our desired requirements. These requirements can be simple, 'faster algorithms are better', or more complex, 'stronger materials are better but they shouldn't be too heavy'.

* Selection - We want to be constantly improving our populations overall fitness, selection helps us discard bad designs and only keep the best individuals.  There are a few different selection methods but the basic idea is the same, make it easier for fitter individuals to be selected for our next generation.

* Crossover - During crossover we create new individuals by creating crosses of our selected individuals, we call these our parents. The idea is the combination of these parents will create an even 'fitter' offspring for our next population which inherits the best bits of both individuals.

* Mutation - We need to add a little bit randomness into our populations' genetics otherwise every combination of solutions we can create would be in our initial population.

* And repeat! - Now we have our next generation we can start again from step two.

 __http://www.theprojectspot.com/tutorial-post/creating-a-genetic-algorithm-for-beginners/3__
 
