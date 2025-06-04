---------------------------------
READUME ON THE MODIFIED VERSION
---------------------------------
This version is build on the Gromacs 2021.4.
This modification enable us to join multiple belly simulations to each other using several quasi-static steps. The details and concepts of this programs can be found at
https://doi.org/10.1063/5.0241914
also,
https://arxiv.org/abs/2409.17028
.

In order to conduct the belly simulations continuously, We added some options of gmx-mdrun.
The below is the description of the useage.
1, Prepare a trr file including the target solute conformations.
2, Set the solute to the Freeze group in the mdp file.
3, Prepare as usual with gmx-grompp.
4, Run gmx-mdrun as follows:

example: gmx mdrun -deffnm test -readcf fit.trr -writers res.trr -nstepsinner 100 -qfacter 5000 -nsteps 10000 -ncfskip 100

-readcf <trr file>
This option set the name of the trr file including the target solute conformations.
The initial and target solute conformations should be superimposed in advance.
If the directions of those structure are different from each other, the solute structure may be crashed once, which lead to the crash of MD simulation.

-writers <trr file>
This option set the name of the trr file including the results of $f_{ano}^i$.

-nstepsinner <int>
This option set the $n_{prd}$ to <int>.

-qfacter <int>
This option set the $n_{buffer}$ to <int>.

-nsteps <int>
This option set the number of frames of the target solute conformation.

-ncfskip <int>
This option can skip <int> frames of the target solute conformation.
This is optional.

※The above options can only be used with the leap-frog algorithm (velocity Verlet is not supported). They also cannot be used with MPI parallelization that employs domain decomposition.

5, You can get the result from the "res.trr" whose name can be changed by the option -writers.

This program does not conduct the correction expressed by Eq. S1 (See Suporting material in https://arxiv.org/abs/2409.17028). You should apply the correction later. Also, you must projection the results to the target solute conformation in the original direction if you conducted the superimposing of the initial and target solute conformations.



---------------------------------
READUME ON THE OFICIAL VERSION
---------------------------------

               Welcome to the official version of GROMACS!

If you are familiar with Unix, it should be fairly trivial to compile and
install GROMACS. GROMACS uses only the CMake build sytem, and our
installation guide can be found at
http://manual.gromacs.org/documentation/current/install-guide/index.html

Of course we will do our utmost to help you with any problems, but PLEASE 
READ THE INSTALLATION INSTRUCTIONS BEFORE CONTACTING US!

There are also several other online resources available from the homepage, 
and special information for developers.

If you are a developer, or change the source for any other reason, check
out http://www.gromacs.org/Developer_Zone.

                               * * * * *

GROMACS is free software, distributed under the GNU Lesser General
Public License, version 2.1 However, scientific software is a little
special compared to most other programs. Both you, we, and all other
GROMACS users depend on the quality of the code, and when we find bugs
(every piece of software has them) it is crucial that we can correct
it and say that it was fixed in version X of the file or package
release. For the same reason, it is important that you can reproduce
other people's result from a certain GROMACS version.

The easiest way to avoid this kind of problems is to get your modifications
included in the main distribution. We'll be happy to consider any decent 
code. If it's a separate program it can probably be included in the contrib 
directory straight away (not supported by us), but for major changes in the 
main code we appreciate if you first test that it works with (and without) 
MPI, threads, double precision, etc.

If you still want to distribute a modified version or use part of GROMACS
in your own program, remember that the entire project must be licensed
according to the requirements of the LGPL v2.1 license under which you
received this copy of GROMACS. We request that it must clearly be labeled as
derived work. It should not use the name "official GROMACS", and make
sure support questions are directed to you instead of the GROMACS developers.
Sorry for the hard wording, but it is meant to protect YOUR reseach results!

                               * * * * *

The development of GROMACS is mainly funded by academic research grants. 
To help us fund development, we humbly ask that you cite the GROMACS papers:

* GROMACS: A message-passing parallel molecular dynamics implementation
  H.J.C. Berendsen, D. van der Spoel and R. van Drunen
  Comp. Phys. Comm. 91, 43-56 (1995)
  DOI: https://doi.org/10.1016/0010-4655(95)00042-E
 
* GROMACS 4: Algorithms for highly efficient, load-balanced, and scalable
  molecular simulation
  B. Hess and C. Kutzner and D. van der Spoel and E. Lindahl
  J. Chem. Theory Comput. 4 (2008) pp. 435-447
  DOI: https://doi.org/10.1021/ct700301q

* GROMACS 4.5: a high-throughput and highly parallel open source
  molecular simulation toolkit
  Sander Pronk, Szilárd Páll, Roland Schulz, Per Larsson, Pär Bjelkmar,
  Rossen Apostolov, Michael R. Shirts, Jeremy C. Smith, Peter M. Kasson,
  David van der Spoel, Berk Hess, Erik Lindahl.
  Bioinformatics 29 (2013) pp. 845-54
  DOI: https://doi.org/10.1093/bioinformatics/btt055

* Tackling Exascale Software Challenges in Molecular Dynamics Simulations
  with GROMACS
  Szilárd Páll, Mark J. Abraham, Carsten Kutzner, Berk Hess, Erik Lindahl
  In S. Markidis & E. Laure (Eds.), Solving Software Challenges for Exascale,
  Lecture Notes for Computer Science, 8759 (2015) pp. 3–27
  DOI: https://doi.org/10.1007/978-3-319-15976-8_1

* GROMACS: High performance molecular simulations through multi-level parallelism from laptops to supercomputers
  M. J. Abraham, T. Murtola, R. Schulz, S. Páll, J. C. Smith, B. Hess, E. Lindahl,
  SoftwareX, 1, (2015), 19-25
  DOI: https://doi.org/10.1016/j.softx.2015.06.001

There are a lot of cool features we'd like to include in future versions,
but our resources are limited. All kinds of donations are welcome, both in 
form of code, hardware and funding! Industrial users who choose to pay
for a license pro bono (it is still LGPL and can be redistributed freely) or
contribute in other ways are listed as GROMACS supporters on our webpages. 
Don't hesitate to contact us if you are interested.


                       Good luck with your simulations!

                              The GROMACS Crew
