# Data-Lib
Simple data structures implementation for a college assignment.

## Generic Type
The libraries are generic. For example, to create a string stack with the max size of 5, do the following:

```c++
Stack<string> strStack = Stack<string>(5);
```

Note that you need to add explicit type compilation at the end of the library source and your code.

```c++
// Explicit instantiations of all the templates used in the file
template
class Stack<std::string>;
```

## Stack-Lib
A very simple C++ Stack Library implementation.

The **stdout output** from stackdemo executable is:

![Failed to load the image!](https://i.imgur.com/wvOT8ub.png "STDOUT")

## Queue-Lib
A very simple C++ Queue Library implementation.

The **stdout output** from queuedemo executable is:

![Failed to load the image!](https://i.imgur.com/8xNQRsr.png "STDOUT")

## List-Lib
A very simple C++ List Library implementation.

The **stdout output** from listdemo executable is:

![Failed to load the image!](https://i.imgur.com/hT2Ui9p.png "STDOUT")
