import uproot
import pandas as pd

folderE = "caloskimE"
folderW = "caloskimW"
folder = "caloskim"
tname = "TrackCaloSkim"

def _makedf(dfs):
    if not isinstance(dfs, tuple):
        assert(isinstance(dfs, pd.DataFrame))
        dfs = [dfs]
    else:
        dfs = list(dfs)

    npad = [max([len(b.split(".")) for b in df.columns]) for df in dfs]
    def pad(b, i):
        while len(b) < npad[i]:
            b.append("")
        return tuple(b)

    for i in range(len(dfs)):
        dfs[i].columns = pd.MultiIndex.from_tuples([pad(b.split("."), i) for b in dfs[i].columns])

    # set the index name if not present
    for i in range(len(dfs)):
        if len(dfs[i].index.names) == 1 and dfs[i].index.names[0] is None:
            dfs[i].index = dfs[i].index.set_names(["entry"])

    return dfs

def loaddf_icarus(fname, branches):
    with uproot.open(fname) as f:
        try:
            dfW = f[folderW][tname].arrays(branches, library="pd")
            dfE = f[folderE][tname].arrays(branches, library="pd")
        except Exception as e:
            print("Could not open file (%s) due to exception." % fname)
            print(e)
            return None

        dfW = _makedf(dfW)
        dfE = _makedf(dfE)

    for i in range(len(dfW)):
        dfW[i] = dfW[i].append(dfE)

    if len(dfW) == 1:
        return dfW[0]
    
    return dfW

def loaddf_sbnd(fname, branches):
    with uproot.open(fname) as f:
        try:
            df = f[folder][tname].arrays(branches, library="pd")
        except Exception as e:
            print("Could not open file (%s) due to exception." % fname)
            print(e)
            return None

        df = _makedf(df)
        
    return df
