# April 2021 Workshop: Doing CAF Analysis with Python

This repository contains information to do event selection type analyses using the CAF files as input. We only need python libraries to do this: **no C++**, **no ROOT**, **no art**, **no LArSoft**. This is very helpful for iterating quickly on analysis and also enables work to be done off the FNAL servers. 

We will be using the following python packages:

<img src="https://raw.githubusercontent.com/scikit-hep/uproot4/main/docs-img/logo/logo-300px.png" alt="uproot" width="100">

[**uproot**](http://github.com/scikit-hep/uproot4) For opening ROOT files (pure python library!)

<img src="https://camo.githubusercontent.com/981d48e57e23a4907cebc4eb481799b5882595ea978261f22a3e131dcd6ebee6/68747470733a2f2f70616e6461732e7079646174612e6f72672f7374617469632f696d672f70616e6461732e737667" alt="pandas" width="100">

[**pandas**](https://github.com/pandas-dev/pandas) For data management.

<img src="https://raw.githubusercontent.com/numpy/numpy/main/branding/logo/primary/numpylogo.svg" alt="numpy" width="100">

[**numpy**](https://github.com/numpy/numpy) For doing math stuff.

<img src="https://www.scipy.org/_static/images/scipy_med.png" alt="scipy" width="100">

[**scipy**](https://github.com/scipy/scipy) For doing more math stuff.

<img src="https://matplotlib.org/_static/logo2_compressed.svg" alt="matplotlib" width="100">

[**matplotlib**](https://github.com/matplotlib/matplotlib) For making plots.

<img src="https://jupyter.org/assets/main-logo.svg" alt="jupyter" width="100">

[**jupyter notebook**](https://github.com/jupyter/notebook) For running code.


## How to Install

To install the python packages you will need **python 3**, **pip**, and **virtualenv**. I have scripts in this repository for getting this setup on the FNAL servers. If you are installing on your own machine, and are not sure if you have the required stuff, see: https://packaging.python.org/guides/installing-using-pip-and-virtual-environments/.

Then, run:

```
# ON FNAL: run the proper setup script: setup_sbnd.sh or setup_icarus.sh
# clone this repository:
git clone https://github.com/gputnam/SBN-Workshop-0421.git
# make a virtualenv
virtualenv env
# NOTE: on the FNAL servers the default virtualenv is broken. Instead, I have one on pnfs persistent. So run:
/pnfs/sbn/persistent/users/gputnam/virtualenv-15.1.0/virtualenv.py env
# Active the virtualenv
source env/bin/activate
# Install the python dependencies
pip install -r requirements.txt
```

## How to Run

In a terminal with the activated virtual environment, run:

```jupyter notebook --no-browser```

And open the link that is printed in a web browser. If you are running jupyter notebook on a FNAL machine, you will need to 
forward it to your local machine. To do this, ssh into the FNAL server with the flag:

```-L <port>:localhost:<port>```

Where ```<port>``` is the port that jupyter notebook opens with. By default, it is 8888.

Then, open **Demo.ipynb** on the file browser.
