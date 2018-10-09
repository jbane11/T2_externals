
void newplan()
{
	//Step size!!!
	double theta_step	=0.0;
	double Ep_step		=0.025;
	double E_step		=0.001;
	//Limits for kins: acceptance of HRS (+- 
	double th_min = 15;  //degrees
	double th_max = 16; //degrees
	double Ep_min = 0;
	double Ep_max = 10.2;//(1.08)*Ep_c;
	double E_max = 10.6; //Just one value for E as of now.
	double E_min = 10.6;
	
	double Ep	=0.0;
	double theta	=0.0;
	
	FILE *output= fopen("contheta.inp","w");
	
	fprintf(output,"RUNPLAN for MARATHON\n"	);
	fprintf(output,"%s\n\n\n\n","contheta");

	fprintf(output,"   E     Ep    theta     W     y     x      Q2 \n");
	
	for(Ep=Ep_min; Ep<=Ep_max; Ep=Ep+Ep_step){
			theta=16.0;
			fprintf(output,"%2.3f %2.4f %2.4f\n",10.6,Ep,theta);	
	}//end of ep loop
	fclose(output);

}//end of code		




 
