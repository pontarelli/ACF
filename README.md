# ACF

This is the repository for the Adaptive Cuckoo Filter simulator code presented in the 2018 Proceedings of the Twentieth Workshop on Algorithm Engineering and Experiments (ALENEX). The paper is available [here](https://epubs.siam.org/doi/pdf/10.1137/1.9781611975055.4).
The code also includes an extension that use fingerprints with different ranges, described in and extended version of the paper that is under submission at the ACM Journal of Experimental Algorithmics (JEA).     

# Getting Started

The simulator has been developed on Ubuntu 12.04. Other distributions or versions may need different steps.

# Building

Run the following commands in the ACF directory to build everything:

```
$ make
```

# Running

There are two executables for the ACF:

1. acf2x4
    This executable investigates the false positive rate achievable with the ACF for buckets with multiple cells. The code has been configured with 2 tables and 4 cells for bucket. The executable options can be retrieved running:

```
$ ./acf2x4 -h 
```
    

2. acf4x1

    This executable investigates the false positive rate achievable with the ACF for buckets with one cell. The code has been configured with 4 tables and 1 cell for bucket. The executable options can be retrieved running:

```
$ ./acf4x1 -h 
```


# Example

The aim of the simulator is to evaluate the false positive rate of different ACF configurations.
The following example runs 10 iterations of an ACF with 4 tables and 1 cell for bucket loaded up to 95%. Each table contains 128 buckets, the number of fingerprint bits is 16, the number of selector bits is 2 and the skewness factor is 1.
The simulator sends 1000 packets for each flow (in random order) and considers that the ratio A/S between the stored flows S and the active flows A is 100.

```
$ ./acf4x1 -l 10  -L 95 -m 128 -f 16 -b 2 -k 1 -n 1000 -a 100 
```

