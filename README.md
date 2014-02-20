Genetic Algorithm
=======

This is my first attempt at genetic algorithms.  I will be focusing on Mutation, Migration, and Culling


The basic idea is:

* Initialization - Create an initial population, this population is usually generated randomly and can be any size desired, from just a few individuals to thousands.

* Evaluation - Each member of the population is then evaluated and we calculate a 'fitness' for that individual. The fitness is calculated by how well it fits our desired requirements. These requirements can be simple, 'faster algorithms are better', or more complex, 'stronger materials are better but they shouldn't be too heavy'.

* Selection - We want to be constantly improving our populations overall fitness, selection helps us discard bad designs and only keep the best individuals.  There are a few different selection methods but the basic idea is the same, make it easier for fitter individuals to be selected for our next generation.

* Crossover - During crossover we create new individuals by creating crosses of our selected individuals, we call these our parents. The idea is the combination of these parents will create an even 'fitter' offspring for our next population which inherits the best bits of both individuals.

* Mutation - We need to add a little bit randomness into our populations' genetics otherwise every combination of solutions we can create would be in our initial population.

* And repeat! - Now we have our next generation we can start again from step two.

 __http://www.theprojectspot.com/tutorial-post/creating-a-genetic-algorithm-for-beginners/3__