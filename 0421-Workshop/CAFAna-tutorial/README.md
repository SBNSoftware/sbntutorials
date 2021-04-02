 # April 2021 Workshop: Doing CAF Analysis with CAFAna

 This repository contains several example CAFAna macros designed to demonstrate many of the capabilities of CAFAna. In order to run these we need to set up CAFAna from the UPS product on CVMFS, there are scripts provided to do this.

 Once these scripts have been sourced and everything is set up, running the scripts is just like running a ROOT macro but replacing `root` with `cafe`. E.g.:

 ```cafe Intro.C```

 There are many options to run alongside `cafe` that can be found by running `cafe --help`. Most commonly used are `-b` to run in batch mode (without graphics) and -q to quit after the macro is finished running, or combine these options by running `-bq`.
