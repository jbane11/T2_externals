# coding: utf-8
import pandas as pd
import matplotlib.pyplot as plt
import numpy as py
table1= pd.read_table('OUT/marathon_kin1_D2.out',delim_whitespace=True)
table3= pd.read_table('OUT/marathon_kin3_D2.out',delim_whitespace=True)
table5= pd.read_table('OUT/marathon_kin5_D2.out',delim_whitespace=True)
table7= pd.read_table('OUT/marathon_kin7_D2.out',delim_whitespace=True)
table9= pd.read_table('OUT/marathon_kin9_D2.out',delim_whitespace=True)
table11= pd.read_table('OUT/marathon_kin11_D2.out',delim_whitespace=True)
tb_L=[table1,table3,table5,table7,table9,table11]
table=pd.concat(tb_L)
table.plot(x='Theta',y='Sig_Born')
plt.show()
