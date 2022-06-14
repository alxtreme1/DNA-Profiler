## Summary

- [Introduction](#introduction)
- [How to test](#how-to-test)

## Introduction

This program was made for DNA profile identification of a unknown DNA sequence on a database. Use `-d` argument to load the database file, and `-s` to load the unknown DNA sequence file.

## How to test

First you need to have the `CMAKE` with a C++ compiler to compiler.

You will create the `build folder` on this cloned project folder. You can do it with this command on your terminal:

```
$ mkdir build
```

After, you will compilate with CMAKE with this:

```
$ cmake ..
```
```
$ cmake --build .
```

Now you finally can run with following command to run the program:

```
$ ./dnaprofiler.exe -d data/data.csv -s data/sequence_alice.txt
```