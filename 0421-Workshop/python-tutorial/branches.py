mcbranches = [
    "rec.mc.nu.E",
    "rec.mc.nu.position.x",
    "rec.mc.nu.position.y",
    "rec.mc.nu.position.z",
    "rec.mc.nu.pdg",
    "rec.mc.nu.iscc"
]


trueparticlenames = [
    "start_process",
    "pdg",
    "startE",
    "start.x", "start.y", "start.z",
    "genp.x", "genp.y", "genp.z",
    "length",
    "G4ID",
    "cont_tpc",
    "genE",
    "plane.1.2.visE",
]


trkbranches = [
    "rec.slc.reco.trk.pfp.parent_is_primary",
    "rec.slc.reco.trk.pfp.slcID",
    "rec.slc.reco.trk.pfp.parent",
    "rec.slc.reco.trk.ID",
    "rec.slc.reco.trk.producer",
    "rec.slc.reco.trk.start.x", "rec.slc.reco.trk.start.y", "rec.slc.reco.trk.start.z",
    "rec.slc.reco.trk.end.x", "rec.slc.reco.trk.end.y", "rec.slc.reco.trk.end.z",
    "rec.slc.reco.trk.dir.x", "rec.slc.reco.trk.dir.y", "rec.slc.reco.trk.dir.z",
    "rec.slc.reco.trk.chi2pid.2.chi2_muon",
    "rec.slc.reco.trk.chi2pid.2.chi2_proton",
    "rec.slc.reco.trk.len",
    "rec.slc.reco.trk.rangeP.p_muon",
    "rec.slc.reco.trk.mcsP.fwdP_muon",
    "rec.slc.reco.trk.rangeP.p_pion",
    "rec.slc.reco.trk.mcsP.fwdP_pion",
    "rec.slc.reco.trk.bestplane",
]

for n in trueparticlenames: trkbranches.append("rec.slc.reco.trk.truth.p." + n)

slcbranches = [
    "rec.slc.charge",
    "rec.slc.vertex.x", "rec.slc.vertex.y", "rec.slc.vertex.z",
    "rec.slc.self",
    "rec.slc.tmatch.eff",
    "rec.slc.tmatch.pur",
    "rec.slc.tmatch.index",
    "rec.slc.producer",
    "rec.slc.nu_score",
]

