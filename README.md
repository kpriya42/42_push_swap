*This project has been created as part of the 42 curriculum by kri- and meqian* <br/>

# push_swap project

## Description

Pushswap description

### Simple Algo - Insertion based sort
A classical linked-list insertion sort is:
```
take element
find insertion point
insert
```
The equivalent algorithm used for push_swap is 
```
take element from B
find insertion point in A
rotate or reverse-rotate - which ever is minimum path
insert with pa
```
The key optimization is:

* Usage of circular ordering.
* Always choosing the cheapest element from B.
* Merging rotations (ra,rb and rra,rrb) using rr and rrr.

### Medium Algo

### Complex Algo

### Adative stratergy

## Instructions


### How to compile library:

Makefile has 4 main options:<br/>
* **make** - to compile C files - create object files and binaries<br/>
* **make clean** - to remove object files<br/>
* **make fclean** - remove binaries libraries and object file<br/>
* **make re** - recompile the library<br/>

## Resources

### Testing


### Learning Materials


### Notes
The library follows 42 School norm standards<br/>
