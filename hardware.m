% Turns=2;
%calculated from avg input voltage divided by output voltage
Vo=10;
Vin_min=24;
Vin_max=48;
Eff=0.9;
%efficiency
fs=10^5; %frequency
Po_max=65;
Pin_max=Po_max/Eff;
 Vo_reflected=1.8*Vo;
Io_max=6;
D=0.40;


Lmax= (Vin_min^2*D^2*Eff)/(2*fs*Po_max);

Ipeak= sqrt((2*Po_max)/(0.85*Lmax*fs*Eff));
Ak= 2*Po_max/(Vin_min*D);
Turns= (Vin_min*D)/((1-D)*(Vo+0.8));
%% Mosfet ekleme



%%
Dav=0.5;%purpose is Dav=0.5
Dmin=Vo_reflected/(Vin_max+Vo_reflected);
Dmax=Vo_reflected/(Vin_min+Vo_reflected);
%%
Krf=1; %for DCM
Lm=(Vin_min*D)^2/(2*Pin_max*fs*Krf);%primary inductance

Iin=Pin_max/(Vin_min*D);
I_ripple=Vin_min*D/(Lm*fs);
I_lm_peak=Iin+I_ripple/2;
%rms hesab?na gerek var m?
%%
Vo_ripple=0.04*10;
C_out=Io_max*D/(fs*Vo_ripple);
