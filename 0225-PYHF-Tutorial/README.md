This instruction is for running a jupyter-notebook on a gpvm. 
The same instruction applied for running on a local machine, however, no forwarding port is needed.

## 1. Setup PYTHON Environment
https://sbnsoftware.github.io/SBNYoung/Python.html

## 2. Install the necessary package in your environment

`which python`

`pip install --upgrade pip`

`pip install wheel setuptools`

`pip install -r requirements.txt`

## 3. Launch the jupyter-notebook from gpvm

### On sbndgpvm 
`jupyter-notebook --no-browser`

Make note of the port in the launch message, for example, it is 8888

```bash
    To access the notebook, open this file in a browser:                              
        file:///nashome/l/lnguyen/.local/share/jupyter/runtime/nbserver-656-open.html 
    Or copy and paste one of these URLs:                                              
        http://localhost:8888/?token=ddedb625c1117e8886b6e8c2075a29f82d434494f4a66cce 
     or http://127.0.0.1:8888/?token=ddedb625c1117e8886b6e8c2075a29f82d434494f4a66cce 

```

### From the local machine

- `ssh sbndgpvm<00> -L <port>:localhost:<host>`
- Open the url on any web browsers
