# Workshop 9
# Function Templates
In this workshop, you code a template to add the value of one object to another.

##Learning Outcomes
Upon successful completion of this workshop, you will have demonstrated your abilities to
* code a function template
* code an explicit specialization for a function template

## the addTo Function.
Consider the following fucntion:
```cpp
void addTo(int* a, const int *b){
  *a += *b;
}
```
This function adds the value of the integer pointed by **b** to the integer pointed by **a**.<br />
## The addTo template
Convert the **addTo** function in **add.h** to add the value of any object to another, assuming the object can work with operator+=.
Download the **W91** repository to your computer and complete the code int the **add.h** file:
### The general addTo Template
Complete the code to have a template called **addTo**, that receives the address of any object and a constant address of the same type of object and adds the value of the target of the second argument to the target of the first argument.
### The explicit specialization addTo template for type char:
Modify the code in **add.h** to have an explicit definition for the template **addTo** that handles char pointers and returns the concatenation result of the second argument to the first one.
## The output
After compilation of the code in **add.h** with **w9.cpp** the output of the executable should be:
```
30
3.5
Checking account balance: $3000.00
Homer Jay Simpson
```
## submission. 
copy **add.h** and **w9.cpp** to your matrix account and execute the following command:
```
~fardad.soleimanloo/submit_ws9
```
### Due date: 
Monday Apr 20th, 23:59. <br />
Submission of the workshop is **optional** but if you submit it, the mark of this workshop will replace the worst mark in the past 8 workshops. 
<br />**Or better to say; best 8 marks of the 9 workshops will be picked.**

