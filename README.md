<p align="center">
  <div align="center">
   <img src="assets/Fillit_graph.png" width="500px"</img><br>
    <em><i>I'll never play Tetris again...</i></em>
  </div>
</p>

# Fillit

The goal for this project is to create an executable that takes only one parameter- an input file which contains a list of Tetriminos to assemble. 

<p align="center">
  <div align="center">
   <img src="https://github.com/micriver/42_fillit/blob/master/assets/sample%20input%20file.png" width="520px"</img><br>
  </div>
</p>

The algorithm must arrange the Tetriminos into the smallest possible square, keeping the given order from the input file.

<p align="center">
  <div align="center">
   <img src="assets/sample_fillit_output.png" width="800px"</img><br>
  </div>
</p>

**Project Document:**
[Fillit.pdf](https://github.com/micriver/get_next_line/blob/master/docs/get_next_line.en.pdf)

During the project, I worked even more with pointers and 2D arrays. I was exposed to various algorithmic concepts, backtracking and recursive functions. Writing Fillit to the norm forced me to practice with new, optimized C language syntax.

All functions were written according to 42's coding standard,
[the Norm](https://github.com/micriver/docs/norme.en%20.pdf).


## Installation

Download the repository by copying and pasting the commands below.

You can compile the ```fillit``` executable using the Makefile:

Command       |  Action
:-------------|:-------------
`make`        | Compile the ```fillit``` executable.
`make clean`  | Remove object files.
`make fclean` | Remove object files and the executable.
`make re`     | Re-compile the ```fillit``` executable.

## Usage

After compilation, you can run the ```./fillit``` executable with one of the valid input files from ```samples/valid_samples/```.

