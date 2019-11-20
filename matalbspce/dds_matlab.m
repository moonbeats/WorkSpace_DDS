function [y,t] = dds_matlab(fout,Fs,Bits,endtime)
%fout:Output frequency
%Fs:Sample frequency
%Bits:Number of bits of the LUT
%endtime:Expected simulation endtime
%y:Output sine wave
%t:Output time


delta_F=Fs/2^Bits;
t=2*pi*(0:2^Bits-1)/2^Bits;
% LUT=sin(t);  
LUT=sawtooth(t);
% LUT=square(t);
subplot(211);
plot(t,LUT)
figure(1)
grid on

t=0:1/Fs:endtime;
N=length(t);
n=1;
y=zeros(1,N);
IND=zeros(1,N);
k=floor(fout/Fs*2^Bits);%定点化
index=0;

while n<=N
    IND(n)=index;
    index=index+k;
    index=mod(index,2^Bits);%相位累加
    n=n+1;
end

m=IND;
IND=IND+1;
y=LUT(IND);%寻址
subplot(212)
plot(t,y)
figure(1)
axis([0 endtime -1.2 1.2]);
grid on
end

