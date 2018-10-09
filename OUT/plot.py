import pandas as pd
import matplotlib.pyplot as plt
import os,sys
import glob
import matplotlib._color_data as mcd
overlap = [name for name in mcd.CSS4_COLORS if "xkcd:" + name in mcd.XKCD_COLORS]
tgt='He3'
search = './marathon_kin*_{}.out'.format(tgt)
files=glob.glob(search)
kins={}
i=0

for j in range(1,len(files),1):
    file=files[i]
    print(file)
    kins[i]=pd.read_table(file,delim_whitespace=True)
    xkcd = mcd.XKCD_COLORS["xkcd:" + overlap[j]].upper()
    xkcd1 = mcd.XKCD_COLORS["xkcd:" + overlap[j]].upper()
    lab=file.replace('./marathon_','')
    lab=lab.replace('.out','')
    lab1=lab+'_rad'
    if i == 0:
        ax=kins[i].loc[kins[i]['Eprime']==3.102].plot(x='Theta',y='Sig_Born',kind='scatter',color=xkcd,label=lab)
    else :
        kins[i].loc[kins[i]['Eprime']==3.102].plot(ax=ax,x='Theta',y='Sig_Born',kind='scatter',color=xkcd,label=lab)
    kins[i].loc[kins[i]['Eprime']==3.102].plot(ax=ax,x='Theta',y='Sig_Rad',kind='scatter',color=xkcd1,label=lab1,marker='v')
    i=i+1
    plt.grid(True)
    
XEMC={}
XEMC[0]=pd.read_table('./xemc_1.dat',delim_whitespace=True)
XEMC[0]["Sig_Born"] = XEMC[0]["Sig_Born"]/100.0
XEMC[0]["Sig_Rad"] = XEMC[0]["Sig_Rad"]/100.0
#XEMC[0].plot(ax=ax,x='Theta',y='Sig_Born',kind='scatter',color='r',label='XEMC', marker='D')
#XEMC[0].plot(ax=ax,x='Theta',y='Sig_Rad',kind='scatter',color='r',label='XEMC_r', marker='D')
plt.grid(True)
