def InFV(x, y, z): # cm
    xmin = -199.15 + 10
    ymin = -200. + 10
    zmin = 0.0 + 10
    xmax = 199.15 - 10
    ymax =  200. - 10
    zmax =  500. - 50
    
    return (x > xmin) & (x < xmax) & (y > ymin) & (y < ymax) & (z > zmin) & (z < zmax)
