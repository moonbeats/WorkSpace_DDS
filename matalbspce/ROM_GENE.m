n = 0:4095 ;
yn = sin(2*pi/4096*n) ;
yn = round(yn*32768); 
yn = dec2hex(yn,3);
% plot(n,yn);

fid = fopen('rom.txt','wt');

for i = 1 : 4096
    if mod(i-1,16) == 0 
        fprintf(fid,'\n');
    end
    fprintf(fid,'%s\t,',strcat(yn(i)));
end