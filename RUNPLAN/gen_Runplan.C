#include "/home/jbane/headers/inc1.h"


void gen_Runplan(int set_all =1, double E_c=10.589,double Ep_c=3.1, 
		 double theta_c = 12.5890, string kin="", int debug=1)
{
	////////////////////////
	//Set all center values;
	////////////////////////
	if(set_all){
		cout <<"Please enter the central E in (GeV)("<<E_c<<")  ";
		cin >> E_c;
		cout<<endl;

		cout <<"Please enter the central E_p in (GeV)("<<Ep_c<<")  ";
		cin >> Ep_c;
		cout<<endl;

		cout <<"Please enter the central theta in (degrees)("<<theta_c<<")  ";
		cin >> theta_c;
		cout<<endl;

		cout <<"Please enter the kin name (Example: kin5)"<<endl;
		cin >>kin;
	}
	//Step size!!!
	double theta_step	=0.1;
	double Ep_step		=0.01;
	double E_step		=0.001;
	//Limits for kins: acceptance of HRS (+- 
	double th_min = theta_c - 1.6; //degrees
	double th_max = theta_c + 1.6; //degrees
	double Ep_min = (0.95)*Ep_c;
	double Ep_max = (1.05)*Ep_c;
	double E_max = E_c; //Just one value for E as of now.
	double E_min = E_c;
	
	double Ep	=0.0;
	double theta	=0.0;
	
	FILE *output= fopen(Form("marathon_%s.inp",kin.c_str()),"w");
	
	fprintf(output,"RUNPLAN for MARATHON\n"	);
	fprintf(output,"%s\n\n\n\n",kin.c_str()		);

	fprintf(output,"   E     Ep    theta     W     y     x      Q2 \n");
	
	for(Ep=Ep_min; Ep<=Ep_max; Ep=Ep+Ep_step){
		theta=th_min;
		for(theta=th_min;theta<=th_max; theta=theta+theta_step){
			fprintf(output,"%2.3f %2.4f %2.4f\n",E_c,Ep,theta);	
		}//end of theta loop
	}//end of ep loop
	fclose(output);

}//end of code		




 
