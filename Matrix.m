% clear;
% clc;
% start = clock;
% x = rand(2^13,2^13);
% y = rand(2^13, 2^13);
% z=x*y;
% finish = clock;
% times= etime(finish , start)
x1=[2^4,2^5,2^6,2^7,2^8,2^9,2^10,2^11,2^12,2^13];
times=[0,0,0,0,0,0,0,0,0,0];
for(i=4:13)
    start = clock;
    x = rand(2^i,2^i);
    y = rand(2^i, 2^i);
    z=x*y;
    finish = clock;
    times(i-3)= etime(finish , start);
end;
plot(x1,times);