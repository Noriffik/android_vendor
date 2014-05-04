srconv4_3;
fc=1000;
fs=12000;
T=1/fs;
checkdisto=0;

if (checkdisto==0)
    N = 2048;
else
    N=12000;
end

NRES = floor(N*4/3);
		
for i=1:N
	input(i) = 0;
end

PI = atan(1) * 4;
rand('seed',0);

if (checkdisto==0)
    for i=1:N
	    	input(i) = (rand(1) - 0.5);
    end
else
    for i=1:N
          	input(i) = sin(2*pi*fc*T*(i-1))/2;
    end
end

res = upfirdn(input,deci1_4_3,4,3);
res1 = res * 2^(shift_4_3);
res1 = res1 * mult_4_3;
figure
epsilon=1e-10;
fftsiz=2048;
i=1:fftsiz;
freq=(i-1)*fs*(4/3)/fftsiz;
spect=(4/fftsiz)*fft(res(NRES-fftsiz+1:NRES).*chebwin(fftsiz,160)',fftsiz);
spectdb=20*log10(abs(spect)+epsilon);
plot(freq,spectdb);
grid on;
zoom on;
axis([0 fs*4/(3*2) -180 0]);
title('Spectrum of output signal');

if (checkdisto>0)
    fil1=fopen('simout.txt','wt');
    fprintf(fil1,'%f\n',res1);
    fclose('all');
end
%Write the corresponding test file
fid = fopen('testval_hamaca12_16_fast.c','w');


fprintf(fid, '#ifndef __flexcc2__\n');
%-------------------------------------
fprintf(fid, '#define N_IN  %d \n ',N);
fprintf(fid, '#define N_OUT  %d \n ',NRES);
fprintf(fid,'Float in12_16[%d] = {\n',N);
for k = 1:N-1
     fprintf(fid,'\tFORMAT_FLOAT(%.15f,MAXVAL),  \t\t// %d\n',input(k),k-1);
end
k = N;
fprintf(fid,'\tFORMAT_FLOAT(%.15f,MAXVAL) }; \t\t// %d\n',input(k),k-1);
		
fprintf(fid,'const YMEM Float out12_16[%d] = {\n',NRES);
for k = 1:NRES-1
     fprintf(fid,'\tFORMAT_FLOAT(%.15f,MAXVAL),  \t\t// %d\n',res1(k),k-1);
end
k = NRES;
fprintf(fid,'\tFORMAT_FLOAT(%.15f,MAXVAL) }; \t\t// %d\n',res1(k),k-1);
%------------------------------------
N=floor(N/16);
NRES=floor(NRES/16);
fprintf(fid, '#else\n');
%-------------------------------------
fprintf(fid, '#define N_IN  %d \n ',N);
fprintf(fid, '#define N_OUT  %d \n ',NRES);
fprintf(fid,'Float in12_16[%d] = {\n',N);
for k = 1:N-1
     fprintf(fid,'\tFORMAT_FLOAT(%.15f,MAXVAL),  \t\t// %d\n',input(k),k-1);
end
k = N;
fprintf(fid,'\tFORMAT_FLOAT(%.15f,MAXVAL) }; \t\t// %d\n',input(k),k-1);
		
fprintf(fid,'const YMEM Float out12_16[%d] = {\n',NRES);
for k = 1:NRES-1
     fprintf(fid,'\tFORMAT_FLOAT(%.15f,MAXVAL),  \t\t// %d\n',res1(k),k-1);
end
k = NRES;
fprintf(fid,'\tFORMAT_FLOAT(%.15f,MAXVAL) }; \t\t// %d\n',res1(k),k-1);
%------------------------------------
fprintf(fid, '#endif\n');


fclose(fid);		